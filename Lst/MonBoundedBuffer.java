public class MonBoundedBuffer {
    // 資源（リングバッファ）
    private int N;
    private int[] buf;
    private int first, last, cnt;
    // 初期化
    public MonBoundedBuffer(int n) {
	N = n;
	buf = new int[N];
	first = last = cnt = 0;
    }
    // 手続き
    private void await() {
	try{wait();}catch(InterruptedException e){}
    }
    public synchronized void append(int x) {    // (1)
	while (cnt==N) await();                 // (1)
	buf[last] = x;                          // (3)
	last = (last + 1) % N;                  // (3)
	cnt++;                                  // (3)
	if (cnt==1) notify();                   // (3)
    }
    public synchronized int remove() {          // (2)
	while (cnt==0) await();                 // (2)
	int x = buf[first];                     // (2)
	first = (first + 1) % N;                // (2)
	cnt--;                                  // (2)
	if (cnt==N-1) notify();                 // (2)
	return x;                               // (2)
    }
}
