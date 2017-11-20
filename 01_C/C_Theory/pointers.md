### Pointers in C
C pointers are variables that storage memory address of data, for example:
```C
int *p; //*p is an intenger and p is a pointer to an integer
int x = 3; //creating x variable with value of 3
p = &x // giving to p x's address
//if we print the value of p:
printf("%p\n",p); // we get something like "0x7ffe2542a824"
printf("%x\n",p); // we get something like "2542a824" because 'x' flag is only for unsigned integers (2^32) in hexadecimal notation
printf("%llx\n",p); // we get something like "7ffe2542a824" (2^64) long long integer
```
##### Pointers and arrays
By default when we create arrays for example:
```C
int array[30];
char *string;
```
_array_ and _string_ are pointers and those are pointing to the first element array[0] and string[0],
if string is not initialized an address memory like 0x4004a0 is given.
