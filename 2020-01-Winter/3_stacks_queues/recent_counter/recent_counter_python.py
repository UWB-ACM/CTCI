class RecentCounter:
    #This queue is a Python list
    #In this problem, we treat it like a FIFO Queue
    def __init__(self):
        self.queue = []

    #The ping function. The self is implicit, so calling
    #this function requires passing in the time t in milliseconds
    #self is like "this" in Java
    def ping(self, t):
        #First, we eneueue the new time into the end of the queue
        self.queue.append(t)

        #Now we loop through the queue and dequeue from the front
        #any pings that happened more that 3000 seconds ago
        while self.queue and self.queue[0] < t - 3000:
            self.queue.pop(0)

        #Since the problem statement wants the number of pings in
        #the previous 3000 milliseconds, we can now simply return
        #the number of elements in the queue
        return len(self.queue)

#main function
def main():
    print("Test Ping Function")

    #create a new RecentCounter object
    r = RecentCounter()

    #from i = 0 to i = 10000 in increments of 1000, call ping with i as the time in ms
    #for i in range (0, 30000, 1500):
        #print the returned value
        #print('Number of Pings in the last 3000ms: ', r.ping(i))
    print('Number of Pings in the last 3000ms: ', r.ping(0))
    print('Number of Pings in the last 3000ms: ', r.ping(1))
    print('Number of Pings in the last 3000ms: ', r.ping(2))
    print('Number of Pings in the last 3000ms: ', r.ping(3))
    print('Number of Pings in the last 3000ms: ', r.ping(100))
    print('Number of Pings in the last 3000ms: ', r.ping(1000))
    print('Number of Pings in the last 3000ms: ', r.ping(2000))
    print('Number of Pings in the last 3000ms: ', r.ping(3003))
    print('Number of Pings in the last 3000ms: ', r.ping(3005))
    print('Number of Pings in the last 3000ms: ', r.ping(4000))

#required code for python to automatically execute the main
#mains are not required, but included here for simplicity
if __name__ == '__main__':
    main()
