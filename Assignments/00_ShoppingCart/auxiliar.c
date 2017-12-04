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

void printTextToColumn(char text[], int width){
  if(strlen(text)>width){
    for(int i=0;i<width-3;i++){
      printf("%c",text[i]);
    }
    printf("...");
  }else{
    printf("%s",text);
    for(int i=strlen(text);i<width;i++){
      printf(" ");
    }
  }
}
void addProduct(){
  struct Product newProduct;
  printf("\tType product name: ");
  scanf("\n%[^\n]s", newProduct.name);
  printf("\tType product Price: ");
  scanf("%f", &newProduct.price);
  printf("\tType product Quantity: ");
  scanf("%i", &newProduct.quantity);
  FILE *fp;
  fp = fopen("product.dat","ab");
  int id = ftell(fp)/sizeof(struct Product);
  newProduct.ID = id+1;
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
    fp=fopen("product.dat", "rb");
    struct Product products[100];
    if(fp!=NULL){
        int count=0;
        struct Product temp;
        while (1) {
            fread(&temp, sizeof(struct Product), 1, fp);
            if(feof(fp)){
                break;
            }
            products[count]=temp;
            count+=1;
        }
        if(count==0){
            printCenteredText("Aun no hay productos.\n", WIDTH);
        }else{
            printf("\t|ID  |Name           |Price   |Quantity|\n");
            char buffer[31];
            for(int i=0;i<count;i++){
                printf("\t|");
                snprintf(buffer,30,"%d", products[i].ID);
                printTextToColumn(buffer, 4);
                printf("|");
                printTextToColumn(products[i].name, 15);
                snprintf(buffer,30,"%.2f",products[i].price);
                printf("|");
                printTextToColumn(buffer,8);
                printf("|");
                snprintf(buffer,30,"%d",products[i].quantity);
                printTextToColumn(buffer,5);
                printf("   |\n");
            }
        }
        fclose(fp);
    }else{
        printCenteredText("El archivo de productos no existe.\n", WIDTH);
    }
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
        break;
      case 2:
        displayAllProduct();
        printf("\n\t\tType anything and enter to get back...");
        char trash[30];
        scanf("%s",trash);
        fflush(stdin);
        break;
      case 0:
        break;
      default:
        printf("\t\tType a right option!\n");
        sleep(2);
    }
    if(option==0)break;
  }
}
void purchaseProduct(){
  while(1){
    printf("\033[2J\033[1;1H");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printCenteredText("Product Details", WIDTH);
    printf("\n");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    displayAllProduct();
    char option;
    printf("\n\tDo you want to purcharse? [y/N]:");
    scanf(" %c",&option);
    if(option != 'y' && option != 'Y')break;
    while(1){
        printf("\tType the product code to purcharse: ");
        int codigo;
        scanf("%d",&codigo);
        FILE *fp;
        fp = fopen("product.dat","rb+");
        struct Product temp;
        int status = 0;
        int index = 0;
        int pos = 0;
        while (1) {
            fread(&temp, sizeof(struct Product), 1, fp);
            if(feof(fp)){
                break;
            }
            pos++;
            if(temp.ID == codigo){
                status = 1; //found
                index = pos;
                if(temp.quantity<=0){
                    status = 2; // sold out
                }
            }
        }
        if(status>0){
            if(status == 2){
                printf("\tThis product is sold out\n");
                sleep(2);
            }else{
                fseek( fp, (index-1)*sizeof(struct Product), SEEK_SET );
                fread(&temp, sizeof(struct Product), 1, fp);
                temp.quantity--;
                fseek( fp, (index-1)*sizeof(struct Product), SEEK_SET );
                fwrite(&temp,1,sizeof(struct Product),fp);
                FILE *fp2;
                fp2 = fopen("bill.dat","ab");
                struct Bill product;
                product.pID = temp.ID;
                strcpy(product.pName,temp.name);
                product.pPrice = temp.price;
                fwrite(&product,1,sizeof(struct Bill),fp2);
                fclose(fp2);
                printf("\tAdded to your cart! ;)\n");
                sleep(1);
            }
        }else{
            printf("\tThis product does not exist :C\n");
            sleep(2);
        }

        fclose(fp);
        break;

    }

  }
}
void generateBill(){
    printf("\033[2J\033[1;1H");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printCenteredText("Bill Details", WIDTH);
    printf("\n");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    FILE *fp;
    fp = fopen("bill.dat","rb");
    struct Bill items[100];
    int count = 0;
    while(1){
        struct Bill temp;
        fread(&temp, sizeof(struct Bill), 1, fp );
        if (feof(fp)){
            break;
        }
        items[count] = temp;
        count++;
    }
    if(count){
        printf("\t|ID   |Product        |Price   |\n");
        char buffer[30];
        float total = 0;
        for(int i=0;i<count;++i){
            printf("\t|");
            snprintf(buffer,30,"%d",items[i].pID);
            printTextToColumn(buffer, 5);
            printf("|");
            printTextToColumn(items[i].pName, 15);
            printf("|");
            snprintf(buffer,30,"%.2f",items[i].pPrice);
            printTextToColumn(buffer, 8);
            printf("|\n");
            total += items[i].pPrice;
        }
        printf("\n\n\tDo you want to generate the bill [y/N]?:");
        char option;
        scanf(" %c",&option);
        if(option !='y' && option!='Y')return ;
        printf("\n\n\t\tTotal amount is: %.2f\n",total);
        printf("\t\tPlease checkout...\n");
        remove("bill.dat");
        sleep(4);
    }else{
        printf("\t\tThere is no products in the cart\n");
        sleep(2);
    }
}
int showPrincipalMenu(){
  while(1){
    printf("\033[2J\033[1;1H");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printCenteredText("Welcome to shopping store", WIDTH);
    printf("\n");
    printNCharacters((int)'=',WIDTH);
    printf("\n");
    printf("\t1.- Manage Product\n");
    printf("\t2.- Purchase Product\n");
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
        purchaseProduct();
        break;
      case 3:
        generateBill();
        break;
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
