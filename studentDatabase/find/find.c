#include "../mylib/mylib.h"
#include "../input/input.h"
#include "../print/print.h"
#include "../main.h"

void Find(Node *head)
{
    int flag = 0;
    if (head == NULL)
    {
        printf("No records to display.\n");
        return;
    }
    char *student = NULL, ch;
OPTION:
    printf("Enter 'a' if you want to search by name or 'b' for studentId : ");
    ch = getchar();
    clearBuffer();

    Node *temp = head;
    if (ch == 'a')
    {
        printf("Enter your name : ");
        student = getString();

        while (temp != NULL)
        {
            if (strcmp(temp->data.name, student) == 0)
            {
                if (!flag)
                {
                    printf("\n--- Search Results ---\n");
                    printHeader(); // Print table header
                    flag = 1;
                }
                printBody(temp);
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("No records found with the name '%s'.\n", student);
        }
    }
    else if (ch == 'b')
    {
        printf("Enter your vector student ID : ");
        student = getString();

        while (temp != NULL)
        {
            if (strcmp(temp->data.studentId, student) == 0)
            {
                if (!flag)
                {
                    printf("\n--- Search Results ---\n");
                    printHeader(); // Print table header
                    flag = 1;
                }
                printBody(temp);
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("No records found with the student ID '%s'.\n", student);
        }
    }
    else
    {
        printf("Invalid input! Please enter 'a', 'b'.\n");
        goto OPTION;
    }
    free(student); // Free the dynamically allocated string
    student = NULL;
}