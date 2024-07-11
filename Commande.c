#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commande.h"
#include "client.h"
#include "produit.h"

Order orders[MAX_ORDERS];
int orderCount = 0;

void addOrder() {
    if (orderCount < MAX_ORDERS) {
        Order newOrder;
        newOrder.id = orderCount + 1;
        
        printf("Enter client ID: ");
        scanf("%d", &newOrder.clientId);
        getchar(); 

        printf("Enter product ID: ");
        scanf("%d", &newOrder.productId);
        getchar();  

        printf("Enter quantity: ");
        scanf("%d", &newOrder.quantity);
        getchar();  

        printf("Enter date (YYYY-MM-DD): ");
        fgets(newOrder.date, sizeof(newOrder.date), stdin);
        newOrder.date[strcspn(newOrder.date, "\n")] = 0;  

      
        int clientExists = 0, productExists = 0;
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].id == newOrder.clientId) {
                clientExists = 1;
                break;
            }
        }
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == newOrder.productId) {
                productExists = 1;
                break;
            }
        }

        if (clientExists && productExists) {
            orders[orderCount] = newOrder;
            orderCount++;
            printf("Order added successfully!\n");
        } else {
            printf("Invalid client ID or product ID!\n");
        }
    } else {
        printf("Order list is full!\n");
    }
}

void listOrders() {
    for (int i = 0; i < orderCount; i++) {
        printf("ID: %d, Client ID: %d, Product ID: %d, Quantity: %d, Date: %s\n",
               orders[i].id, orders[i].clientId, orders[i].productId, orders[i].quantity, orders[i].date);
    }
}

void deleteOrder(int id) {
    int found = 0;
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].id == id) {
            found = 1;
            for (int j = i; j < orderCount - 1; j++) {
                orders[j] = orders[j + 1];
            }
            orderCount--;
            printf("Order deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Order not found!\n");
    }
}
