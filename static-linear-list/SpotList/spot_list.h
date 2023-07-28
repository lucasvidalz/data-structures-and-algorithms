#ifndef SPOT_LIST_H
#define SPOT_LIST_H
#include <stdio.h>

//store up to 100 songs
#define MAX_SIZE 100

typedef struct {
    char name[100];
    int duration;
} Song;

typedef struct {
    Song data[MAX_SIZE];
    int count;
} List;

void list_initialize(List *list) {
    list->count = 0;
}

int list_isFull(List *list) {
    return list->count == MAX_SIZE;
}

int list_insertAtBeginning(List *list, Song song) {
    if (list_isFull(list)) {
        return 0;
    }

    for (int i = list->count; i > 0; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[0] = song;
    list->count++;
    return 1;
}

void list_print(List *list) {
    printf("List of Songs:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Song: %s - Duration: %d seconds\n", list->data[i].name, list->data[i].duration);
    }
}






#endif // SPOT_LIST
