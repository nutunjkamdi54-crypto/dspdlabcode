#include <stdio.h>

struct student {
    int rollno;
    char name[50];
    char surname[50];
    float avgmarks;
};


void bubbleSort(struct student arr[], int n) {
    int i, j;
    struct student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].avgmarks < arr[j + 1].avgmarks) {  
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll no: ");
        scanf("%d", &s[i].rollno);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Surname: ");
        scanf("%s", s[i].surname);
        printf("Average marks: ");
        scanf("%f", &s[i].avgmarks);
    }

    bubbleSort(s, n);

    printf("\n--- Students sorted by Average Marks (Descending Order) ---\n");
    for (i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s %s, Average Marks: %.2f\n",
               s[i].rollno, s[i].name, s[i].surname, s[i].avgmarks);
    }

    return 0;
}
