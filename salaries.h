#ifndef SALARIES_H
#define SALARIES_H

#define MAX_SALARIES 100

typedef struct {
    int employee_id;
    char date[11];
    float gross_salary;
    float net_salary;
    float tax;
} Salary;

extern Salary salaries[MAX_SALARIES];
extern int salaryCount;

void loadSalaries(const char *filename);
void saveSalaries(const char *filename);
void addSalary();
void listSalariesForEmployee(int employee_id);

#endif
