#include <stdio.h>

int main(int argc, char *argv[]){
   /*
    * argc: Es el numero de argumentos que recibe nuestro programa
    *       cuando es llamado desde la linea de comandos (o desde otro lado)
    * argv: Contiene los valores de los argumentos ingresados en linea de comandos.
    *       
    *       Los argumentos ingresados son separados por espacios y tomados 
    *       como cadenas
    */
    printf("%i\n", argc);
    //int i;
    for(int i=1;i<argc;i++){
      printf("%d\t%s\n",i,argv[i]);
    }
}
