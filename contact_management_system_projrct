#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contact structure
struct Contact {
    char name[50];
    char phone[15];   // phone ko string rakha
    char email[50];
};

// Function to add a new contact
void addContact() {
    struct Contact s;
    FILE *p = fopen("contacts.txt", "a");  // append mode
    if (p == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter the Name: ");
    scanf("%s", s.name);

    printf("Enter the Mobile Phone number: ");
    scanf("%s", s.phone);

    printf("Enter Email: ");
    scanf("%s", s.email);

    fprintf(p, "%s %s %s\n", s.name, s.phone, s.email);
    fclose(p);

    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts() {
    struct Contact s;
    FILE *p = fopen("contacts.txt", "r");
    if (p == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (fscanf(p, "%s %s %s", s.name, s.phone, s.email) != EOF) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n-------------------\n",
               s.name, s.phone, s.email);
    }
    fclose(p);
}

// Function to search for a contact
void searchContact() {
    struct Contact s;
    char name[50], number[15];
    int found = 0;

    FILE *p = fopen("contacts.txt", "r");
    if (p == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("Enter name to search: ");
    scanf("%s", name);
    printf("Enter phone to search: ");
    scanf("%s", number);

    while (fscanf(p, "%s %s %s", s.name, s.phone, s.email) != EOF) {
        if (strcmp(s.name, name) == 0 || strcmp(s.phone, number) == 0) {
            printf("Found Contact:\nName: %s\nPhone: %s\nEmail: %s\n",
                   s.name, s.phone, s.email);
            found = 1;
            break;
        }
    }
    fclose(p);

    if (!found)
        printf("Contact not found!\n");
}

// Function to update a contact
void updateContact() {
    struct Contact s;
    char name[50];
    int found = 0;

    FILE *p = fopen("contacts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (p == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter name of contact to update: ");
    scanf("%s", name);

    while (fscanf(p, "%s %s %s", s.name, s.phone, s.email) != EOF) {
        if (strcmp(s.name, name) == 0) {
            printf("Current -> Name: %s, Phone: %s, Email: %s\n",
                   s.name, s.phone, s.email);

            printf("Enter new Phone: ");
            scanf("%s", s.phone);
            printf("Enter new Email: ");
            scanf("%s", s.email);

            found = 1;
        }
        fprintf(temp, "%s %s %s\n", s.name, s.phone, s.email);
    }

    fclose(p);
    fclose(temp);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        printf("Contact updated successfully!\n");
    else
        printf("Contact not found!\n");
}

// Function to delete a contact
void deleteContact() {
    struct Contact s;
    char name[50];
    int found = 0;

    FILE *p = fopen("contacts.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (p == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter name of contact to delete: ");
    scanf("%s", name);

    while (fscanf(p, "%s %s %s", s.name, s.phone, s.email) != EOF) {
        if (strcmp(s.name, name) == 0) {
            found = 1;
            continue;   // skip writing this record
        }
        fprintf(temp, "%s %s %s\n", s.name, s.phone, s.email);
    }

    fclose(p);
    fclose(temp);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        printf("Contact deleted successfully!\n");
    else
        printf("Contact not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
