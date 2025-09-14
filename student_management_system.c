#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
struct Student { 
    int roll; 
    char name[50]; 
    float marks; 
}; 
 
// Function to add a student 
void addStudent() { 
    FILE *f; 
    struct Student s; 
 
    f = fopen("student.txt", "a"); 
    if (f == NULL) { 
        printf("File error.\n"); 
        return; 
    } 
 
    printf("\nEnter Roll Number: "); 
    scanf("%d", &s.roll); 
    printf("Enter Name: "); 
    scanf("%s", s.name); 
    printf("Enter Marks: "); 
    scanf("%f", &s.marks); 
 
    fprintf(f, "%d %s %.2f\n", s.roll, s.name, s.marks); 
    fclose(f); 
    printf("Student added successfully.\n"); 
} 
 
// Function to display all students 
void viewStudents() { 
    FILE *f; 
    struct Student s; 
 
    f = fopen("student.txt", "r"); 
    if (f == NULL) { 
        printf("No records found.\n"); 
        return; 
    } 
 
    printf("\n--- Student Records ---\n"); 
    while (fscanf(f, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) { 
        printf("Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks); 
    } 
 
    fclose(f); 
} 
 
// Function to search a student by roll number 
void searchStudent() { 
    FILE *f; 
    struct Student s; 
    int roll, found = 0; 
 
    f = fopen("student.txt", "r"); 
    if (f == NULL) { 
        printf("File not found.\n"); 
        return; 
    } 
 
    printf("\nEnter Roll Number to Search: "); 
    scanf("%d", &roll); 
 
    while (fscanf(f, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) { 
        if (s.roll == roll) { 
            printf("Found: Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks); 
            found = 1; 
            break; 
        } 
    } 
 
    if (!found) { 
        printf("Student with Roll %d not found.\n", roll); 
    } 
 
    fclose(f); 
} 
 
// Function to delete a student by roll number 
void deleteStudent() { 
    FILE *f, *temp; 
    struct Student s; 
    int roll, found = 0; 
 
    f = fopen("student.txt", "r"); 
    temp = fopen("temp.txt", "w"); 
 
    if (f == NULL || temp == NULL) { 
        printf("File error.\n"); 
        return; 
    } 
 
    printf("\nEnter Roll Number to Delete: "); 
    scanf("%d", &roll); 
 
    while (fscanf(f, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) { 
        if (s.roll == roll) { 
            found = 1; 
        } else { 
            fprintf(temp, "%d %s %.2f\n", s.roll, s.name, s.marks); 
        } 
    } 
 
    fclose(f); 
    fclose(temp); 
 
    remove("student.txt"); 
    rename("temp.txt", "student.txt"); 
 
    if (found) 
        printf("Student record deleted.\n"); 
    else 
        printf("Roll number not found.\n"); 
} 
 
// Main menu 
int main() { 
    int choice; 
 
    do { 
        printf("\n===== Student Management System =====\n"); 
        printf("1. Add Student\n"); 
        printf("2. View All Students\n"); 
        printf("3. Search Student by Roll No\n"); 
        printf("4. Delete Student by Roll No\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: addStudent(); break; 
            case 2: viewStudents(); break; 
            case 3: searchStudent(); break; 
            case 4: deleteStudent(); break; 
            case 5: printf("Thank you. Exiting program.\n"); break; 
            default: printf("Invalid choice. Try again.\n"); 
        } 
 
    } while (choice != 5); 
 
return 0; 
} 
