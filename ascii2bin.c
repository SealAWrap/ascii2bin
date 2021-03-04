#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[], char ** envp) {

    char offset = 0x30;  //0x30 is the hexadecimal base of decmial 48
    int number = 0;
    int retval, count = 0;
    char ascii_value, digit;
    const char MAX_BITS_SIZE = 32;
        
    retval = read(0, &ascii_value, 1);
    while (retval == 1) {
        digit = ascii_value - offset;
        //validation if its a 0 or a 1
        if (ascii_value == offset || ascii_value == 0x31) {
            number = (number << 1) + digit;  
            retval = read(0, &ascii_value, 1);
            count++;
        } else {
            retval = 0;
        }
    }

    //validation whether , its a 1, 0, newline, neither, or the bit size is over bound
    if ((ascii_value == 0x30 || ascii_value == 0x31 || ascii_value == 0x0a) && MAX_BITS_SIZE >= count) { //0x0a is the newline char in hexadecial
        printf("%u\n", number);
        return 0;
    } else {
        return 1; //when its neither
    }
}//end of main method