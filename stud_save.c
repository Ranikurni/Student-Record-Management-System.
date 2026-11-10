
#include "student.h"

// Save student records into student.dat
void save_records(struct student *head)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("\nUnable to open file!\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fwrite(&temp->rollno, sizeof(int), 1, fp);
        fwrite(temp->name, sizeof(temp->name), 1, fp);
        fwrite(&temp->percentage, sizeof(float), 1, fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("\nRecords saved successfully!\n");
}

// Load student records from student.dat
void load_records(struct student **head)
{
    FILE *fp;
    struct student *newnode, *temp;

    int roll;
    char name[50];
    float percentage;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo previous records found.\n");
        return;
    }

    while(1)
    {
        if(fread(&roll, sizeof(int), 1, fp) != 1)
            break;

        if(fread(name, sizeof(name), 1, fp) != 1)
            break;

        if(fread(&percentage, sizeof(float), 1, fp) != 1)
            break;

        newnode = malloc(sizeof(struct student));

        if(newnode == NULL)
        {
            printf("\nMemory allocation failed!\n");
            break;
        }

        newnode->rollno = roll;
        strcpy(newnode->name, name);
        newnode->percentage = percentage;
        newnode->next = NULL;

        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            temp = *head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fclose(fp);

    printf("\nStudent records loaded successfully!\n");
}

