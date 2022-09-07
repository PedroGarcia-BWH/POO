import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class V extends Thread{
    Condition[] c;
    int i;
    ReentrantLock l;
    public V(int i){
        this.i = i;
        l = new ReentrantLock();
        c = new Condition[this.i+1];
        for(int k=0; k<c.length; k++) c[k] = l.newCondition();
    }

    public void run(){
        l.lock();
        try{
            c[this.i].await();
            System.out.println("Soy la hebra " + this.i);
        }catch (InterruptedException e){} finally {l.unlock();}
    }

    public void aux() throws InterruptedException{
        l.lock();
        try{
            c[this.i].signal();
        }finally{l.unlock();}
    }

    public static void main(String[] args) throws Exception{
        V[] t = new V[4];
        int s  = 2;
        for(int i=0; i<t.length;i++) t[i] = new V(i);
        for(int i=0; i<t.length;i++) t[i].start();
        Thread.currentThread().sleep(1000);
        t[s].aux();
        for(int i=0; i<t.length;i++) t[i].join();
        System.out.println("Fin programa ");
    }
}