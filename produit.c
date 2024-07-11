#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produit.h"

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        Product newProduct;
        newProduct.id = productCount + 1;
        
        printf("Enter product name: ");
        fgets(newProduct.name, sizeof(newProduct.name), stdin);
        newProduct.name[strcspn(newProduct.name, "\n")] = 0;  

        printf("Enter product price: ");
        scanf("%f", &newProduct.price);
        getchar();  

        printf("Enter product stock: ");
        scanf("%d", &newProduct.stock);
        getchar(); 
        
        products[productCount] = newProduct;
        productCount++;
        printf("Product added successfully!\n");
    } else {
        printf("Product list is full!\n");
    }
}

void listProducts() {
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Stock: %d\n",
               products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void deleteProduct(int id) {
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found!\n");
    }
}
