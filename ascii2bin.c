offset = 1;
number = 0;
    
retval = read(0, &ascii_value, 1);
while (retval == 1)
    digit = ascii_value - offset;
    number = (number << 1) + digit;  
    retval = read(0, &ascii_value, 1);
        
printf("%d\n", number);
return 0;