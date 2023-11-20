import java.util.*;
import java.util.concurrent.Semaphore;

public class readerwriter {
    static Semaphore readlock=new Semaphore(1);
    static Semaphore writelock=new Semaphore(1);
    static int readcount=0;

    static class Reader implements Runnable{
        @Override
        public void run(){
            try{
                readlock.acquire();
                readcount++;
                if(readcount==1){
                    writelock.acquire();
                }
                readlock.release();
                System.out.println(Thread.currentThread().getName()+" is reading ");
                Thread.sleep(1000);
                System.out.println(Thread.currentThread().getName()+" is finished ");
                readlock.acquire();
                readcount--;
                if(readcount==0){
                    writelock.release();
                }
                readlock.release();
            }
            catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
            

        }
    }

    static class Writer implements Runnable{
        @Override
        public void run(){
            try{
                writelock.acquire();
                System.out.println(Thread.currentThread().getName()+" is writing ");
                Thread.sleep(1000);
                System.out.println(Thread.currentThread().getName()+" is writing ");
                writelock.release();
            }
            catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter no. of process ");
        int n;
        n=sc.nextInt();
        Thread[] process=new Thread[n];
        System.out.println("enter 1 for writer and 0 for reader");
        for(int i=0;i<n;i++){
            process[i]=(sc.nextInt()==1)?new Thread(new Writer()):new Thread(new Reader());
            process[i].setName("thread "+(i+1));
        }
        for(Thread proces:process){
            proces.start();
        }
        sc.close();
    }
}