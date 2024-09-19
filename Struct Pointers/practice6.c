#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to print the contents of the dynamic array using a void pointer
void printArray(void* arr, int size, int numElements) {
    struct Employee* empArr = (struct Employee*) arr;
    for (int i = 0; i < numElements; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", 
               empArr[i].id, empArr[i].name, empArr[i].salary);
    }
}

int main() {
    int numEmployees;
    struct Employee* employees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    // Dynamically allocate memory for the array of structures
    employees = (struct Employee*) malloc(numEmployees * sizeof(struct Employee));

    // Error handling for memory allocation failure
    if (employees == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Indicate an error occurred
    }

    // Get employee details from the user
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &(employees[i].id));

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Salary: ");
        scanf("%f", &(employees[i].salary));
    }

    // Print the employee details using the void pointer function
    printf("\nEmployee Details:\n");
    printArray(employees, sizeof(struct Employee), numEmployees);

    // Free the allocated memory to prevent memory leaks
    free(employees);

    return 0;
}