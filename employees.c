#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void loadEmployees(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (employeeCount >= MAX_EMPLOYEES) {
            break;
        }
        Employee e;
        sscanf(line, "%d,%49[^,],%49[^,],%49[^,],%49[^\n]",
               &e.id, e.first_name, e.last_name, e.position, e.department);
        employees[employeeCount++] = e;
    }

    fclose(file);
}

void saveEmployees(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        fprintf(file, "%d,%s,%s,%s,%s\n", employees[i].id, employees[i].first_name, employees[i].last_name,
                employees[i].position, employees[i].department);
    }

    fclose(file);
}

void addEmployee() {
    if (employeeCount < MAX_EMPLOYEES) {
        Employee newEmployee;
        newEmployee.id = employeeCount + 1;

        printf("Enter first name: ");
        fgets(newEmployee.first_name, sizeof(newEmployee.first_name), stdin);
        newEmployee.first_name[strcspn(newEmployee.first_name, "\n")] = 0;

        printf("Enter last name: ");
        fgets(newEmployee.last_name, sizeof(newEmployee.last_name), stdin);
        newEmployee.last_name[strcspn(newEmployee.last_name, "\n")] = 0;

        printf("Enter position: ");
        fgets(newEmployee.position, sizeof(newEmployee.position), stdin);
        newEmployee.position[strcspn(newEmployee.position, "\n")] = 0;

        printf("Enter department: ");
        fgets(newEmployee.department, sizeof(newEmployee.department), stdin);
        newEmployee.department[strcspn(newEmployee.department, "\n")] = 0;

        employees[employeeCount++] = newEmployee;
        printf("Employee added successfully!\n");

        saveEmployees("employees.csv");
    } else {
        printf("Employee list is full!\n");
    }
}

void listEmployees() {
    printf("=== Employee List ===\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d, Name: %s %s, Position: %s, Department: %s\n",
               employees[i].id, employees[i].first_name, employees[i].last_name,
               employees[i].position, employees[i].department);
    }
}
