//03
#include <stdio.h>
#include "spot_list.h"

int main() {
    List L;
    list_initialize(&L);

    // Example of inserting songs into the playlist, name and duration are sent
    Song s1 = {"Sorry 1", 180};
    Song s2 = {"Unforgettable 2", 240};
    Song s3 = {"Intentions 3", 200};

    list_insertAtBeginning(&L, s1);
    list_insertAtBeginning(&L, s2);
    list_insertAtBeginning(&L, s3);

    list_print(&L);

    return 0;
}
