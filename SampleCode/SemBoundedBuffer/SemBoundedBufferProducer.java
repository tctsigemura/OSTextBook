public class SemBoundedBufferProducer extends Thread {
    SemBoundedBuffer queue;
    SemBoundedBufferProducer(SemBoundedBuffer q) {
	queue = q;
    }
    public void run() {
	for (int i=0; i<10; i++) {
	    int s=(int)(Math.random()*2000); // 0〜2秒ごとに
	    try{sleep(s);}catch(InterruptedException e){}
	    System.out.println("producer start : slept("+s+"ms)");
	    queue.append(i);
	    System.out.println("producer : append "+i);
	}
    }
}

