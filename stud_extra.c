
#include "student.h"

// Delete all student records
void delete_all(struct student **head)
{
    struct student *temp;

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    printf("\nAll student records deleted!\n");
}

// Reverse the linked list
void reverse_list(struct student **head)
{
    struct student *prev = NULL;
    struct student *current = *head;
    struct student *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    printf("\nStudent list reversed successfully!\n");
}

