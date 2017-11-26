#include "auxiliar.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
void addProduct(){
  struct Product newProduct;
  printf("\tType product name: ");
  scanf("%s", newProduct.name);
  printf("\tType product Price: ");
  scanf("%f", &newProduct.price);
  printf("\tType product Quantity: ");
  scanf("%i", &newProduct.quantity);
  FILE *fp;
  fp = fopen("product.dat","a");
  int id = ftell(fp)/sizeof(struct Product);
  newProduct.ID = id+1;
  printf("IDDDDDD: %d\n", id+1);
  fwrite(&newProduct,1,sizeof(struct Product),fp);
  if(fclose(fp)==0){
    printf("Success! :)");
    sleep(1);
  }else{
    printf("Somenthing went wrong! :)");
  }
}
void displayAllProduct(){
  FILE *fp;
  fp=fopen("product.dat", "r");
  struct Product products[100];
  if(fp!=NULL){
    int count=0;
    struct Product *temp;
    while (1) {
      fread(temp, sizeof(struct Product), 1, fp);
      if(feof(fp)){
        break;
      }
      products[count]=*temp;
      count+=1;
    }
    if(count==0){
      printCenteredText("Aun no hay productos.\n", WIDTH);
    }else{
        printf("\tID\tName\tPrice\tQuantity\n\n");
        for(int i=0;i<count;i++){
          printf("\t%i\t%s\t%f\t%i\n",
            products[i].ID,products[i].name,products[i].price,products[i].quantity);
        }
        printf("\n\t\tType anything and enter to get back...");
        char trash[]="  ";
        scanf("%s",trash);
        fflush(stdin);
    }
  }else{
    printCenteredText("Aun no hay productos.\n", WIDTH);
  }
  fclose(fp);
  sleep(2);
}
void manageProduct(){
  int option;
  while(1){
    printf("\033[2J\033[1;1H");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printCenteredText("Product Details", WIDTH);
    printf("\n");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printf("\t1.- Add new product\n");
    printf("\t2.- Display all products\n");
    printf("\t0.- Back\n\n");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printf("\t\tOption: ");
    scanf("%d",&option);
    fflush(stdin);
    switch (option) {
      case 1:
        addProduct();
      case 2:
        displayAllProduct();
      case 0:
        break;
      default:
        printf("\t\tType a right option!\n");
        sleep(2);
    }
    if(option==0)break;
  }
}
void purcharseProduct(){

}
void generateBill(){

}
int showPrincipalMenu(){
  while(1){
    printf("\033[2J\033[1;1H");
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
    int option;
    scanf("%d",&option);
    fflush(stdin);
    switch (option) {
      case 1:
        manageProduct();
        break;
      case 2:
        purcharseProduct();
        break;
      case 3:
        generateBill();
      case 0:
        return 1;
      default:
        printf("\t\tType a right option!");
        printf("\t\tOption: ");
        scanf("%d",&option);
        fflush(stdin);
    }
  }
  return 1;
}
