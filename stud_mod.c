
#include "student.h"

// Function to update student details
void update_record(struct student *temp)
{
    printf("\nCurrent Student Details:\n");
    printf("Roll Number : %d\n", temp->rollno);
    printf("Name        : %s\n", temp->name);
    printf("Percentage  : %.2f\n", temp->percentage);

    printf("\nEnter new name: ");
    scanf(" %49[^\n]", temp->name);

    while(1)
    {
        printf("Enter new percentage: ");

        if(scanf("%f", &temp->percentage) != 1)
        {
            printf("Invalid input! Enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        if(temp->percentage >= 0 &&
           temp->percentage <= 100)
            break;

        printf("Percentage must be between 0 and 100.\n");
    }

    printf("\nRecord modified successfully!\n");
}

void modify_student(struct student *head)
{
    struct student *temp;
    char choice, name[50];
    int roll, found = 0;
    float percentage;

    if(head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nR : Search by roll number");
    printf("\nN : Search by name");
    printf("\nP : Search by percentage");

    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    // Search by roll number
    if(choice == 'r' || choice == 'R')
    {
        printf("\nEnter roll number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                update_record(temp);
                return;
            }

            temp = temp->next;
        }

        printf("\nStudent record not found!\n");
    }

    // Search by name
    else if(choice == 'n' || choice == 'N')
    {
        printf("\nEnter student name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("\nRoll No: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name,
                       temp->percentage);
                found = 1;
            }

            temp = temp->next;
        }

        if(!found)
        {
            printf("\nStudent name not found!\n");
            return;
        }

        printf("\nEnter roll number to modify: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               strcmp(temp->name, name) == 0)
            {
                update_record(temp);
                return;
            }

            temp = temp->next;
        }

        printf("\nInvalid roll number for this name!\n");
    }

    // Search by percentage
    else if(choice == 'p' || choice == 'P')
    {
        printf("\nEnter percentage: ");
        scanf("%f", &percentage);

        temp = head;

        while(temp != NULL)
        {
            if(temp->percentage == percentage)
            {
                printf("\nRoll No: %d  Name: %s  Percentage: %.2f\n",
                       temp->rollno, temp->name,
                       temp->percentage);
                found = 1;
            }

            temp = temp->next;
        }

        if(!found)
        {
            printf("\nPercentage not found!\n");
            return;
        }

        printf("\nEnter roll number to modify: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               temp->percentage == percentage)
            {
                update_record(temp);
                return;
            }

            temp = temp->next;
        }

        printf("\nInvalid roll number for this percentage!\n");
    }

    else
    {
        printf("\nInvalid choice!\n");
    }
}

