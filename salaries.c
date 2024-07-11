#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salaries.h"

Salary salaries[MAX_SALARIES];
int salaryCount = 0;

void loadSalaries(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (salaryCount >= MAX_SALARIES) {
            break;
        }
        Salary s;
        sscanf(line, "%d,%10[^,],%f,%f,%f",
               &s.employee_id, s.date, &s.gross_salary, &s.net_salary, &s.tax);
        salaries[salaryCount++] = s;
    }

    fclose(file);
}

void saveSalaries(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    for (int i = 0; i < salaryCount; i++) {
        fprintf(file, "%d,%s,%.2f,%.2f,%.2f\n", salaries[i].employee_id, salaries[i].date,
                salaries[i].gross_salary, salaries[i].net_salary, salaries[i].tax);
    }

    fclose(file);
}

void addSalary() {
    if (salaryCount < MAX_SALARIES) {
        Salary newSalary;

        printf("Enter employee ID: ");
        scanf("%d", &newSalary.employee_id);
        getchar();  

        printf("Enter date (YYYY-MM-DD): ");
        fgets(newSalary.date, sizeof(newSalary.date), stdin);
        newSalary.date[strcspn(newSalary.date, "\n")] = 0;

        printf("Enter gross salary: ");
        scanf("%f", &newSalary.gross_salary);
        getchar();  

        printf("Enter net salary: ");
        scanf("%f", &newSalary.net_salary);
        getchar(); 

        printf("Enter tax: ");
        scanf("%f", &newSalary.tax);
        getchar();  

        salaries[salaryCount++] = newSalary;
        printf("Salary added successfully!\n");

        saveSalaries("salaries.csv");
    } else {
        printf("Salary list is full!\n");
    }
}

void listSalariesForEmployee(int employee_id) {
    printf("=== Salary Details for Employee ID: %d ===\n", employee_id);
    for (int i = 0; i < salaryCount; i++) {
        if (salaries[i].employee_id == employee_id) {
            printf("Date: %s, Gross Salary: %.2f, Net Salary: %.2f, Tax: %.2f\n",
                   salaries[i].date, salaries[i].gross_salary, salaries[i].net_salary, salaries[i].tax);
        }
    }
}
