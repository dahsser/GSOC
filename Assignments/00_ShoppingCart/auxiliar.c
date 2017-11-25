#include "auxiliar.h"
#include <stdio.h>
#include <string.h>
void printNCharacters(char c,int n){
  for(int i = 0;i<n;i++){
    printf("%c", c);
  }
  printf("\n");
}

void printCenteredText(char text[],int width){
  int left = (width-strlen(text))/2;
  for(int i=0;i<left;i++)printf(" ");
  printf("%s",text);
  printf("\n");
}
void showPrincipalMenu(int WIDTH){
  int option;
  printNCharacters((int)'=',WIDTH);
  printf("\n");
  printCenteredText("Welcome to shopping list", WIDTH);
  printf("\n");
  printNCharacters((int)'=',WIDTH);
  printf("\n");
  printf("\t1.- Manage Product\n");
  printf("\t2.- Purcharse Product\n");
  printf("\t3.- Generate Bill\n");
  printf("\t0.- Exit\n\n");
  printNCharacters((int)'=',WIDTH);
  printf("\n");
  printf("\t\tOption: ");
  scanf("%d",&option);
  fflush(stdin);
  scanf("%d",&option);
  fflush(stdin);

}
