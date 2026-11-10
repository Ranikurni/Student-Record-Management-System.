
#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student structure
struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

// Function declarations
void add_student(struct student **head);

void delete_student(struct student **head);

void show_students(struct student *head);

void modify_student(struct student *head);

void save_records(struct student *head);

void load_records(struct student **head);

void sort_students(struct student **head);

void reverse_list(struct student **head);

void delete_all(struct student **head);

#endif

