public class SemBoundedBufferConsumer extends Thread {
    SemBoundedBuffer queue;
    SemBoundedBufferConsumer(SemBoundedBuffer q) {
	queue = q;
    }
    public void run() {
	for (int i=0; i<10; i++) {
	    try{sleep(2000);}catch(InterruptedException e){} // 2秒ごとに
	    System.out.println("consumer start");
	    int x = queue.remove();
	    System.out.println("consumer : remove "+x);
	}
    }
}

