/*
 * Author : Diego Lopez
 * email  : dilogi7@gmail.com
 * github : /dahsser
 * This is the main function for a shopping cart
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define WIDTH 50

/* Data Structures */
struct Product{
  int ID;
  char name[35];
  float price;
  int quantity;
} Product;

struct Bill{
  int pID;
  char pName[35];
  float pPrice;
} Bill;

/* Function prototypes */

int getID();

void showPrincipalMenu();
void manageProduct();
void purcharseProduct();
void generateBill();
void addProduct();
void displayAllProduct();
#include "auxiliar.h"

int main(int argv, char *argc[]){
  showPrincipalMenu(WIDTH);
}
