# ascii2bin

### COMP 122: Converting ASCII digits to a number.


# Purpose
Now that you have completed one programming assignment in C, coupled with the use of make and git, it is time to continue to practice writting more code.  This simple coding assignment is based upon the information you are learning in class about various encoding schemes; in particular, the encodings of ASCII characters and binary numbers.   Moreover, this assignment will help you to better understand the algorithm used to convert binary numbers into decimal numbers.

In summary, the purpose of this assignment is:

* to continue your exposure to C, make, and Git
* to ensure you understand the difference between ASCII numbers and binary numbers
* to validate you understand how to convert a binary number into a decimal number

The description of this assignment also includes more detailed information about a suggestive development process.  The various git commands usind within this process are provided to help you along your way.


# Assignment
Your task is to develop a C program, called ascii2bin, that
  * reads a string of 1's and 0's as ASCII digits, and 
  * outputs the equivalent unsigned decimal number 

Your program must
  1. exercises the read() system call to read a single byte, at a time, from stdin
  1. validate that the read byte is appropriate for conversion, e.g., it must be either an ASCII '0' or '1'
  1. converts each byte into an integer value via a mathematical expression
  1. uses the resulting integer as part of the calcuation to determine the final number
  1. identifies the end of a input string by either end of file or by a new line
      *  End of file is detected when read() returns the value '0'
      *  A new line is identified in the ASCII table as either: newline, nl, LF, or \n'
  1. prints this final unsigned number on stdout
  1. returns a value of 0 upon success and 1 otherwise


### The Algorithm
```
    offset = ?;
    number = 0;
    
    retval = read(0, &ascii_value, 1);
    while (retval == 1)
        digit = ascii_value - offset;
        number = (number << 1) + digit;  
        retval = read(0, &ascii_value, 1);
        
    printf("%u\n", number);
    return 0;
```

### Validation Checks:
You should add additional validation checks to your code to catch potential errors. At a minimum, validate the following:
  * that each ASCII input character is one of the following characters: '0', '1', or '\n'
  * that the calculated number does not exceed 2^32


# Your Developement Process
Some of you have some expertise in devoping your code on your home computer---great.  You can continue to develop your code in this way, using your favorite editor.  During your work, you need to continue to integrate git into your process.  


## The Initial Step
  * Fork this github repository to create your own version of the project.  You can perform this operatin via the github GUI.
  * Clone the repo onto your development computer.
  * Change your working directory to where your code is located.
  * Create your first version of your ascii2bin.c file.
  * Run the make command to build anything the Professor is providing to you, like test cases.
  * Introduce ascii2bin.c to your local repo
  * Commit ascii2bin.c to your local repo

To recap:
```
$ git clone https://github.com/COMP122/ascii2bin.git    # for example
$ cd ascii2bin
$ touch ascii2bin.c
$ make
$ git add ascii2bin.c
$ git commit -m 'Initial version' ascii2bin.c
```

  * Now create a copy on the ssh.sandbox.csun.edu server
```
$ ssh ssh.sandbox.csun.edu
$ mkdir -p comp122 ; cd comp122              # Change your working directo to by you comp122 directory
$ git clone $URL                             # Clone your repo
$ cd ascii2bin                               # Change to the correct working directory
$ ls                                         # Review that you have all the files from the repo
$ exit
```

## Going Forward

* REPEAT
    * REPEAT
      1. update your ascii2bin.c program
      1. recompile the code, via the make command, to validate it compiles correctly, etc.
      1. perform some test case  (Consider using the command:  make test )
    * UNTIL you are satisfied 
    * commit your changes to your local git repo
    ```
       $ git status
       $ git add ascii2bin.c
       $ git commit -m 'Revised Message'
    ```
    * if your code is good enough to share, push it to your remote repo
    ```
      $ git push
    ```
    * take a break
* UNTIL complete


# Final Validation and Submission
To obtain credit for this assignment, you must ensure your program works correctly on ssh.sandbox.csun.edu.  This server is a shared resource in which you can finalize you work and the professor can validate this work.  The final steps for validation are as follows:

* Update the repo on ssh.sandbox.csun.edu:
```
$ ssh ssh.sandbox.csun.edu
$ cd comp122/ascii2bin
$ git pull
$ make    
```

* Test your program:
```
$ script ascii2bin.typescript 
$ ascii2bin
0101
^d
5
$ cat 54356.txt  | ./ascii2bin ; echo $?
54356
0
$ cat 138.txt | ./ascii2bin ; echo $?
138
0
$ cat 2863311530.txt | ./ascii2bin ; echo $?
2863311530
0
$ cat 4294967295.txt | ./ascii2bin ; echo $?
4294967295
0
$ cat error.txt | ./ascii2bin ; echo $?
1
$ exit
```
* Download the typescript file from the server
```
$ scp  ssh.sandbox.csun.edu:comp122/ascii2bin/ascii2bin.typescript .
```

### Submission
* Submit your assignent to Canvas with the following information:
  * The URL to your github repo
  * The checksum.typescript file

