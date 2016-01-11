Crypto Systems
===========

Your job is in the National Security Agency secret lab, deep beneath the ground. You are a
trainee and you have been given the task of writing code for crypto systems.


A cipher is a technique used to convert information into a format that cannot be understood by a third party. Two parties can exchange information with the confidence a third party will not understand it providing they know the secret also known as a key.


You job is implement encrypt and decrypt routines of a commonly used substitution cipher.


Using the header file provided (`vignere.h`) your job is to implement the Vignere Cipher’s
encrypt and decrypt functions. Information regarding the cipher can be found
http://en.wikipedia.org/wiki/Vigenère_cipher.


The cipher works by taking `data` which is to be encrypted, and a `key`. The prototypes of the
functions to implement are as follows:
```C++
void vignere_encrypt(char data[], char key[]);
void vignere_decrypt(char data[], char key[]);
```


The actual data to be encrypted/ decrypted is passed to the function as a C string using the `data` argument. You can assume this string is never bigger then 1024 bytes (excluding null byte). The `key` as represented by the key argument is a string with no more then 8 characters (excluding null byte). When encrypting or decrypting `data` ignore any character that is not an alphabetic (this includes newlines, numbers etc). Your code is to preserve the case of data but it should be noted that when doing the crypto (encrypt or decrypt) simply work using upper case characters. 

To encrypt text, simply take the key and overlay it onto the data to be encrypted. Consider the following function call:
```C++
vignere_encrypt(“MAC’S RULE”, “APPLE”)
```

Notice the string is terminated with a null byte, has a space and has some punctuation. If the key is Apple simply overlay the key on top of the data to be encrypted like so.
<table>
  <tr>
    <td>M</td><td>A</td><td>C</td><td>'</td><td>S</td><td> </td><td>R</td><td>U</td><td>L</td><td>E</td><td>\0</td>
  </tr>
  <tr>
    <td>A</td><td>P</td><td>P</td><td> </td><td>L</td><td> </td><td>E</td><td>A</td><td>P</td><td>P</td><td>\0</td>
  </tr>
</table>

Given this apply the following table by,
！[Fig](http://i11.tietuku.com/d3a19060839e3a87.png)

taking the first letter of the string “`MAC’S RULE`”, `M` as the column and the key character `A` as
the row. The character at the intersection is the encrypted character.


The above string is converted to the following


`MPR’D VUAT`


To decrypt the string, take the character from the encrypted string along with the corresponding
character from the key and find the corresponding column it belongs to in the table

.
Your job is to implement this algorithm in the above named functions. Place your code for this
in the file `vignere.cpp`.


**Part 1**
Given your implementation of the algorithm in vignere.cpp with appropriate interfaces in
vignere.h, write a simple driver program to do the following.
prompt the user for source filename
prompt the user for target filename
prompt the user to enter a key
ask the user if they want to encrypt or decrypt the file
IF files can not be opened
Terminate
ELSE
IF the user wants to decrypt
FOR each line in the source file
Encrypt it using the key and write to result the
target
file
ELSE
FOR each line in the source file
Decrypt it using the key and write the result to the
target
file
ENDIF
ENDIF
Output from the program should look like:
Enter source file: input.txt
Enter target file: output.txt
What is the key: cat
Encrypt or Decrypt (e/d)? e
Encrypting input.txt – writing output to output.txt
Done….
It should be noted that BOLD represents user input.
When writing the driver, you can assume that lines are no longer then 1024 characters and are
always terminated by a new line character. The newline my be preserved in any encrypted/
decrypted file. Non alphabetics are not touched as part of this process.
You need not perform any error checking in the driver apart from file checks. You can assume
the e/d option for Encrypt/ Decrypt can be in either upper or lower case.
The driver is to be placed in the file driver.cpp and is to be compiled with the code from
part 1.
