#include "../mylib/mylib.h"
#include "../input/input.h"
#include "./file.h"

void sync(Node **head)
{
    FILE *fptr = fopen("./studentDB.txt", "r");
    if (!fptr)
    {
        printf("Error: Could not read file.\n");
        return;
    }

    char name[20], studentID[15], email[20];
    unsigned long int contactNumber;
    unsigned int date, month, year;
    float ssc, preDegree, degree;
    char preDegreeType;

    // while (fscanf(fptr, "%s %s %s %lu %u %u %u %f %c %f %f", name, studentID, email, &contactNumber, &date, &month, &year, &ssc, &preDegreeType, &preDegree, &degree) != EOF)
    while (fscanf(fptr, "%s %s %s %lu %u %u %u %f %c %f %f", name, studentID, email, &contactNumber, &date, &month, &year, &ssc, &preDegreeType, &preDegree, &degree) == 11)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(!newNode){
            printf("Memory allocation failed!\n");
            fclose(fptr);
            return;
        }
        // newNode->data.name = strdup(name);
        newNode->data.name = malloc(strlen(name) + 1);          //assign dynamic memory
        strcpy(newNode->data.name, name);                       // copy data

        newNode->data.studentId = strdup(studentID);
        newNode->data.emailId = strdup(email);
        newNode->data.contactNumber = contactNumber;
        newNode->data.birth.date = date;
        newNode->data.birth.month = month;
        newNode->data.birth.year = year;
        newNode->data.percentage.ssc = ssc;
        newNode->data.percentage.preDegreeType = preDegreeType;
        if (preDegreeType == 'D')
        {
            newNode->data.percentage.preDegree.diploma = preDegree;
        }
        else
            newNode->data.percentage.preDegree.inter = preDegree;
        newNode->data.percentage.degree = degree;

        appendNode(head,newNode);
        generateID(name);
    }
    fclose(fptr);
}