#include <stdio.h>
#include <stdlib.h>
//coo
struct Student {
    int registration;
    char name[45];
    float finalGrade;
};

int main() {
    int n;
    printf("Student Registration (REGISTRATION, NAME, AND FINAL GRADE)\n");
    printf("How many students will be added? ");
    scanf("%d", &n);

    struct Student student[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for student %d\n", i + 1);

        printf("Registration of student %d: ", i + 1);
        scanf("%d", &student[i].registration);

        printf("Name of student %d: ", i + 1);
        fflush(stdin);
        gets(student[i].name);

        printf("Final grade of student %d: ", i + 1);
        scanf("%f", &student[i].finalGrade);
    }

    float sum = 0;

    // Calculating the sum of final grades to calculate the average
    for (int i = 0; i < n; i++) {
        sum += student[i].finalGrade;
    }

    // Calculating and printing the average final grade
    float average = sum / n;
    printf("\nThe average final grade is %.2f\n", average);

    return 0;
}
