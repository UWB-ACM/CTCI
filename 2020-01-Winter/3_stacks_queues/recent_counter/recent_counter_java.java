package com.company;

import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] args) {
        System.out.println("Test Ping Function");

        //create a new RecentCounter object
        RecentCounter r = new RecentCounter();

        //from i = 0 to i = 10000 in increments of 1000, call ping with i as the time in ms
        for(int i = 0; i <= 10000; i += 1000){
            //print the returned value
            System.out.println("Number of Pings in the last 3000ms: " + r.ping(i));
        }
    }
}

class RecentCounter{
    //This is one way of making a FIFO Queue in Java
    Queue<Integer> queue = new LinkedList<>();

    //The ping function.
    //Calling this function requires passing in the time t in milliseconds
    public int ping(int t){
        //First, we eneueue the new time into the end of the queue
        queue.add(t);

        //Now we loop through the queue and dequeue from the front
        //any pings that happened more that 3000 seconds ago
        for(int i = 0; i < queue.size(); i++){
            if(queue.peek() < t-3000){
                queue.remove();
            }
        }

        //Since the problem statement wants the number of pings in
        //the previous 3000 milliseconds, we can now simply return
        //the number of elements in the queue
        return queue.size();
    }
}

