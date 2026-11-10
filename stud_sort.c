
#include "student.h"

void sort_students(struct student **head)
{
    struct student *i, *j;
    int choice, temp_roll;
    float temp_percentage;
    char temp_name[50];

    if(*head == NULL || (*head)->next == NULL)
    {
        printf("\nNot enough records to sort!\n");
        return;
    }

    printf("\n1. Sort by Name");
    printf("\n2. Sort by Percentage");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for(i = *head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            int swap = 0;

            if(choice == 1 && strcmp(i->name, j->name) > 0)
                swap = 1;

            else if(choice == 2 && i->percentage < j->percentage)
                swap = 1;

            if(swap)
            {
                temp_roll = i->rollno;
                i->rollno = j->rollno;
                j->rollno = temp_roll;

                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);

                temp_percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = temp_percentage;
            }
        }
    }

    if(choice == 1 || choice == 2)
        printf("\nRecords sorted successfully!\n");
    else
        printf("\nInvalid sorting choice!\n");
}

