The game Yahtzee
==============

###Step One
Step One is to develop a program to take as input the five dice rolls and determine the 13
different possible scores.


Write a program that inputs five values in the range 1 to 6 and stores the five values in an integer array. You can assume that the five values are within the range 1 to 6. (Ensure when testing your program that you input valid values.) Then determine the score possible for each of the following 13 alternatives. Store the scores in a suitable array.


1.  Aces: the number of ones in the 5 dice;
2.  Twos: the number of twos times 2, or the sum of the twos;
3.  Threes: the sum of the threes;
4.  Fours: the sum of the fours;
5.  Fives: the sum of the fives;
6.  Sixes: the sum of the sixes;
7.  3 of a Kind: the sum of the five dice if at least three of the dice are the same, otherwise 0;
8.  4 of a kind: the sum of the five dice if at least four of the dice are the same, otherwise 0;
9.  Full House: 25 points if three dice are one number and two are another, otherwise 0;
10.  Small Straight: 30 points if four of the dice are consecutive numbers, otherwise 0;
11.  Large Straight: 40 points if the five dice are consecutive numbers, otherwise 0;
12.  Yahtzee: 50 points if all five dice are the same, otherwise 0;
13.  Chance: the sum of the dice


###Step Two
Let's now move to the generation of the dice rolls. To simulate the random process of rolling a
die or tossing a coin, most computer languages provide a library function for generating **pseudorandom numbers**. Such a function generates a sequence of numbers in some range with properties such as equal probabilities of all possible numbers, and no correlation between one number generated and the next. Each call returns the next number in the sequence.


###Step Three
Part of the game is that the player has the option of re-rolling some of the dice. By requesting
five characters, typed immediately under the five numbers, re-roll those dice under which the
letter 'r' or 'R' has been typed. For example, if the dice rolls were 1,2,1,2,3, the output would be
something like


      The dice were 12123
      What re-rolls?
      
      
with the cursor positioned for the first input to be under the 1 to which a suitable input would be


      The dice were 12123
      What re-rolls? hhhhr
      
      
to indicate holding the first four and re-rolling the last (in the hope of another 1 or 2, making a full house.) The letter used for a hold could be anything (except a space, which would be
ignored by cin).


###Step 4
The game of Yahtzee consists of thirteen rounds of rolling the five dice, selecting a set of rerolls, and then deciding which of the thirteen categories to use for that roll. Each category can be used once only. The aim of the game is to get as high a total as possible. There is a bonus of 35 points if the total of the first six categories is 63 or greater.


The code written so far is now to be incorporated into a loop which repeats 13 times. The
thirteen category scores should each be initially set to zero and associated with a flag initially set to true indicating it is available for allocation. After each set of dice rolls has been determined, a list of the still-available categories should be displayed, with the associated number (1-13). The user should be requested to input the category to be used for this set of dice rolls. The program should ensure that an available category is chosen. This means if a user enters an invalid number you re-prompt till a valid number is entered. The score for that category is then be set to the calculated value. (If you are learning the game, you can print out the value for each category before the choice is made.) Report the score recorded and the current total for the first six categories.


After the 13 rounds, check for the bonus and report the final score.


###Step 5
The final part of the program is to break the task into a number of functions. For each
function you define you are to create a suitable prototype.

You should write functions for:


      1.  Rolling and re-rolling dice – the function should roll the dice as per specification, then
          prompt the user for which dice to reroll. Once complete the function should return the
          caller the 5 dice.
      2.  A collection of functions, which perform the checks for each category. The functions
          would typically take the five dice as an argument and return to the invoker the score for
          the category.
      3.  You may implement additional functions to help with output where appropriate.
      4.  The main function should be modified to follow the logic of the game but this time use
          the functions above. As a consequence of this main should become smaller.
      
      
**INPUT/OUTPUT SAMPLE**


Below is a sample run of the program – it does not have all 13 rounds but it gives you an idea as
to what we expect. Please be sure to obey the input below, particularly in reference to bad entry
of categories. If you do not obey this, you will be penalised. The output need not be identical but
it should be close.


**Bold** denotes user input.


        Yahtzee Program
        Enter Seed: **123456**
        Round 1
        The dice were 12335
        What re-rolls? hhhhr
        The dice were 12333
        1. Aces
        2. Twos
        3. Threes
        4. Fours
        5. Fives
        6. Sixes
        7. 3 of a Kind
        8. 4 of a kind
        9. Full House
        10. Small Straight
        11. Large Straight
        12. Yahtzee
        13. Chance
        Which category? 14
        Bad Catergory Please retry? -1
        Bad Catergory Please retry? 7
        Score recorded for round: 12
        Score for first six Categories: 0
        
        Round 2
        The dice were 14444
        What re-rolls? rhhhh
        The dice were 44444
        1. Aces
        2. Twos
        3. Threes
        4. Fours
        5. Fives
        6. Sixes
        8. 4 of a Kind
        9. Full House
        10. Small Straight
        11. Large Straight
        12. Yahtzee
        13. Chance
        Which category? 7
        Bad Category Please retry? 4
        Score recorded for round: 20
        Score for first six Categories: 0
            . . .


Obviously after 13 rounds you are to output the total score along with the bonus. In addition to
this during the development of your program you may want to output the score for each category
in the menu's.
