public class BoundedBuffer {
    // 資源（リングバッファ）
    private int N;
    private int[] buf;
    private int first = 0;
    private int last = 0;
    private int cnt = 0;
    // 条件変数
    private Object empty = new Object();
    private Object full  = new Object();
    // 初期化（コンストラクタ）
    BoundedBuffer(int n) {
	N = n;
	buf = new int[N];
    }
    // 手続き（操作）
    private int next(int n) {
	return (n + 1) % N;
    }
    public synchronized void append(int x) {
	while (cnt==N) {
	    try{full.wait();}
	    catch(InterruptedException e) {}
	}
	buf[last] = x;
	last = next(last);
	cnt++;
	empty.notify();
    }
    public synchronized int remove() {
	while (cnt==0) {
	    try{empty.wait();}
	    catch(InterruptedException e) {}
	}
	int x = buf[first];
	first = next(first);
	cnt--;
	full.notify();
	return x;
    }
}
	