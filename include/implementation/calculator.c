#include "../header_files/calculator.h"
#include <stdio.h>
#include <stdlib.h>


char* formatMessage(char* type, int noOfNumbers){
    static char buffer[100] = {};
    if(noOfNumbers == 0)
    sprintf(buffer, "Enter space separated numbers to %s \n", type);
    else
    sprintf(buffer, "Enter space separated with %d numbers to %s \n", noOfNumbers, type);

    return buffer;
}

void freeMemory(int* myArray){
    free(myArray);
}

double add()
{
    struct MultipleInput input = takeMultipleInput(formatMessage("add", 0));
    double sum = 0;
    for (int i = 0; i < input.size; i++) {
        sum += input.myArray[i];
    }
    return sum;
}

int subtract()
{
    struct MultipleInput input = takeMultipleInput(formatMessage("subtract", 2));
    int num1 = input.myArray[0], num2 = input.myArray[1];
    return num1 - num2;
}

double multiply()
{
    struct MultipleInput input = takeMultipleInput(formatMessage("multiple", 0));
    double sum = 1;
    for (int i = 0; i < input.size; i++) {
        sum *= input.myArray[i];
    }
    return sum;
}

struct MultipleInput takeMultipleInput(char* message){
    struct MultipleInput myStruct =  { .myArray = NULL, .size = 0 }; //
    int value;          
    int capacity = 1; 
    
    myStruct.myArray = (int *)malloc(capacity * sizeof(int));
    if (myStruct.myArray == NULL) {
        return myStruct; 
    }
    printf("%s (press Ctrl+D to end input):\n", message);
    while (1) {
        int isInputExist = scanf("%d", &value);
        if(isInputExist <= 0){
            break;
        }
        if (myStruct.size >= capacity) {
            capacity *= 2; 
            myStruct.myArray = (int *)realloc(myStruct.myArray, capacity * sizeof(int));
            if (myStruct.myArray == NULL) {
                return myStruct; 
            }
        }
        myStruct.myArray[myStruct.size++] = value; 
    }
    return myStruct;
}

double divide()
{
    struct MultipleInput input = takeMultipleInput(formatMessage("divide", 2));
    int num1 = input.myArray[0], num2 = input.myArray[1];
    if(num2 <= 0)
        return num2;
    return (double)num1 / num2;
}

int modulus()
{
    struct MultipleInput input = takeMultipleInput(formatMessage("modulus", 2));
    int num1 = input.myArray[0], num2 = input.myArray[1];
    if(num2 <= 0)
        return num2;
    return num1 % num2;
}

double exponent()
{
    struct MultipleInput input = takeMultipleInput(formatMessage("exponent", 2));
    int base = input.myArray[0], pow = input.myArray[1];
    int sum = 1;
    for (int i = 0; i < pow; i++)
    {
        sum *= base;
    }
    return sum;
}

void exitApp(int* isRepeatAgain)
{
    *isRepeatAgain = 0;
}
