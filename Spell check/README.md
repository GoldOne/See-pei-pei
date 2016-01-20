Spell Check
===========

Your task is to write a Multi-Threaded (ie. concurrent) Client Server C/C++ application for performing spell checking of text files using the dictionary in /usr/dict/words.

After the file is processed by the server, the client should display all miss-spelt words and any near words as suggested replacements. (An example output is shown below.)
```cpp
Line No.           Mis-spelt word                     Suggestion
      7                     enogh                         enough
     12                    nothng                        nothing
    230                 happenned                       happened
    234                      glob                          globe
    563                    poeple                         people
   1034                  lathgter                       laughter
   1455                    kowing                        knowing
   1788                     wuold                          would
   1951                     quate                          quite
   2145                javascript                  no suggestion
   2344                    winkle                        wrinkle
Total processing time = 3.723 sec 
```
File processing should be done by the server on a line by line basis. Each time a line of text is read it should be preprocessed by converting all uppercase letters to lowercase and removing leading or tailing punctuation characters. A word is to be defined as a sequence alphabetic characters as well as the characters ' ' ' (apostrophe) and '-'(hyphen). Thus, words like "co-operate" and "it's" will be processed as whole words. (Note: If you are not sure how to extract words from a line of text you can use the example code in sscanf_eg.cpp.) The total processing time is the time from the commencement of the program (or client) until its termination. To search for words in the dictionary just use a linear search.

To determine if the two words are the same (or different) use the int WordCmp(char*,char*) function below. It returns 0 if the words are the same or a number >0 if the words are different. (Note: the greater the return value the greater the difference between the words.) To obtain a suggestion word for a miss-spelt word use the word with the minimum difference. (Note: if there is more than one word with the minimum difference for a miss-spelt word then use the one found first as the suggestion word.)
```cpp
int WordCmp(char*Word1,char*Word2){
    if(strcmp(Word1,Word2)==0)
        return 0;
    if(Word1[0]!=Word2[0]))
        return 100;
    float AveWordLen = (strlen(Word1) + strlen(Word2)) / 2.0;
    return int(NumUniqueChars(Word1,Word2) / AveWordLen * 100);
}
```
where: the `NumUniqueChars()` is the number of chars in Word1 that are not in Word2 plus the number of chars in Word2 that are not in Word1. You may improve this compare function if you wish.

**You should complete this program by performing the following steps.**

Step 1: Implement a single-process program without sockets or threads.

Step 2: Convert the program in step 1 into a client-server application using TCP sockets. 

Step 3: Convert the server program in step 2 into a multithreaded program capable of processing lines of
input file data in parallel from an input queue and record all miss-spelt words, their suggestion
word and line number in a global linked list. You may use buffer.cc to help with this step. The
mutexes and condition vars should provide mutual exclusion to the shared global data to prevent
the threads from updating it simultaneously. When processing is complete the contents of the
linked list are sent to the client for displaying on the user's screen.

###Algorithms:

####SINGLE THREADED
```cpp
open input file
while !eof
        read line from file
        preprocess line
        for each word in line
                  open dictionary
                  for each word in dictionary
                           compare words
                           if same found=true; 
                                   break;
                           if word difference is minimum
                                   keep dictionary word as a suggestion word
                  close dictionary
                  if !found
                          print line no. word and suggestion on screen
        end for
close input file
print processing time
```
####CLIENT:

1. get filename and number of slaves etc. from command line
2. gethostbyname (to obtain IP_Address of the Server)
3. contact Server (using connect + IP_Address from above)
4. send filename and number of threads to server & wait for miss-spelt words to return.
5. take miss-spelt words from Server and print them
6. close socket.

####SERVER:

1. setup socket
2. accept client connection
4. read filename and number of threaded slaves.
5. open file
6. create threaded slaves
7. keep filling input buffer with preprocessed lines of text. (see Producer below)
8. wait for threads to complete
9. send miss-spelt words to client
10. close socket & file, goto 2

####PRODUCER:
```cpp
         while(1)
                  read line from file
                  if no data left set data_finished & break;
                  if queue full pthread_cond_wait
                  else
                          put item in input queue
                          . . .
```
####CONSUMER THREAD:
```cpp
        while(1)
                  if data_finished break;
                  if input queue empty pthread_cond_wait
                  else
                           take item from queue
                           process item
                           . . .
```
####NOTES:

(i) For the server to work correctly you will have to implement a number of mutexes and condition
variables appropriately to make the global data accesses mutually exclusive. Remember with threads
preemption can occur at any point in the program, even halfway through calculations.

(ii) Using the following attribute ensures that threads will be bound to kernel LWPs in a 1:1 manner - ie. the OS uses time slicing (this ensures that each thread will get CPU time allocated, & overcomes potential Solaris thread scheduling problems):
```cpp
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
```

(iii) Compile using the -mt & -lpthread options \[ref. cc man page entries\]
(By default, -mt appends -lthread ie. Solaris rather than POSIX!)