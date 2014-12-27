Spell Check
===========

Your task is to write a Multi-Threaded (ie. concurrent) Client Server C/C++ application for performing spell checking of text files using the dictionary in /usr/dict/words.
After the file is processed by the server, the client should display all miss-spelt words and any near words as suggested replacements. (An example output is shown below.)
Line No.           Mis-spelt word                     Suggestion
           7                       enogh                           enough
         12                      nothng                          nothing
       230                happenned                       happened
       234                          glob                              globe
       563                       poeple                            people
     1034                     lathgter                          laughter
     1455                      kowing                          knowing
     1788                       wuold                              would
     1951                       quate                                quite
     2145                  javascript                  no suggestion
     2344                       winkle                             wrinkle
Total processing time = 3.723 sec 

File processing should be done by the server on a line by line basis. Each time a line of text is read it should be preprocessed by converting all uppercase letters to lowercase and removing leading or tailing punctuation characters. A word is to be defined as a sequence alphabetic characters as well as the characters ' ' ' (apostrophe) and '-'(hyphen). Thus, words like "co-operate" and "it's" will be processed as whole words. (Note: If you are not sure how to extract words from a line of text you can use the example code in sscanf_eg.cpp.) The total processing time is the time from the commencement of the program (or client) until its termination. To search for words in the dictionary just use a linear search.
To determine if the two words are the same (or different) use the int WordCmp(char*,char*) function below. It returns 0 if the words are the same or a number >0 if the words are different. (Note: the greater the return value the greater the difference between the words.) To obtain a suggestion word for a miss-spelt word use the word with the minimum difference. (Note: if there is more than one word with the minimum difference for a miss-spelt word then use the one found first as the suggestion word.)
int WordCmp(char*Word1,char*Word2){
if(strcmp(Word1,Word2)==0)return 0;
if(Word1[0]!=Word2[0]))return 100;
float AveWordLen = (strlen(Word1) + strlen(Word2)) / 2.0;
return int(NumUniqueChars(Word1,Word2) / AveWordLen * 100);
}
where: the NumUniqueChars() is the number of chars in Word1 that are not in Word2 plus the number of chars in Word2 that are not in Word1. You may improve this compare function if you wish.