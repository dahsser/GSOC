### Struct
_**struct**_ is used to declare a new data-type
A way to declare _**struct**_ in C is:
```C
struct data{
    int a;
    int b;
};
```
Another one
```C
struct {
    int a;
    int b;
} x; //This creates an anonymous struct and only 'x' has that data type
```
To create a variable of a struct type we made
```C
struct data x;
```
To access to the values of and struct
```C
x.a = 30 ;
printf("%d",x.a);
```
