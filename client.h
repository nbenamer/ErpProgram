#ifndef CLIENT_H
#define CLIENT_H

#define MAX_CLIENTS 100

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[15];
} Client;

extern Client clients[MAX_CLIENTS];
extern int clientCount;

void addClient();
void listClients();
void deleteClient(int id);

#endif // CLIENT_H
