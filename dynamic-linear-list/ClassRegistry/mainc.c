#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classregistry.h"
//06

int main() {

    Discipline* head = NULL;
    int choice;
    char codeToRemove[10];

    do {
        printf("\nOptions menu:\n");
        printf("1. Insert a new discipline\n");
        printf("2. Remove a discipline by code\n");
        printf("3. Display disciplines in the computer lab\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertDiscipline(head);
                break;
            case 2:
                printf("Enter the code of the discipline to remove: ");
                scanf("%s", codeToRemove);
                head = removeDiscipline(head, codeToRemove);
                break;
            case 3:
                displayComputerLabDisciplines(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    Discipline* current = head;
    while (current != NULL) {
        Discipline* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
