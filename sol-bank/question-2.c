/* There are ‘n’ different employees working for an organization. Each employees
possesses the following characteristics. Name, eid, department and salary. Perform the
following set of operations to create and maintain the employees database using
dynamic memory allocation techniques in C.
i. Store the employee details in the ascending order of the eid.
ii. Search an employee and print his/her details based on the eid.
iii. Search and delete an employee details based on eid.
iv. Display the details of all the employees in the table format. */

/* Code: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure for employee
struct employee {
    char name[50];
    int eid;
    char department[50];
    int salary;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // allocate memory for an array of n employee structures
    struct employee *employees = (struct employee*)malloc(n * sizeof(struct employee));

    // get the details of the employees
    printf("Enter the details of the employees:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("EID: ");
        scanf("%d", &employees[i].eid);
        printf("Department: ");
        scanf("%s", employees[i].department);
        printf("Salary: ");
        scanf("%d", &employees[i].salary);
    }

    // sort the employees in ascending order of eid using insertion sort algorithm
    for (int i = 1; i < n; i++) {
        struct employee key = employees[i];
        int j = i - 1;
        while (j >= 0 && employees[j].eid > key.eid) {
            employees[j+1] = employees[j];
            j = j - 1;
        }
        employees[j+1] = key;
    }

    // search an employee and print his/her details based on eid
    int search_eid;
    printf("Enter the EID to search: ");
    scanf("%d", &search_eid);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].eid == search_eid) {
            printf("Employee details:\n");
            printf("Name: %s\n", employees[i].name);
            printf("EID: %d\n", employees[i].eid);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: %d\n", employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with EID %d not found.\n", search_eid);
    }

    // search and delete an employee details based on eid
    int delete_eid;
    printf("Enter the EID to delete: ");
    scanf("%d", &delete_eid);
    int delete_index = -1;
    for (int i = 0; i < n; i++) {
        if (employees[i].eid == delete_eid) {
            delete_index = i;
            break;
        }
    }
    if (delete_index == -1) {
        printf("Employee with EID %d not found.\n", delete_eid);
    } else {
        for (int i = delete_index; i < n-1; i++) {
            employees[i] = employees[i+1];
        }
        n--;
        printf("Employee with EID %d deleted successfully.\n", delete_eid);
    }

    // display the details of all the employees in the table format
    printf("\nDetails of all employees:\n");
    printf("+------+---------------------+-------------+----------+\n");
    printf("| EID  | Name                | Department  | Salary   |\n");
    printf("+------+---------------------+-------------+----------+\n");
    for (int i = 0; i < n; i++) {
          printf("| %-4d | %-20s | %-11s | %8d |\n", employees[i].eid, employees[i].name, employees[i].department, employees[i].salary);
    }
    printf("+------+---------------------+-------------+----------+\n");

    // free the dynamically allocated memory
    free(employees);
return 0;
}
