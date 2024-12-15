#include "../mylib/mylib.h"
#include "../input/input.h"
#include "./delete.h"

void Delete(Node **head) // double pointer required because if head node is deleted then change head
{
    if (*head == NULL)
    {
        printf("No data to delete.\n");
        return;
    }
    char *studID = NULL;
    printf("Enter student ID to Delete : ");
    studID = getString();
    int found = 0;
    Node *temp = *head, *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->data.studentId, studID) == 0)
        {
            found = 1;
            if (prev == NULL)
            { // delete head node
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
                if (temp->next == NULL)
                { // for last node
                    prev->next = NULL;
                }
            }
            free(temp->data.name);
            free(temp->data.emailId);
            free(temp->data.studentId);
            free(temp);

            printf("student record deleted successfully!\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found)
    {
        printf("No matching record found for the given student ID : %s.\n", studID);
    }
    free(studID);
}