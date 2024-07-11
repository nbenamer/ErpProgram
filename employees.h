#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char first_name[50];
    char last_name[50];
    char position[50];
    char department[50];
} Employee;

extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

void loadEmployees(const char *filename);
void saveEmployees(const char *filename);
void addEmployee();
void listEmployees();

#endif
