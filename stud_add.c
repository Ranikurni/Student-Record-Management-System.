
#include "student.h"

void add_student(struct student **head)
{
    struct student *newnode, *temp;
    int roll = 1, found;

    // Allocate memory dynamically
    newnode = (struct student *)malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    // Find smallest available roll number
    do
    {
        found = 0;
        temp = *head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                roll++;
                break;
            }

            temp = temp->next;
        }

    } while(found);

    newnode->rollno = roll;

    printf("\nEnter student name: ");
    scanf(" %49[^\n]", newnode->name);

    // Validate percentage
    while(1)
    {
        printf("Enter percentage: ");

        if(scanf("%f", &newnode->percentage) != 1)
        {
            printf("Invalid input! Enter a number.\n");

            while(getchar() != '\n');
            continue;
        }

        if(newnode->percentage >= 0 &&
           newnode->percentage <= 100)
        {
            break;
        }

        printf("Percentage must be between 0 and 100.\n");
    }

    newnode->next = NULL;

    // Insert node into linked list
    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nStudent record added successfully!\n");
    printf("Assigned Roll Number: %d\n", roll);
}

