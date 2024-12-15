#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MARKS_MIN 100
#define MARKS_MAX 10000

extern int dataCount;

typedef struct
{
    unsigned int date : 5;  // 11111 = 31 and date 0-31
    unsigned int month : 4; // 1111  = 15 and mnth 0-12
    unsigned int year : 12;
} DOB;

typedef union
{
    float inter;
    float diploma;
} sscPlus;

typedef struct
{
    float ssc;
    sscPlus preDegree;
    float degree;
    char preDegreeType; // flag for printing 'a' for diploma, 'b' for Intermediate because union use/share same memory location then it's overwrite
} marks;

typedef struct student_Record
{
    char *name;
    char *emailId;
    char *studentId;
    unsigned long int contactNumber;
    DOB birth;
    marks percentage;
} stud;

typedef struct Node
{
    stud data;
    struct Node *next;
} Node;

// void menu();
// void subMenu();
// void clearBuffer();
// char *getString();
// int getOnlyInt(char *);
// int getDOBInput(char *, unsigned int, unsigned int);
// float getFloatInput(char *);
// char *generateID(char *);
// void appendNode(Node **, Node *);
// void printHeader();
// void printBody(Node *);
// int nameValidation(char *);

// void sync(Node **);
// void Input(Node **);
// void Print(Node *);
// void Find(Node *);
// void Save(Node *);
// void Edit(Node *);
// void Delete(Node **head);
// void Reverse(Node *head);

// // all about edit or update

// Node *findStudent(Node *, char *);
// void updateName(Node *);
// void updateEmail(Node *);
// void updateContact(Node *);
// void updateDOB(Node *);
// void updatePercentage(Node *);
// void updateDataPrint(Node *);

#endif
