#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "produit.h"
#include "commande.h"
#include "employees.h"
#include "salaries.h"

void printMenu() {
    printf("\n=== Menu ===\n");
    printf("1. Add Client\n");
    printf("2. List Clients\n");
    printf("3. Delete Client\n");
    printf("4. Add Product\n");
    printf("5. List Products\n");
    printf("6. Delete Product\n");
    printf("7. Add Order\n");
    printf("8. List Orders\n");
    printf("9. Add Employee\n");
    printf("10. List Employees\n");
    printf("11. Add Salary\n");
    printf("12. View Employee Salaries\n");
    printf("13. Quit\n");
    printf("============\n");
    printf("Enter your choice: ");
}

int main() {
    loadEmployees("employees.csv");
    loadSalaries("salaries.csv");

    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                listClients();
                break;
            case 3: {
                int id;
                printf("Enter client ID to delete: ");
                scanf("%d", &id);
                getchar(); 
                deleteClient(id);
                break;
            }
            case 4:
                addProduct();
                break;
            case 5:
                listProducts();
                break;
            case 6: {
                int id;
                printf("Enter product ID to delete: ");
                scanf("%d", &id);
                getchar(); 
                deleteProduct(id);
                break;
            }
            case 7:
                addOrder();
                break;
            case 8:
                listOrders();
                break;
            case 9:
                addEmployee();
                break;
            case 10:
                listEmployees();
                break;
            case 11:
                addSalary();
                break;
            case 12: {
                int id;
                printf("Enter employee ID to view salaries: ");
                scanf("%d", &id);
                getchar(); 
                listSalariesForEmployee(id);
                break;
            }
            case 13:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number from 1 to 13.\n");
                break;
        }
    }

    return 0;
}
