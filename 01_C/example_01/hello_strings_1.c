#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
   char x = 'x';
   char arrayString1[] = "hola";
   char arrayString2[] = {'h','o','l','a','\0'};
   char *z=&x;
   for(int i=0;i<strlen(arrayString2);i++){
      printf("char:%c\tdir:%p\n",arrayString2[i],&arrayString2[i]);
   }
   for(int i=0;i<strlen(arrayString2);i++){
      printf("%x\n",&(arrayString2[i]));
   }
   return EXIT_SUCCESS;
}
