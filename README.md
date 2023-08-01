# Introduction
The project is based on different versions of the HashSet data structure, adapted for concurrent use, where different services make use of the same data structure at the same time. The goal with the project is to study the different ways Java accommodates concurrent programming. For that, there exists five different implementations, which one with different pros and cons.

If you don't know what a HashSet is, you can find some relevant information here: [Java HashSet Documentation](https://docs.oracle.com/javase/8/docs/api/java/util/HashSet.html)

# Hset0
Hset0 makes use of the `synchronized` key word, making sure each transition done by the services happen atomically and that there are no anomalies in memory writing and reading between services. This is the most simple implementation, and thus, the one with less beneficial features, since we don't have the power to control lock allocation, that being controlled all by java itself.

# Hset1
Hset1 makes use of the `ReentrantLock` class, giving us the power to control where the functions acquire locks and where the lock is freed. To make sure the lock is always freed, we used the `try {} finally {}`. Apart from controlling the location of locks and unlocks, the ReentrantLock doesn't give any more beneficial changes to the concurrent process. Something important to note is that we can create conditions using the `Condition` class to signal the services of an update to the data structure (as seen in the add function for example).

# Hset2
Hset2 now makes use of the `ReentrantReadWriteLock` class, which is an upgrade from the `ReentrantLock` class, giving us the power to choose which lock we want to acquire, that being the **writeLock** or the **readLock**. That being said, we can now have to services with two different locks, giving more efficiency to the data structure, but this solution still has the same idea behind what Hset1 does.

# Hset3
Similar to Hset2, Hset3 uses `ReentrantReadWriteLock` class as well as `AtomicInteger` class for atomic changes of values. But the difference in Hset3, is that it uses an array of locks, bringing the possibility of different services being active at the same time in the data structure without compromising the atomic changes to values within the data structure. This, of course, brings a way more efficient way of processing things in the data structure, and a way more responsive time to the services, with the cost of more space complexity being involved.

# Hset4
Finally, Hset4 makes use of **Scala** and scala syntax to maintain the atomic behavior of the data structure.  

