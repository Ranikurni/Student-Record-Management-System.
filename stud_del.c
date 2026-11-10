
#include "student.h"

// Function to delete using roll number
void delete_by_roll(struct student **head, int roll)
{
    struct student *temp, *prev;

    temp = *head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->rollno == roll)
        {
            if(prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("\nRecord deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nStudent record not found!\n");
}

void delete_student(struct student **head)
{
    struct student *temp;
    char choice;
    char name[50];
    int roll, found = 0;

    if(*head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nR : Delete by roll number");
    printf("\nN : Delete by name");
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    if(choice == 'r' || choice == 'R')
    {
        printf("\nEnter roll number: ");
        scanf("%d", &roll);

        delete_by_roll(head, roll);
    }
    else if(choice == 'n' || choice == 'N')
    {
        printf("\nEnter student name: ");
        scanf(" %49[^\n]", name);

        temp = *head;

        printf("\nMatching student records:\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll No: %d  Name: %s\n",
                       temp->rollno, temp->name);
                found = 1;
            }

            temp = temp->next;
        }

        if(found == 0)
        {
            printf("\nStudent name not found!\n");
            return;
        }

        printf("\nEnter roll number to delete: ");
        scanf("%d", &roll);

        // Verify selected roll belongs to the name
        temp = *head;
        found = 0;

        while(temp != NULL)
        {
            if(temp->rollno == roll &&
               strcmp(temp->name, name) == 0)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found)
            delete_by_roll(head, roll);
        else
            printf("\nInvalid roll number for this name!\n");
    }
    else
    {
        printf("\nInvalid choice!\n");
    }
}

