#ifndef CALCULATOR_H
#define CALCULATOR_H

struct MultipleInput{
    int* myArray;
    int size;
};

struct MultipleInput takeMultipleInput(char*);
double add();
int subtract();
double multiply();
double divide();
int modulus();
double exponent();
void freeMemory(int*);
void exitApp(int*);
char* formatMessage(char*, int);

#endif
