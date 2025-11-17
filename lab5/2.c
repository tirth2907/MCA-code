#include <stdio.h>

struct Student_Detail {
    int Enrollment_no;
    char Name[50];
    int Sem;
    float CPI;
};

void main() {
    struct Student_Detail s[5];
    int i;

    printf("Enter details of 5 students:\n");

    for (i = 0; i < 5; i++) {

        printf("Enrollment No: ");
        scanf("%d", &s[i].Enrollment_no);

        printf("Name: ");
        scanf("%s", s[i].Name);

        printf("Semester: ");
        scanf("%d", &s[i].Sem);

        printf("CPI: ");
        scanf("%f", &s[i].CPI);
    }

    printf("\n");

    for (i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enrollment No: %d\n", s[i].Enrollment_no);
        printf("Name: %s\n", s[i].Name);
        printf("Semester: %d\n", s[i].Sem);
        printf("CPI: %.2f\n", s[i].CPI);
    }

}
