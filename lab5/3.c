#include <stdio.h>

struct Employee_Detail {
    int Employee_id;
    char Name[50];
    char Designation[50];
    float Salary;
};

void main() {
    struct Employee_Detail emp;
    struct Employee_Detail *ptr = &emp;

    printf("Enter Employee ID: ");
    scanf("%d", &ptr->Employee_id);

    printf("Enter Name: ");
    scanf("%s", ptr->Name);

    printf("Enter Designation: ");
    scanf("%s", ptr->Designation);

    printf("Enter Salary: ");
    scanf("%f", &ptr->Salary);

    printf("Employee ID: %d\n", ptr->Employee_id);
    printf("Name: %s\n", ptr->Name);
    printf("Designation: %s\n", ptr->Designation);
    printf("Salary: %.2f\n", ptr->Salary);

}
