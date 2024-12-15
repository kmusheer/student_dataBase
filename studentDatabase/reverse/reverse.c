#include "../mylib/mylib.h"
#include "../delete/delete.h"
#include "../print/print.h"

void Reverse(Node *head)
{
    if (head == NULL)
    {
        printf("No data to reverse or display.\n");
        return;
    }

    Node *temp = head;
    Node *stack[dataCount];            //in this stack to store all data using dataCount in generateID
    int top = -1;


    while (temp != NULL)
    {
        stack[++top] = temp;            //Insert/Push data into stack

        temp = temp->next;
    }
    printf("\n--- All Student Records in reverse order ---\n");

    printHeader();
    while (top >= 0)
    {
        printBody(stack[top--]);
    }
}



//another way to use Recursion

