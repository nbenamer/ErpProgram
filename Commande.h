#ifndef ORDER_H
#define ORDER_H

#define MAX_ORDERS 100

typedef struct {
    int id;
    int clientId;
    int productId;
    int quantity;
    char date[20];
} Order;

extern Order orders[MAX_ORDERS];
extern int orderCount;

void addOrder();
void listOrders();
void deleteOrder(int id);

#endif // ORDER_H
