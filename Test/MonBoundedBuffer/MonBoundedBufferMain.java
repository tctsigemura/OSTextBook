public class MonBoundedBufferMain {
    static public void main(String[] args) {
	MonBoundedBuffer queue = new MonBoundedBuffer(3);
	Thread producer = new MonBoundedBufferProducer(queue);
	Thread consumer = new MonBoundedBufferConsumer(queue);
	producer.start();
	consumer.start();
    }
}

