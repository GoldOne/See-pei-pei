LOA(Last Output Analysis)
===========

The purpose of this program is to write a last output analyser **(loa)** in C++.

###Backup on last:

The man page for last tells us:
```shell
last - display login and logout information about
users and terminals.
```
We will be focusing on analysing the output of `last -a`.

Here go two typical lines of output.

**lukemc pts/11 Mon Mar 10 14:13 - 15:31 (01:17) info-b64752s.cs.uow.edu.au**

**lukemc sshd Mon Mar 10 14:13 - 15:31 (01:17) info-b64752s.cs.uow.edu.au**

The first column is the user name. The second column is the terminal, either pts/# or sshd.
The third, fourth and fifth columns contain the short form of the day and month, following by
the day number. The next section contains the start time and the end time, with the bracketed
total time. It is possible for a session to be for (00:00). The last field is the hostname, which
we will ignore for this analysis.

Some of the lines can be ignored in the analysis:
+ The sshd lines.
+ The lines with ¡°still logged in¡± listed in place of the end time.
+ The reboot related lines.

For testing, it is a good idea to take a fixed output from `last`, store it in a file, and direct that
into your program rather than running `last` every time. You should consider using a subset
for some of your testing too.

####The task:

You are to write a C++ program that should compile on Banshee using the instruction:

    $ CC A1.cpp -o LOA

Your program should run using instructions of the form:

    $ last -a | LOA options

    $ cat last_data.txt > LOA options

where `last_data.txt` has been generated using

    $ last -a > last_data.txt

The output from your program varies depending on the options chosen.

    $ last -a | LOA -u [username]

Provide a report on the usage of the user specified by the `username`. You should provide:
+ The first recorded login by that user.
+ The last recorded login by that user.
+ The total number logins by that user.
+ The total time that user has spent logged in.

If the `username` is omitted, the program should provide a list of the top ten users by login,
and the number of times each has logged in.

    $ last -a | LOA -t <terminal_number1> [terminal_number2]

Provide a report on the usage of the terminal specified by `terminal_number1`, or, if a
`terminal_number2` is provided, all terminals in the range `terminal_number1` to
`terminal_number2`. For example, entering `¨Ct 5 8` should mean providing information
on `pts/5`, `pts/6`, `pts/7` and `pts/8`. You should provide:
+ The first recorded login to that terminal.
+ The last recorded login to that terminal.
+ The total number of logins to that terminal.
+ The total amount of time users have spent logged in to the terminal.

Note: Some logins are for many days.

    $ last -a | LOA -d <day>

Provide a report on the usage for a specified day of the week. The argument day should take
one of the following values: `Mon, Tue, Wed, Thu, Fri, Sat, Sun`. You should provide:
+ A list of the number of logins per day of the specified type. You should list the date
and the number of logins for that day.
+ The average number of logins per day of the specified type.

$ last -a | LOA -m

Provide a report on the usage by time. Break the time into blocks of quarter of an hour,
`00:00-00:14, 00:15-00:29, ¡­, 23:45-23:59`. You should provide:
+ The number of logins within each time block.
+ The number of logouts within each time block.

A user should be able to choose any number of options, so, for example, the following should work:

    $ last -a | LOA -m -d Tue -t 4 20 -u lukemc
**Notes:**
+ Do not pause the output in the program, we want to be able to run this in batch mode and will likely direct the output to a file for testing.
+ Your program should be appropriately modular.
+ You should carefully think about how you are going to store and interact with the data.
