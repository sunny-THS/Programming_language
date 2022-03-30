/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

/**
 *
 * @author Admin
 */
public class Store {
    int maxN = 50;
    long [] a;
    int n;
    public Store() { n=0; a=new long[maxN]; }
    private boolean empty() { return n==0; }
    private boolean full() { return n==maxN; }
    public /* synchronized */ boolean put(long x) {
        if (full()) return false;
        a[n++] = x;
        try { Thread.sleep(500); }
        catch(Exception e) {}
        return true;
    }   
    public /* synchronized */ long get() {
        long rs = 0;
        if (!empty()) {
            rs = a[0];
            for (int i=0; i<n-1; i++) a[i] = a[i+1];
            n--;
        }
        try {
            Thread.sleep(500);
        } catch (Exception e) {
        }
        return rs;
    }
}