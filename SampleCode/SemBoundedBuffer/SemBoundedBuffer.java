// Java のセマフォクラス
// P操作がacquireUninterruptibly(), V操作がrelease() になる
import java.util.concurrent.Semaphore;          // セマフォ型を利用可能にする
public class SemBoundedBuffer {
    private Semaphore guard = new Semaphore(1); // ガード用のセマフォ
    private Semaphore next = new Semaphore(0);  // signal時ブロック用セマフォ
    private int nextCont = 0;                   // signal時ブロック・スレッド数
    private class Condition {                   // 内部クラス'条件変数型'を定義
	Semaphore sem = new Semaphore(0);       // 条件変数待ち用セマフォ sem
	int count = 0;                          // 条件変数を待つスレッドの数
	void await() {                          // 条件変数を待つメソッド
	    count++;                            // この条件変数待ちスレッドの数
	    if (nextCont>0) {                   // 起床後にawait()した場合なら
		next.release();                 //   signal()したスレッドを起床
	    } else {                            // 起こすスレッドがないなら
		guard.release();                //   ガードを外してからブロック
	    }
	    sem.acquireUninterruptibly();       // 条件変数のセマフォで待つ
	    count--;                            // 待ちが完了
	}
	void signal() {                         // 条件変数で待つスレッドを起床
	    if (count>0) {                      // 待っているスレッドがあれば
		nextCont++;                     //   signal途中のスレッド数
		sem.release();                  //   待ちスレッドを起こす
		next.acquireUninterruptibly();  //   起きたスレッドを先に実行
		nextCont--;                     //   signal完了
	    }
	}
    }
    private void exitProc() {                   // 手続きの出口処理
	if (nextCont>0) {                       // signalされた後なら
	    next.release();                     //   signalしたスレッドを起床
	} else {                                // そうでなければ
	    guard.release();                    //   ガードを外す
	}
    }
    // 資源（リングバッファ）
    private int N;
    private int[] buf;
    private int first, last, cnt;
    // 条件変数
    private Condition empty = new Condition();
    private Condition full  = new Condition();
    // 初期化
    public SemBoundedBuffer(int n) {
	N = n;
	buf = new int[N];
	first = last = cnt = 0;
    }
    // 手続き
    public void append(int x) {                 // (1)
	guard.acquireUninterruptibly();         // (1) ガードを取得
	if (cnt==N) full.await();               // (1)
	buf[last] = x;                          // (3)
	last = (last + 1) % N;                  // (3)
	cnt++;                                  // (3)
	empty.signal();                         // (3)
	exitProc();                             // (3) 手続きの出口処理
    }
    public int remove() {                       // (2)
	guard.acquireUninterruptibly();         // (2) ガードを取得
	if (cnt==0) empty.await();              // (2)
	int x = buf[first];                     // (2)
	first = (first + 1) % N;                // (2)
	cnt--;                                  // (2)
	full.signal();                          // (2)
	exitProc();                             // (4) 手続きの出口処理
	return x;                               // (4)
    }
}
