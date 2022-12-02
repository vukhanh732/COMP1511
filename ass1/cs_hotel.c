// Program name
//
// This program was written by [your name] (z5555555)
// on [date]
//
// Description of program

#include <stdio.h>

// Additional libraries here
#include <stdlib.h>

// Provided constants
#define TRUE 1
#define FALSE 0

#define TOTAL_FLOORS 8
#define ROOMS_PER_FLOOR 8
#define INITIAL_PRICE 10
#define NO_BOOKING -1

// Your constants here

// Provided struct
struct room {
    int booking_id;
    int price;
};

// Provided functions use for game setup
// You do not need to use these functions yourself.
void init_hotel(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]);


// You will need to use these functions for stage 1.
void print_hotel(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]);
void print_hotel_with_prices(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]);

// Your function prototypes here:
int invalid_room(int room, int floor);
int room_is_empty(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR], int floor, int room);
int calculate_total_revenue(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]);
void revenue_compare(int prev_rev, int total_rev);
void add_to_best_room(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR], int id);


int main(void) {
    struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR];
    init_hotel(hotel);

    printf("Welcome to the CS Hotel!!\n\n");

    // TODO: Add your setup phase
    int num_guests, floor, room, invalid = 0, valid_guest = 0;
    printf("Add your current guests, how many guests? ");
    scanf("%d", &num_guests);

    printf("Input in your guests room numbers\n");
    for (int i = 0; i < num_guests; i++) {
        scanf("%d %d", &floor, &room);
        if (invalid_room(floor, room)) {
            printf("Invalid room number!\n");
            invalid++;
        } else {
            if (room_is_empty(hotel, floor, room)) {
                hotel[floor][room].booking_id = i - invalid;
                valid_guest++;
            } else {
                printf("Room already occupied!\n");
                invalid++;
            }
        }
    }

    print_hotel(hotel);
    printf("Enter a command: ");

    // TODO: keep scanning in commands from the user until the user presses
    // ctrl-d
    char command;
    int temp_floor, temp_room = 0;
    int new_price, vary_amount;
    int total_rev = 0;
    int prev_rev = 0;
    int temp_id;
    int floor_a, room_a, floor_b, room_b;
    

    while (scanf(" %c", &command) != EOF) {
        switch(command) {
            // Print hotel command
            case 'p':
                print_hotel(hotel);
                break;
            // Show room info command
            case '?':
                scanf("%d %d", &temp_floor, &temp_room);
                // If room or floor number is invalid, break out of switch statement
                if (invalid_room(temp_floor, temp_room)) {
                    printf("Invalid room number!\n");
                    break;
                }
                // If bookingID is not -1, it means room is booked
                if (!room_is_empty(hotel, temp_floor, temp_room)) {
                    printf("Booking ID at Floor %d, Room %d is : %d\n", temp_floor, 
                    temp_room, hotel[temp_floor][temp_room].booking_id);
                    break;
                // If bookingID is -1 then its empty
                } else {
                    printf("Floor %d, Room %d is empty.\n", temp_floor, temp_room);
                    break;
                }
            // Add people to room command
            case 'a':
                scanf("%d %d", &temp_floor, &temp_room);
                // If room is invalid
                if (invalid_room(temp_floor, temp_room)) {
                    printf("Invalid room number!\n");
                    break;
                }
                // If room already occupied
                else if (!room_is_empty(hotel, temp_floor, temp_room)) {
                    printf("Room already occupied!\n");
                    break;
                }
                // If room is available then find the next available ID and add
                // that to the new room. Increase number of valid guest by 1
                else {
                    printf("Guest's booking id is: %d\n", valid_guest);
                    hotel[temp_floor][temp_room].booking_id = valid_guest;
                    valid_guest++;
                    break;
                }
            // Guest leave command
            case 'l':
                scanf("%d %d", &temp_floor, &temp_room); 
                if (invalid_room(temp_floor, temp_room)) {
                    printf("Invalid room number!\n");
                    break;
                } 
                // If the room is empty then guest can't leave
                else if (room_is_empty(hotel, temp_floor, temp_room)) {
                    printf("This room is already empty.\n");
                    break;
                } 
                // If that room has a guest in it. Set booking_id to NO_BOOKING
                else {
                    printf("Goodbye booking %d!\n", hotel[temp_floor][temp_room].booking_id);
                    hotel[temp_floor][temp_room].booking_id = NO_BOOKING;
                    break;
                }
            case 'c':
                print_hotel_with_prices(hotel);
                break;
            case '$':
                scanf("%d %d", &temp_floor, &new_price);
                if (invalid_room(temp_floor, 1)) {
                    printf("Invalid floor number!\n");
                    break;
                } else if (new_price < 0) {
                    printf("Invalid price!\n");
                    break;
                } else {
                    for (int i = 0; i < ROOMS_PER_FLOOR; i++) {
                        hotel[temp_floor][i].price = new_price;
                    }
                    break;
                }
            case '^':
                scanf("%d", &vary_amount);
                for (int i = 0; i < TOTAL_FLOORS; i++) {
                    for (int j = 0; j < TOTAL_FLOORS; j++) {
                        if (hotel[i][j].price + vary_amount < 0) 
                            hotel[i][j].price = 0;
                        else 
                            hotel[i][j].price = hotel[i][j].price + vary_amount;
                    }
                }
                break;
            case 'r':
                prev_rev = total_rev;
                total_rev = calculate_total_revenue(hotel);
                printf("The total revenue for the night is $%d\n", total_rev);
                revenue_compare(prev_rev, total_rev);
                break;
            case 'j':
                add_to_best_room(hotel, valid_guest);
                valid_guest++;
                break;
            case 's':
                scanf("%d %d %d %d", &floor_a, &room_a, &floor_b, &room_b);
                if (invalid_room(floor_a, room_a) == TRUE || invalid_room(floor_b, room_b) == TRUE) {
                    printf("Invalid room number!\n");
                } else {
                    temp_id = hotel[floor_a][room_a].booking_id;
                    hotel[floor_a][room_a].booking_id = hotel[floor_b][room_b].booking_id;
                    hotel[floor_b][room_b].booking_id = temp_id;
                }
                break;

                

        }
        printf("Enter a command: ");
    }
    printf("Bye!\n");
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////// ADDITIONAL FUNCTIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: you may need to add additional functions here

