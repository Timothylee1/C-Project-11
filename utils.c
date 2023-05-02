/*!
@file       utils.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Laboratory 7
@Laboratory Working with pointers   
@date       29/10/2021
@brief      This file contains code for definitions of functions read_total_count(void), 
            read_3_numbers(int*, int*, int*), swap(int*, int*), sort_3_numbers(int*, int*, 
            int*), and maintain_3_largest(int, int*, int*, int*). The function main() uses
            the aforementioned functions to sort and maintain the top 3 largest integers 
            based on an input sequence provided by the user.
            E.g. 
            Input sequence by user: 1 -5 3 6 
            Output sequence: 6, 3, 1
*//*______________________________________________________________________________________*/
#include <stdio.h> //for printf & scanf
#include <stdlib.h> //for exit function

/*!
@brief  This function read_total_count() contains code to that reads an integer value from 
        the user and tests if the value is less than 3. If it is, it prints out to text to 
        the standard output and terminates the program by calling the function exit(). If 
        the value is more than or equals to 3, it returns the value to the function main().

@param  integer as an unsigned long int data type
		
@return Returns an unsigned long int value
*//*_______________________________________________________________________________________*/
size_t read_total_count(void) {

    printf("Please enter the number of integers: ");
    
    unsigned long int integer; //data type for size_t
    scanf("%lu", &integer);
    if (integer < 3){
        printf("There is no third largest number.\n");    
        exit (EXIT_SUCCESS); //or exit (0); is a normal termination
    } 
    else
    return integer;
}

/*!
@brief  This function read_3_numbers() contains code to perform a simple task of reading 3
        integers from the user and initializes the objects pointed by the function 
        parameters. Thus, allowing for side effect output.

@param  first, second, third are declared as a pointer to an integer 
		
@return Returns nothing
*//*_______________________________________________________________________________________*/
void read_3_numbers(int* first, int* second, int* third) {

//first second third are pointing to respective addresses of 
//variables declared in main(), hence, no need & in this scanf
    scanf("%d %d %d", first, second, third);
}

/*!
@brief  This function swap() contains code that exchanges the values of the left-hand side 
        object indicated by lhs and the righ-hand side object indicated by rhs.

@param  lhs, rhs are declared as a pointer to an integer
        temp is declared as an integer
		
@return Returns nothing
*//*_______________________________________________________________________________________*/
void swap(int* lhs, int* rhs){
    int temp = *lhs; //temp gets assigned the value that lhs is pointing to
    *lhs = *rhs; //assigns *lhs the value *rhs is pointing to
    *rhs = temp; //assigns *rhs the value *lhs was pointing to
}

/*!
@brief  This function sort_3_numbers() contains code that sorts the values of integer 
        objects indicated by the function pointer parameters. The function then assigns the 
        value in the memory location to indicate the largest value in the object indicated 
        by first and second largest by second and third largest by third.

@param  first, second, third are declared as a pointer to an integer
        one, two, three are delcared as an interger
		
@return Returns nothing
*//*_______________________________________________________________________________________*/
void sort_3_numbers(int* first, int* second, int* third){

    //assign variables to hold the values the int pointers are
    //pointing to
    int one = *first, two = *second, three = *third;
    if(one > two && one > three) {
        *first = one;
        if (two > three) {
           *second = two;
            *third = three;
        } else {   
            *second = three;
            *third = two; 
        }
    }
    else if (two > one && two > three) {
        *first = two;
        if (three > one) {
            *second = three;
            *third = one;
        } else  {  
            *second = one;
            *third = three;
        }
    }
    else if (three > one && three > two) {
        *first = three;
        if (two > one) {
            *second = two;
            *third = one;
        } else  {  
            *second = one;
            *third = two;
        }
    }
}

/*!
@brief  This function maintain_3_largest() contains code assumes that objects indicated by 
        first, second, and third have been already sorted and that a new value under the 
        function parameter, number, is inserted. This function then reassess the values and 
        sorts them to maintain the top 3 largest integer values, and in the process, 
        discarding the fourth, uncessassary value.

@param  first, second, third are declared as a pointer to an integer
        one, two, three, number are delcared as an interger
		
@return Returns nothing
*//*_______________________________________________________________________________________*/
void maintain_3_largest(int number, int* first, int* second, int* third){
    //assign variables to hold the values the int pointers are
    //pointing to
    int one = *first, two = *second, three = *third;

    //Largest is one
    if(one > two && one > three && one > number) {
        *first = one;
        //2nd Largest is two 
        if (two > three && two > number) {
           *second = two;
           //3rd Largest is three or number 
           *third = three > number ? three : number;
        } 
        //2nd Largest is three
        else if (three > two && three > number) {
           *second = three;
           //3rd Largest is two or number
           *third = two > number ? two : number;
        } 
        //2nd Largest is number 
        else if (number > two && number > three) {
           *second = number;
           //3rd Largest is two or three
           *third = two > three ? two : three;
        }
    } //Largest is two
    else if(two > one && two > three && two > number) {
        *first = two;
        //2nd Largest is one 
        if (one > three && one > number) {
           *second = one;
           //3rd Largest is three or number 
           *third = three > number ? three : number;
        } 
        //2nd Largest is three
        else if (three > one && three > number) {
           *second = three;
           //3rd Largest is one or number
           *third = one > number ? one : number;
        } 
        //2nd Largest is number 
        else if (number > one && number > three) {
           *second = number;
           //3rd Largest is one or three
           *third = one > three ? one : three;
        }
    }//Largest is three
    else if(three > two && three > one && three > number) {
        *first = three;
        //2nd Largest is one 
        if (one > two && one > number) {
           *second = one;
           //3rd Largest is two or number 
           *third = two > number ? two : number;
        } 
        //2nd Largest is two
        else if (two > one && two > number) {
           *second = two;
           //3rd Largest is one or number
           *third = one > number ? one : number;
        } 
        //2nd Largest is number 
        else if (number > two && number > one) {
           *second = number;
           //3rd Largest is two or one
           *third = two > one ? two : one;
        }
    }//Largest number
    else if(number > two && number > three && number > one) {
        *first = number;
        //2nd Largest is two 
        if (two > three && two > one) {
           *second = two;
           //3rd Largest is three or one 
           *third = three > one ? three : one;
        } 
        //2nd Largest is three
        else if (three > two && three > one) {
           *second = three;
           //3rd Largest is two or one
           *third = two > one ? two : one;
        } 
        //2nd Largest is one
        else if (one > two && one > three) {
           *second = one;
           //3rd Largest is two or three
           *third = two > three ? two : three;
        }
    }
}
