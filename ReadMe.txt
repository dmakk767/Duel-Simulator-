Duel Simulator 
Coded by: Dustin McDaniel
Enjoy!

***This is something I dug up on the internet that relates to this program. Not sure if this is exactly what I followed when i wrote this but it is similar for sure.


In the land of Puzzlevania, Aaron, Bob, and Charlie had an argument over which one of them was the greatest puzzler of all time. To end the argument once and for all, 
they agreed on a duel to the death. Aaron is a poor shooter and only hits his target with a probability of 1/3. Bob is a bit better and hits his target with a
 probability of 1/2. Charlie is an expert marksman and never misses. A hit means a kill and the person hit drops out of the duel. To compensate for the inequities
 in their marksmanship skills, it is decided that the contestants would fire in turns starting with Aaron, followed by Bob, and then by Charlie. The cycle would
 repeat until there was one man standing. And that man would be remembered as the greatest puzzler of all time.

a. Write a function to simulate a single shot. It should use the following
declaration:
void shoot(bool& targetAlive, double accuracy);
This would simulate someone shooting at targetAlive with the given accuracy by generating a random number between 0 and 1. If the
random number is less than accuracy , then the target is hit and targetAlive should be set to false . Appendix 4 illustrates how to
generate random numbers.

For example, if Bob is shooting at Charlie, this could be invoked as:
shoot(charlieAlive, 0.5);
Here, charlieAlive is a Boolean variable that indicates if Charlie is alive. Test your function using a driver program before moving on to step b.

b. An obvious strategy is for each man to shoot at the most accurate shooter still alive on the grounds that this shooter is the deadliest and
has the best chance of hitting back. Write a second function named startDuel that uses the shoot function to simulate an entire duel using this strategy. 
It should loop until only one contestant is left, invoking the shoot function with the proper target and probability of hitting the target according to who is shooting. 
The function should return a variable that indicates who won the duel. 

c. In your main function, invoke the startDuel function 1,000 times in a loop, keeping track of how many times each contestant wins. Output
the probability that each contestant will win when everyone uses the strategy of shooting at the most accurate shooter left alive. 

d. A counterintuitive strategy is for Aaron to intentionally miss on his first shot. Thereafter, everyone uses the strategy of shooting at the most accurate shooter left alive. 
This strategy means that Aaron is guaranteed to live past the first round, since Bob and Charlie will fire
at each other. Modify the program to accommodate this new strategy and output the probability of winning for each contestant.