int invalid_room (int floor, int room) {
    if (floor < 0 || floor >= 8 || room < 0 || room >= 8) {
        return TRUE;
    }
    return FALSE;
}

int room_is_empty(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR], int floor, int room) {
    if (hotel[floor][room].booking_id == -1) {
        return TRUE;
    }
    return FALSE;
}

int calculate_total_revenue(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]) {
    int total_rev = 0;
    for (int i = 0; i < TOTAL_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (!room_is_empty(hotel, i, j)) {
                total_rev += hotel[i][j].price;
            }
        }
    }
    return total_rev;
}

void revenue_compare(int prev_rev, int total_rev) {
    int diff = total_rev - prev_rev;
    if (diff > 0) {
        printf("This is $%d more than last time :)\n", diff);
    } else if (diff == 0) {
        printf("This is the same as the last time you asked :\\\n");
    } else {
        printf("This is $%d less than last time (haha lol)\n", abs(diff));
    }
}

void add_to_best_room(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR], int id) {
    int flag = 0;
    for (int i = 0; i < TOTAL_FLOORS && flag == 0; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (room_is_empty(hotel, i, j)) {
                hotel[i][j].booking_id = id;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0) {
        printf("The hotel is full!\n");
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROVIDED FUNCTIONS //////////////////////////////
/////////////////////////// (DO NOT EDIT BELOW HERE) ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided Function (you shouldn't need to edit this in stage 1 or 2)
// Initalises the booking id and price of each room in the hotel to be
// the default values.
void init_hotel(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]) {
    int row = 0;
    while (row < TOTAL_FLOORS) {
        int col = 0;
        while (col < ROOMS_PER_FLOOR) {
            hotel[row][col].booking_id = NO_BOOKING;
            hotel[row][col].price = INITIAL_PRICE;
            col++;
        }
        row++;
    }
}

// Provided Function - DO NOT EDIT
// Prints out the hotel with the booking number of each room, or empty
// if there is no booking.
void print_hotel(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]) {
    printf(
        "\n"
        "         /--^--\\\n"
        "   _     |  O  |     _\n"
        " _/ \\___/_^___^_\\___/ \\_\n"
        "/                       \\\n");

    int row = 0;
    while (row < TOTAL_FLOORS) {
        int col = 0;
        printf("|--+--+--+--+--+--+--+--|\n");
        while (col < ROOMS_PER_FLOOR) {
            printf("|");
            if (hotel[row][col].booking_id == NO_BOOKING) {
                printf("  ");
            } else {
                printf("%02d", hotel[row][col].booking_id);
            }
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(
        "|--+--+--+--+--+--+--+--|\n"
        "|         /^^^\\         |\n"
        "|_________|_\"_|_________|\n\n");
}

// Provided Function - DO NOT EDIT
// Prints out the hotel with the the price and booking number included.
void print_hotel_with_prices(struct room hotel[TOTAL_FLOORS][ROOMS_PER_FLOOR]) {
    printf(
        "\n"
        "             /--^--\\\n"
        "   _         |  O  |         _\n"
        " _/ \\_______/_^___^_\\_______/ \\_\n"
        "/                               \\\n");

    int row = 0;
    while (row < TOTAL_FLOORS) {
        int col = 0;
        printf("|---+---+---+---+---+---+---+---|\n");
        while (col < ROOMS_PER_FLOOR) {
            printf("|");
            if (hotel[row][col].booking_id == NO_BOOKING) {
                printf("   ");
            } else {
#ifndef NO_COLORS
                printf("\033[1;35m");
#endif
                printf("%03d", hotel[row][col].booking_id);
#ifndef NO_COLORS
                printf("\033[0m");
#endif
            }
            col++;
        }
        printf("|\n");
        col = 0;
        while (col < ROOMS_PER_FLOOR) {
            printf("|");
#ifndef NO_COLORS
            printf("\033[1;32m");
#endif
            printf("%03d", hotel[row][col].price);
#ifndef NO_COLORS
            printf("\033[0m");
#endif
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(
        "|---+---+---+---+---+---+---+---|\n"
        "|             /^^^\\             |\n"
        "|_____________|_\"_|_____________|\n\n");
}
