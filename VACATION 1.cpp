#include <stdio.h>

int main() {
    FILE *file = fopen("records.dat", "a+b");
    int id;
    char name[30];
    float score;
    int choice;

    printf("1. Write Record\n2. Read Records\n3. Exit\n");

    while (scanf("%d", &choice) && choice != 3) {
        if (choice == 1) {
            printf("Enter ID, Name, Score: ");
            scanf("%d %s %f", &id, name, &score);
            fprintf(file, "%d %s %.2f\n", id, name, score);
        } else if (choice == 2) {
            rewind(file);
            while (fscanf(file, "%d %s %f", &id, name, &score) == 3) {
                printf("ID: %d Name: %s Score: %.2f\n", id, name, score);
            }
        }
        printf("\n1. Write Record\n2. Read Records\n3. Exit\n");
    }

    fclose(file);
    return 0;
}