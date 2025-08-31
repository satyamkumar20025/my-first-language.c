#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
struct employee {
    int id;
    char name[50];
    char address[50];
    float salary;
};

// Function prototypes
void add_employee();
void display_employee();
void search_employee();
void update_employee();
void remove_employee();

int main() {
    int choice;

    do {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Remove Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_employee(); break;
            case 2: display_employee(); break;
            case 3: search_employee(); break;
            case 4: update_employee(); break;
            case 5: remove_employee(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Add Employee
void add_employee() {
    FILE *p;
    struct employee s;

    p = fopen("employee.dat", "ab");
    if (p == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &s.id);
    printf("Enter Employee Name: ");
    scanf("%s", s.name);
    printf("Enter Employee Address: ");
    scanf("%s", s.address);
    printf("Enter Employee Salary: ");
    scanf("%f", &s.salary);

    fwrite(&s, sizeof(struct employee), 1, p);
    fclose(p);
    printf("✅ New employee added successfully!\n");
}

// Display Employees
void display_employee() {
    FILE *p;
    struct employee s;

    p = fopen("employee.dat", "rb");
    if (p == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Employee List ---\n");
    while (fread(&s, sizeof(struct employee), 1, p)) {
        printf("ID: %d | Name: %s | Address: %s | Salary: %.2f\n",
               s.id, s.name, s.address, s.salary);
    }
    fclose(p);
}

// Search Employee
void search_employee() {
    FILE *p;
    struct employee s;
    int id, found = 0;

    p = fopen("employee.dat", "rb");
    if (p == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(struct employee), 1, p)) {
        if (s.id == id) {
            printf("\n✅ Record Found!\n");
            printf("ID: %d | Name: %s | Address: %s | Salary: %.2f\n",
                   s.id, s.name, s.address, s.salary);
            found = 1;
            break;
        }
    }
    fclose(p);

    if (!found) printf("❌ No employee found with ID: %d\n", id);
}

// Update Employee
void update_employee() {
    FILE *p;
    struct employee s;
    int id, found = 0;

    p = fopen("employee.dat", "rb+");
    if (p == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(struct employee), 1, p)) {
        if (s.id == id) {
            printf("Current Name: %s\n", s.name);
            printf("Enter New Name: ");
            scanf("%s", s.name);

            printf("Current Address: %s\n", s.address);
            printf("Enter New Address: ");
            scanf("%s", s.address);

            printf("Current Salary: %.2f\n", s.salary);
            printf("Enter New Salary: ");
            scanf("%f", &s.salary);

            fseek(p, -sizeof(struct employee), SEEK_CUR);
            fwrite(&s, sizeof(struct employee), 1, p);

            printf("✅ Employee updated successfully!\n");
            found = 1;
            break;
        }
    }
    fclose(p);

    if (!found) printf("❌ No employee found with ID: %d\n", id);
}

// Remove Employee
void remove_employee() {
    FILE *p, *temp;
    struct employee s;
    int id, found = 0;

    p = fopen("employee.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (p == NULL || temp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Employee ID to remove: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(struct employee), 1, p)) {
        if (s.id != id) {
            fwrite(&s, sizeof(struct employee), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(p);
    fclose(temp);

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found) printf("✅ Employee removed successfully!\n");
    else printf("❌ No employee found with ID: %d\n", id);
}
