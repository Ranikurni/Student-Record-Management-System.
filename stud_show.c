
#include "student.h"

void show_students(struct student *head)
{
    struct student *temp;

    // Check whether list is empty
    if(head == NULL)
    {
        printf("\nNo student records available.\n");
        return;
    }

    temp = head;

    printf("\n");
    printf("-----------------------------------------------\n");
    printf("%-12s %-18s %-12s\n",
           "Roll No.", "Name", "Percentage");
    printf("-----------------------------------------------\n");

    // Traverse linked list
    while(temp != NULL)
    {
        printf("%-12d %-18s %-12.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("-----------------------------------------------\n");
}

