#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

Client clients[MAX_CLIENTS];
int clientCount = 0;

void addClient() {
    if (clientCount < MAX_CLIENTS) {
        Client newClient;
        newClient.id = clientCount + 1;
        
        printf("Enter client name: ");
        fgets(newClient.name, sizeof(newClient.name), stdin);
        newClient.name[strcspn(newClient.name, "\n")] = 0;  

        printf("Enter client address: ");
        fgets(newClient.address, sizeof(newClient.address), stdin);
        newClient.address[strcspn(newClient.address, "\n")] = 0;  

        printf("Enter client phone: ");
        fgets(newClient.phone, sizeof(newClient.phone), stdin);
        newClient.phone[strcspn(newClient.phone, "\n")] = 0;  
        
        clients[clientCount] = newClient;
        clientCount++;
        printf("Client added successfully!\n");
    } else {
        printf("Client list is full!\n");
    }
}

void listClients() {
    for (int i = 0; i < clientCount; i++) {
        printf("ID: %d, Name: %s, Address: %s, Phone: %s\n",
               clients[i].id, clients[i].name, clients[i].address, clients[i].phone);
    }
}

void deleteClient(int id) {
    int found = 0;
    for (int i = 0; i < clientCount; i++) {
        if (clients[i].id == id) {
            found = 1;
            for (int j = i; j < clientCount - 1; j++) {
                clients[j] = clients[j + 1];
            }
            clientCount--;
            printf("Client deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Client not found!\n");
    }
}
