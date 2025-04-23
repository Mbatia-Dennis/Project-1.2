#include <stdio.h>
#include <string.h>

#define MAX_DORMS 10
#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 1000

typedef struct {
    char name[50];
} Student;

typedef struct {
    char name[50];
    int totalBeds;
    int occupiedBeds;
    Student students[];
} Dorm;

void displayDormStatus(Dorm dorms[], int dormCount) {
    printf("\n--- Dorm Status ---\n");
    for (int i = 0; i < dormCount; i++) {
        printf("Dorm %d: %s\n", i + 1, dorms[i].name);
        printf("  Total Beds: %d\n", dorms[i].totalBeds);
        printf("  Occupied Beds: %d\n", dorms[i].occupiedBeds);
        printf("  Available Beds: %d\n", dorms[i].totalBeds - dorms[i].occupiedBeds);
        if (dorms[i].occupiedBeds >= dorms[i].totalBeds) {
            printf("  Status:DORMS FULL!\n");
        } else {
            printf(" %d slots available\n",dorms[i].totalBeds - dorms[i].occupiedBeds);
        }

        printf("  Students:\n");
        for (int j = 0; j < dorms[i].occupiedBeds; j++) {
            printf("    - %s\n", dorms[i].students[j].name);
        }
        printf("\n");
    }
}

void addStudent(Dorm dorms[], int dormNumber[20]) {
    if (dorms[dormIndex].occupiedBeds < dorms[dormNumber].totalBeds) {
        printf("Enter student name: ");
        scanf("%s", dorms[dormNumber].students[dorms[dormNumber].occupiedBeds].name);
        dorms[dormNumber].occupiedBeds++;
        printf("Student added successfully.\n");
    } else {
        printf("Dorm is full. Cannot add more students.\n");
    }
}

void searchStudent(Dorm dorms[], int dormCount) {
    char target[50];
    printf("Enter student name to search: ");
    scanf("%s", target);

    for (int i = 0; i < dormCount; i++) {
        for (int j = 0; j < dorms[i].occupiedBeds; j++) {
            if (strcmp(dorms[i].students[j].name, target) == 0) {
                printf("Student '%s' found in Dorm '%s'.\n", target, dorms[i].name);
                return;
            }
        }
    }
    printf("Student '%s' not found.\n", target);
}

int main() {
    Dorm dorms[10];
    int dormCount;

    printf("Enter number of dorms: ");
    scanf("%d", &dormCount);

    for (int i = 0; i < dormCount; i++) {
        printf("Enter name for dorm %d: ", i + 1);
        scanf("%s", dorms[i].name);
        printf("Enter total number of beds in %s: ", dorms[i].name);
        scanf("%d", &dorms[i].totalBeds);
        dorms[i].occupiedBeds = 0;
    }

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Display dorm status\n");
        printf("2. Add student to dorm\n");
        printf("3. Search for student by name\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayDormStatus(dorms, dormCount);
                break;
            case 2: {
                int dormNumber;
                printf("Enter dorm number (1 to %d): ", dormCount);
                scanf("%d", &dormNumber);
                if (dormNumber >= 1 && dormNumber <= dormCount) {
                    addStudent(dorms, dormNumber - 1);
                } else {
                    printf("Invalid dorm number.\n");
                }
                break;
            }
            case 3:
                searchStudent(dorms, dormCount);
                break;
            case 0:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}