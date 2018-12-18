# simpleQuestions
Some common questions' solutions

**savefile.java:**
 two methods to write things into the file without clearing the file
 
 **cycleDetection.cpp:**
 Floyd's cycle-finding algorithm

**getCountries.js:**
Using HTTP.get to filter the countries which satifies containing given string and that the population is bigger than a specific number

**printNumThroughCommand.cpp:**
  Create simple C/C++ application that takes two numbers 'n' and 't' as command-line arguments.

  Spawns 2 separate threads:

  - Thread 1:
      - Generate a random number from 0 to n, once every 100 milliseconds (n is specified as a command-line argument).
      - Store that number in a data structure and keep track of the number of occurrences for each number.

  - Thread 2:
      - Every 5 seconds, print out the top t numbers with the highest occurrences (t is specified as a command-line argument).

  Once every number from 0 to n is hit at least once, shutdown both threads and exit cleanly.
