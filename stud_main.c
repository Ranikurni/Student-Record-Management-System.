
#include "student.h"

int main()
{
    struct student *head = NULL;
    char choice, option;

    // Load saved records
    load_records(&head);

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("A : Add new record\n");
        printf("D : Delete a record\n");
        printf("S : Show the list\n");
        printf("M : Modify a record\n");
        printf("V : Save records\n");
        printf("T : Sort the list\n");
        printf("L : Delete all records\n");
        printf("R : Reverse the list\n");
        printf("E : Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case 'a':
            case 'A':
                add_student(&head);
                break;

            case 'd':
            case 'D':
                delete_student(&head);
                break;

            case 's':
            case 'S':
                show_students(head);
                break;

            case 'm':
            case 'M':
                modify_student(head);
                break;

            case 'v':
            case 'V':
                save_records(head);
                break;

            case 't':
            case 'T':
                sort_students(&head);
                break;

            case 'l':
            case 'L':
                delete_all(&head);
                break;

            case 'r':
            case 'R':
                reverse_list(&head);
                break;

            case 'e':
            case 'E':
                printf("\nS : Save and Exit");
                printf("\nE : Exit without Saving");
                printf("\nEnter your choice: ");
                scanf(" %c", &option);

                if(option == 's' || option == 'S')
                {
                    save_records(head);
                    delete_all(&head);
                    printf("\nSaved and exited successfully.\n");
                    return 0;
                }
                else if(option == 'e' || option == 'E')
                {
                    delete_all(&head);
                    printf("\nExited without saving.\n");
                    return 0;
                }
                else
                {
                    printf("\nInvalid choice!\n");
                }
                break;

            default:
                printf("\nInvalid menu choice!\n");
        }
    }

    return 0;
}

