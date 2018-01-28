public class SemBoundedBufferMain {
    static public void main(String[] args) {
	SemBoundedBuffer queue = new SemBoundedBuffer(3);
	Thread producer = new SemBoundedBufferProducer(queue);
	Thread consumer = new SemBoundedBufferConsumer(queue);
	producer.start();
	consumer.start();
    }
}

