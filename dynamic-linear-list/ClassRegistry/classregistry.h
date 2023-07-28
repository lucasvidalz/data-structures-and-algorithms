#ifndef CLASSREGISTRY_H
#define CLASSREGISTRY_H
#include <stdio.h>


// Structure to hold the data of each discipline
typedef struct Discipline {
    char code[10];
    char name[100];
    int inComputerLab; // 1 if the discipline is in the computer lab, 0 otherwise
    struct Discipline* next;

} Discipline;

//implementation - could be a .c file, but for being simple I keep it here

Discipline* insertDiscipline(Discipline* head) {
    Discipline* newDiscipline = (Discipline*)malloc(sizeof(Discipline));
    if (newDiscipline == NULL) {
        printf("Memory allocation failed. Unable to insert discipline.\n");
        return head;
    }

    printf("Enter the code of the discipline: ");
    scanf("%s", newDiscipline->code);

    printf("Enter the name of the discipline: ");
    getchar(); // To consume the newline character left by the previous scanf
    fgets(newDiscipline->name, sizeof(newDiscipline->name), stdin);
    newDiscipline->name[strcspn(newDiscipline->name, "\n")] = '\0'; // Remove newline character if present

    printf("Is the discipline in the computer lab? (1 for Yes, 0 for No): ");
    scanf("%d", &newDiscipline->inComputerLab);

    newDiscipline->next = head;
    head = newDiscipline;

    printf("Discipline inserted successfully.\n");
    return head;
}

Discipline* removeDiscipline(Discipline* head, const char* code) {
    if (head == NULL) {
        printf("List is empty. Unable to remove discipline.\n");
        return NULL;
    }

    Discipline* current = head;
    Discipline* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->code, code) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Discipline with code %s removed successfully.\n", code);
            return head;
        }

        prev = current;
        current = current->next;
    }

    printf("Discipline with code %s not found. Unable to remove.\n", code);
    return head;
}

void displayComputerLabDisciplines(Discipline* head) {
    if (head == NULL) {
        printf("List is empty. No disciplines found in the computer lab.\n");
        return;
    }

    printf("Disciplines in the computer lab (PVA 227):\n");
    Discipline* current = head;

    while (current != NULL) {
        if (current->inComputerLab == 1) {
            printf("Code: %s, Name: %s\n", current->code, current->name);
        }
        current = current->next;
    }
}

#endif

