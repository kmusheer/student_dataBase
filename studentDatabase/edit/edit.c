#include "../mylib/mylib.h"
#include "../input/input.h"
#include "../main.h"
#include "./edit.h"

// Node *findStudent(Node *head, char *studentId)
// {
//     while (head != NULL)
//     {
//         if (strcmp(head->data.studentId, studentId) == 0)
//         {
//             return head;
//         }
//         head = head->next;
//     }
//     return NULL;
// }
// void updateName(Node *student)
// {
//     char *newName = NULL;
//     do
//     {
//         printf("Enter your full (new) name : ");
//         newName = getString();
//         if (newName[0] != student->data.name[0])
//         {
//             printf("You cannot change the first character of your name.\n");
//             free(newName);
//             continue;
//         }
//         if (!nameValidation(newName))
//         {
//             printf("Invalid name. Try again.\n");
//             free(newName);
//             continue;
//         }
//         free(student->data.name); // free previously allocated memory
//         student->data.name = strdup(newName);
//         free(newName);
//         break;
//     } while (1);
// }
// void updateEmail(Node *student)
// {
//     printf("Enter your (new) email ID : ");
//     free(student->data.emailId); // free previously allocated memory
//     student->data.emailId = getString();
// }
// void updateContact(Node *student)
// {
//     student->data.contactNumber = getOnlyInt("Enter your 10-digit (new) contact number: ");
// }
// void updateDOB(Node *student)
// {
//     printf("Enter your (new) DOB : \n");
//     student->data.birth.date = getDOBInput("Enter your birth date (Day, between 1 and 31) : ", 1, 31);
//     student->data.birth.month = getDOBInput("Enter your birth month (Month, between 1 and 12) : ", 1, 12);
//     student->data.birth.year = getDOBInput("Enter your birth year (e.g., 1999): ", 1900, 2024);
// }
// void updatePercentage(Node *student)
// {
//     printf("Enter your (updated) percentage here : \n");
//     printf("\nEnter your (updated) marks in percentage\n(e.g., enter 7545 for 75.45%%) \n");
//     student->data.percentage.ssc = getFloatInput("Enter your (updated) SSC percentage : ");
//     if (student->data.percentage.preDegreeType == 'D')
//     {
//         student->data.percentage.preDegree.diploma = getFloatInput("Enter your (updated) diploma percentage : ");
//     }
//     else if (student->data.percentage.preDegreeType == 'I')
//     {
//         student->data.percentage.preDegree.inter = getFloatInput("Enter your (updated) Intermediate percentage : ");
//     }
//     student->data.percentage.degree = getFloatInput("Enter your (updated) degree percentage : ");
// }

// void updateDataPrint(Node *student){
//     printHeader();
//     printBody(student);
// }

void Edit(Node *head)
{

    if (head == NULL)
    {
        printf("No existing records edit.\n");
        return;
    }
    char ch, *studentID = NULL;
    Node *student = NULL;

    while (1)
    {
        subMenu();
        printf("Enter your sub menu choice: ");
        ch = getchar();
        clearBuffer();

        if (ch == 'q' || ch == 'Q')
        {
            break;
        }
        if (ch == 'a' || ch == 'A' || ch == 'b' || ch == 'B' || ch == 'c' || ch == 'C' || ch == 'd' || ch == 'D' || ch == 'e' || ch == 'E')
        {
            printf("Enter your student ID : ");
            studentID = getString();
            student = findStudent(head, studentID);
            free(studentID);
            if (!student)
            {
                printf("No record found for the given student ID.\n");
                continue;
            }
        }

        switch (ch)
        {
        case 'a':
        case 'A':
            updateName(student);
            break;
        case 'b':
        case 'B':
            updateEmail(student);
            break;
        case 'c':
        case 'C':
            updateContact(student);
            break;
        case 'd':
        case 'D':
            updateDOB(student);
            break;
        case 'e':
        case 'E':
            updatePercentage(student);
            break;
        case 'p':
        case 'P':
            updateDataPrint(student);
            break;
        default:
            printf("Invalid subMenu choice. Please try again.\n");
        }
    }
}