#ifndef AUXILIAR_H_
#define AUXILIAR_H_
/* Constants */
#define WIDTH 50
/* Data Structures */
struct Product{
  int ID;
  char name[35];
  float price;
  int quantity;
};

struct Bill{
  int pID;
  char pName[35];
  float pPrice;
};
/* Auxiliars */
void printNCharacters(char character, int times);
void printCenteredText(char text[],int width);
void printTextToColumn(char text[],int width);
int showPrincipalMenu();
void manageProduct();
void purcharseProduct();
void generateBill();
void addProduct();
void displayAllProduct();
#endif
