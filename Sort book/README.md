Sort Book
===========

Objectives
explore how different sorting algorithms are better/worse with particular types of data research and/or design an appropriate sorting algorithm for the given data and implementation timeframe implement a sorting algorithm consider actual performance rather than asymptotic(big-Oh) performance

Important
Your program should compile to produce a program named sortbook 
command:
make
Your program must run using the command:
sortbook <inputfile> <outputfile> <timesfile> <ntests>
So sortbook A.txt B.txt times.txt 100 should cause your program to read the text A.txt, write the sorted words to B.txt and output the sorted times for each of 100 tests in times.txt.

The data
The data you will be sorting is english text, stripped to remove punctuation. An example text 308-0.txt is provided, but is not the same as the text that will be used for testing. The text is composed entirely of words, separated by whitespace. A word is defined as a contiguous sequence of non-whitespace characters (so it's is one word, but J W Arrowsmith is three words).
Sorting
The primary sort order should be the number of characters in the word. The secondary sort order should be lexicographical order as you get using strcmp.

So sorting the words: This is a list of unsorted words
should give: a is of This list words unsorted

Sorting Algorithm
You can use any sorting algorithm, but you must implement it yourself, no code from elsewhere. No calls to standard library sorting algorithms for this part. No need for multithreading; if for some reason you want to write it multithreaded, then the time must be the sum of times for all threads.1 Local machine only|no distributing work to other machines. Focus on designing/researching an ecient algorithm and coding it clearly and well.

Not timed
You are allowed to make an initial pass through the input le, and gather a constant amount of data (e.g. the number of characters in the largest word), before reading in the words and storing it in an array. You may strip extraneous whitespace if you wish, but you may not partially sort the data while reading it in. Once the data is read in, that array should remain unchanged for the rest of the program. You should also dene (but not copy data into) the temporary data structure(s) which you will use for sorting. This may be any data structure(s) you want to use.
The Timed Bit
Each test should consist of copying the data from the array into your temporary data structure and sorting the data using your sorting code.
Not timed
Finally, the sorted words from the nal test run should be extracted from their temporary data structure and output with a space after each word except for every 10th word which is followed by a newline. A sample output le has been provided. Your sort routine is considered correct if your output le matches mine (if you run di on your answer and my answer you should get no dierences).
