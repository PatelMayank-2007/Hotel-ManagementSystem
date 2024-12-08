#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure to store guest details
typedef struct {
    int id;
    char name[50];
    int roomNumber;
    int nights;
} Guest;

Guest hotel[MAX];
int count = 0;

// Function to add a guest
void addGuest() {
    if (count < MAX) {
        printf("Enter Guest ID: ");
        scanf("%d", &hotel[count].id);
        printf("Enter Guest Name: ");
        scanf(" %[^\n]", hotel[count].name);
        printf("Enter Room Number: ");
        scanf("%d", &hotel[count].roomNumber);
        printf("Enter Number of Nights: ");
        scanf("%d", &hotel[count].nights);
        count++;
        printf("Guest added successfully!\n");
    } else {
        printf("Sorry, the hotel is full!\n");
    }
}

// Function to view all guests
void viewGuests() {
    if (count == 0) {
        printf("No guests are currently checked in.\n");
    } else {
        printf("\nList of Guests:\n");
        printf("ID\tName\t\tRoom\tNights\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t%s\t\t%d\t%d\n", hotel[i].id, hotel[i].name, hotel[i].roomNumber, hotel[i].nights);
        }
    }
}

// Function to check out a guest
void checkOutGuest() {
    if (count == 0) {
        printf("No guests to check out.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Guest ID to check out: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (hotel[i].id == id) {
            found = 1;
            printf("Guest %s checked out from room %d.\n", hotel[i].name, hotel[i].roomNumber);
            for (int j = i; j < count - 1; j++) {
                hotel[j] = hotel[j + 1];
            }
            count--;
            break;
        }
    }

    if (!found) {
        printf("Guest with ID %d not found.\n", id);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Add Guest\n");
        printf("2. View Guests\n");
        printf("3. Check Out Guest\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                viewGuests();
                break;
            case 3:
                checkOutGuest();
                break;
            case 4:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}