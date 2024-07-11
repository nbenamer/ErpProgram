#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int stock;
} Product;

extern Product products[MAX_PRODUCTS];
extern int productCount;

void addProduct();
void listProducts();
void deleteProduct(int id);

#endif 
