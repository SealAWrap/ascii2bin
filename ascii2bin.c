#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[], char ** envp) {

    int offset = 48;
    int number = 0;
    int retval;
    char ascii_value, digit;
    int number;
        
    retval = read(0, &ascii_value, 1);
    while (retval == 1) {
        if (ascii_value == offset || ascii_value == offset + 1) {
            digit = ascii_value - offset;
            number = (number << 1) + digit;  
            retval = read(0, &ascii_value, 1);
        } else {
            retval = 0;
        }
    }
    
    printf("%u\n", number);
    return 0;
}