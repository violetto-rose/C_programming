#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a day
struct Day {
    char *name;       // Name of the day
    int date;         // Date of the day
    char *activity;   // Description of the activity
};

// Function to dynamically allocate memory for a string
char* allocateStringMemory(char* str) {
    char* dynamicStr = (char*)malloc(strlen(str) + 1);
    strcpy(dynamicStr, str);
    return dynamicStr;
}

// Function to create a calendar
struct Day* createCalendar(int numDays) {
    struct Day* calendar = (struct Day*)malloc(numDays * sizeof(struct Day));
    if (calendar == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < numDays; i++) {
        calendar[i].name = NULL;
        calendar[i].activity = NULL;
    }
    return calendar;
}

// Function to read data for each day of the calendar
void readCalendar(struct Day* calendar, int numDays) {
    for (int i = 0; i < numDays; i++) {
        char name[20];
        int date;
        char activity[100];

        printf("Enter the name of day %d: ", i + 1);
        scanf("%s", name);
        calendar[i].name = allocateStringMemory(name);

        printf("Enter the date of day %d: ", i + 1);
        scanf("%d", &date);
        calendar[i].date = date;

        printf("Enter the activity for day %d: ", i + 1);
        scanf(" %[^\n]", activity);
        calendar[i].activity = allocateStringMemory(activity);
    }
}

// Function to display the calendar
void displayCalendar(struct Day* calendar, int numDays) {
    printf("Day\tDate\tActivity\n");
    for (int i = 0; i < numDays; i++) {
        printf("%s\t%d\t%s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

// Function to free memory allocated for the calendar
void freeCalendar(struct Day* calendar, int numDays) {
    for (int i = 0; i < numDays; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar);
}

int main() {
    int numDays = 7;

    // Create calendar
    struct Day* calendar = createCalendar(numDays);

    // Read data for each day
    readCalendar(calendar, numDays);

    // Display calendar
    displayCalendar(calendar, numDays);

    // Free memory
    freeCalendar(calendar, numDays);

    return 0;
}
