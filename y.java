import java.util.*;
import java.util.concurrent.Semaphore;

class y {
    static Semaphore readlock = new Semaphore(1);
    static Semaphore writelock = new Semaphore(1);
    static int readCount = 0;

    static class Reader implements Runnable {
        @Override
        public void run() {
            try {
                readlock.acquire();
                readCount++;
                if (readCount == 1) {
                    writelock.acquire();
                }
                readlock.release();
                System.out.println("Reader " + Thread.currentThread().getName() + " is reading");
                Thread.sleep(500);
                System.out.println("Reader " + Thread.currentThread().getName() + " finished reading");
                readlock.acquire();
                readCount--;
                if (readCount == 0) {
                    writelock.release();
                }
                readlock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    static class Writer implements Runnable {
        @Override
        public void run() {
            try {
                writelock.acquire();
                System.out.println(Thread.currentThread().getName() + " is writing");
                Thread.sleep(500);
                System.out.println(Thread.currentThread().getName() + " finished writing");
                writelock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of processes");
        int n = sc.nextInt();
        Thread[] process = new Thread[n];
        System.out.println("Enter 1 for reading and 0 for writing");
        for (int i = 0; i < n; i++) {
            process[i] = (sc.nextInt() == 1) ? new Thread(new Reader()) : new Thread(new Writer());
            process[i].setName("thread" + (i + 1));
        }
        for (Thread it : process) {
            it.start();
        }
        sc.close();
    }
}
