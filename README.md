# ECE4574

My code uses four files named
main.cpp 
path.cpp
module.cpp
path.h

It uses QT5 and accepts as inputs four integers that coorelate to the starting X,Y and ending X,Y positions of the targets. It then utilizes an A* pathfinding module to find the best path and output it on the console. 

An example terminal code to run for start position (0,10) and finishing position (55,40) would be

**./program 0 10 55 40**


The program does error checking to make sure the integers input are actually numbers, non-negative, not special characters, and that it does not exceed the map size of 60.

**Unit Test Framework:**

I was unfortunately not able to get automated test frameworks setup. I spent hours trying to learn and use QtTest with their own framework before moving on to Catch (https://github.com/philsquared/Catch). Both did not work properly and so my results were not able to be automated and tested.

I have discussed it with the professor and noted that ECE 3574 did not provide me with instruction on what or how automated test frameworks worked when I took it and so this material is new to me. I intend to learn how to perform this testing with the TA at the next moment available. 

**Manual Test:**

As I was not able to utilize an automated test framework, I performed manual testing using command line arguments and filmed it in the video submission. 

To show this, I ran the program multiple times with different coordinate inputs. The tests coordinates I ran were

1. 0 10 – 20
2. 0 10 -9 8
3. 0 10 / 8
4. 0 10 63 40
5. 0 10 55 40
6. 10 10 52 36
7. 0 0 59 59

Tests 1 through 4 were meant to show error conditions and my program handling them correctly. Test (1) had a dash as the third argument and thus was invalid. Test (2) had a negative coordinate which is not possible. Test (3) had a / backslash as one argument which was also invalid. And Test (4) had a coordinate location greater than my defined map size of 60.

The final tests (5) , (6) , and (7) were to show different start and end coordinates and the program output when run. 