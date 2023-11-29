#include<stdio.h>
#include<string.h>

#define MAX_ENTRIES 200

// ANSI color codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct PhoneDirectory {
    long long int phone;
    char name[100];
};

struct PhoneDirectory phoneEntries[MAX_ENTRIES];

// Function prototypes
int operation(void);
int addPh(void);
int searchPh(void);
int editPh(void);

int main() {
    printf(ANSI_COLOR_GREEN "Welcome to the Phone Number Directory App!\n\n" ANSI_COLOR_RESET);
    operation();
    return 0;
}

int operation(void) {
    int opt;
    printf("\nEnter the corresponding number for the operation you want to do.\n"
           "1. Add Phone number\n"
           "2. Search Phone number\n"
           "3. Edit Phone Number\n"
           "4. Delete Phone Number\n"
           "0. Exit the program.\nEnter: ");
    scanf("%d", &opt);
    
    switch (opt) {
        case 0:
            break;
        case 1:
            addPh();
            break;
        case 2:
            searchPh();
            break;
        case 3:
            editPh();
            break;
        default:
            printf(ANSI_COLOR_RED "Enter a valid number\n" ANSI_COLOR_RESET);
            break;
    }

    if (opt != 0) {
        operation();
    }

    return 0;
}

int addPh(void) {
    int n;
    printf(ANSI_COLOR_CYAN "How many numbers do you want to add? (should be within %d)\n" ANSI_COLOR_RESET, MAX_ENTRIES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details of person %d\n", i + 1);
        printf("Name: ");
        scanf("%s", phoneEntries[i].name);
        printf("Phone Number: ");
        scanf("%lld", &phoneEntries[i].phone);
        printf(ANSI_COLOR_GREEN "Number added!" ANSI_COLOR_RESET);
        printf("\n---------\n");
    }

    return 0;
}

int editPh(void) {
    char editName[100];
    printf("Enter the name of the person whose number you want to edit.\nEnter: ");
    scanf("%s", editName);

    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(editName, phoneEntries[i].name) == 0) {
            printf("Enter the new number for %s.\n", editName);
            scanf("%lld", &phoneEntries[i].phone);
            printf(ANSI_COLOR_GREEN "Number updated!\n" ANSI_COLOR_RESET);
            printf("\n---------\n");
            return 0;
        }
    }

    printf(ANSI_COLOR_RED "Name not found. Please enter a valid name.\n" ANSI_COLOR_RESET);
    return 0;
}

int searchPh(void) {
    printf("Enter\n1. For search by name\n2. For search by number\n");
    int opt;
    scanf("%d", &opt);

    char searchName[100];
    if (opt == 1) {
        printf("Enter name: ");
        scanf("%s", searchName);

        int nameFound = 0;
        for (int i = 0; i < MAX_ENTRIES; i++) {
            if (strcmp(searchName, phoneEntries[i].name) == 0) {
                printf(ANSI_COLOR_GREEN "Number: %lld\n" ANSI_COLOR_RESET, phoneEntries[i].phone);
                nameFound = 1;
                break;
            }
        }

        if (!nameFound) {
            printf(ANSI_COLOR_RED "Name not found. Please retry.\n" ANSI_COLOR_RESET);
        }
    }

    return 0;
}