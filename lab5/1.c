#include <stdio.h>

struct Employee_detail {
    int Employee_id;
    char Name[50];
    char Designation[50];
    float Salary;
};

void main() {
    struct Employee_detail emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.Employee_id);

    printf("Enter Name: ");
    scanf("%s", emp.Name);

    printf("Enter Designation: ");
    scanf("%s", emp.Designation);

    printf("Enter Salary: ");
    scanf("%f", &emp.Salary);

    printf("Employee Details:\n");
    printf("Employee ID: %d\n", emp.Employee_id);
    printf("Name: %s\n", emp.Name);
    printf("Designation: %s\n", emp.Designation);
    printf("Salary: %.2f\n", emp.Salary);

}
