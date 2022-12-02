// 
// Written INSERT-DATE-HERE
// By INSERT-AUTHOR-HERE
//
// INSERT-DESCRIPTION-HERE
//

#include <stdio.h>

#define MAX_ROOMS 50

struct hotel_room {
    // TODO: fill this in with the details of each hotel room
    int room_number;
    double price;
};

// Prints the room in the correct format when given the room_number
// and price of it.
void print_room(int room_number, double price);

int main(void) {
    int num_room;
    struct hotel_room hotel[MAX_ROOMS];


    printf("How many rooms? ");
    // TODO: scan in how many rooms in the hotel
    scanf("%d", &num_room);

    printf("Enter hotel rooms:\n");
    // TODO: scan in the details of each hotel room
    for (int i = 0; i < num_room; i++) {
        scanf("%d %lf", &hotel[i].room_number, &hotel[i].price);
    }

    printf("Room List:\n");
    // TODO: print all the rooms scanned in
    for (int i = 0; i < num_room; i++) {
        print_room(hotel[i].room_number, hotel[i].price);
    }

    return 0;
}

// Prints the room in the correct format when given the room_number
// and price of it.
//
// Takes in:
// - `room_number` -- The hotel room's room number.
// - `price` -- How much the hotel room costs.
//
// Returns: nothing.
void print_room(int room_number, double price) {

    printf("Room %d @ $%.2lf\n", room_number, price);

    return;
}