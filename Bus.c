#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 100
#define MAX_SEATS 50
#define MAX_RESERVATIONS 200

// Structure to store bus information
typedef struct {
    int busId;
    char busName[50];
    int totalSeats;
    int availableSeats;
} Bus;

// Structure to store reservation information
typedef struct {
    int reservationId;
    int busId;
    char passengerName[50];
} Reservation;

Bus buses[MAX_BUSES];
Reservation reservations[MAX_RESERVATIONS];
int busCount = 0;
int reservationCount = 0;

// Function to add a bus
void addBus() {
    if (busCount >= MAX_BUSES) {
        printf("Bus limit reached!\n");
        return;
    }
    Bus newBus;
    newBus.busId = busCount + 1; // Simple ID assignment
    printf("Enter bus name: ");
    scanf("%s", newBus.busName);
    printf("Enter total number of seats: ");
    scanf("%d", &newBus.totalSeats);
    newBus.availableSeats = newBus.totalSeats;
    buses[busCount++] = newBus;
    printf("Bus added successfully!\n");
}

// Function to display all buses
void displayBuses() {
    if (busCount == 0) {
        printf("No buses available!\n");
        return;
    }
    printf("\nAvailable Buses:\n");
    printf("ID\tName\t\tTotal Seats\tAvailable Seats\n");
    for (int i = 0; i < busCount; i++) {
        printf("%d\t%s\t\t%d\t\t%d\n", buses[i].busId, buses[i].busName, buses[i].totalSeats, buses[i].availableSeats);
    }
}

// Function to reserve a seat on a bus
void reserveSeat() {
    int busId, seatCount;
    char passengerName[50];

    displayBuses();
    printf("Enter bus ID to reserve a seat: ");
    scanf("%d", &busId);
    if (busId < 1 || busId > busCount) {
        printf("Invalid bus ID!\n");
        return;
    }
    printf("Enter number of seats to reserve: ");
    scanf("%d", &seatCount);
    if (seatCount <= 0 || seatCount > buses[busId - 1].availableSeats) {
        printf("Invalid number of seats!\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf("%s", passengerName);

    Reservation newReservation;
    newReservation.reservationId = reservationCount + 1;
    newReservation.busId = busId;
    strcpy(newReservation.passengerName, passengerName);
    reservations[reservationCount++] = newReservation;

    buses[busId - 1].availableSeats -= seatCount; // Update available seats
    printf("Reservation successful! Reservation ID: %d\n", newReservation.reservationId);
}

// Function to view all reservations
void viewReservations() {
    if (reservationCount == 0) {
        printf("No reservations made!\n");
        return;
    }
    printf("\nReservations:\n");
    printf("ID\tBus ID\tPassenger Name\n");
    for (int i = 0; i < reservationCount; i++) {
        printf("%d\t%d\t%s\n", reservations[i].reservationId, reservations[i].busId, reservations[i].passengerName);
    }
}

// Main function to run the bus reservation system
int main() {
    int choice;
    do {
        printf("\nBus Reservation System\n");
        printf("1. Add Bus\n");
        printf("2. Display Buses\n");
        printf("3. Reserve Seat\n");
        printf("4. View Reservations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                displayBuses();
                break;
            case 3:
                reserveSeat();
                break;
            case 4:
                viewReservations();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
