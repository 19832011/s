// import java.util.Scanner;
import java.util.concurrent.Semaphore;

import java.util.*;
class ReaderWritersProblem {
    static Semaphore readLock = new Semaphore(1);
    static Semaphore writeLock = new Semaphore(1);
    static int readCount = 0;

    static class Reader implements Runnable {
        @Override
        public void run() {
            try {
                readLock.acquire();
                readCount++;
                if (readCount == 1) {
                    writeLock.acquire();
                }
                readLock.release();

                System.out.println(Thread.currentThread().getName() + " is READING");
                Thread.sleep(2500);
                System.out.println(Thread.currentThread().getName() + " has FINISHED READING");

                readLock.acquire();
                readCount--;
                if (readCount == 0) {
                    writeLock.release();
                }
                readLock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            } 
        }
    }

    static class Writer implements Runnable {
        @Override
        public void run() {
            try {
                writeLock.acquire();
                System.out.println(Thread.currentThread().getName() + " is WRITING");
                Thread.sleep(2500);
                System.out.println(Thread.currentThread().getName() + " has FINISHED WRITING");
                writeLock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = scanner.nextInt();
        Thread[] processes = new Thread[n];

        System.out.println("Enter the sequence of processes (1 for reading, 0 for writing): ");
        for (int i = 0; i < n; i++) {
            processes[i] = (scanner.nextInt() == 1) ? new Thread(new Reader()) : new Thread(new Writer());
            processes[i].setName("Thread " + (i + 1));
        }

        for (Thread process : processes) {
            process.start();
        }

        scanner.close();
    }
}