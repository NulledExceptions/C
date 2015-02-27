/*
File: primeList.c

Purpose: Find all the prime numbers before the number inputed by the user.

Input: n
Output: List of primes up to and including the user input.  Output variable =i.

Compile: gcc -g -Wall -o primeListBin primeList.c -lm

Usage: ./primeListBin


 */


#include <stdio.h>
#include <math.h>
int PrimeSearch(int i); /* Function that checks for Primes */

int main(void){

  int n,i, x; /* n is the user input, i is the variable iterated, x calls the function and catches the return value*/
  
  printf("Enter a number greater than 2:\n");
  scanf("%d", &n);
  printf("The list of primes before and including your number are:\n");
  

  for(i=2; i <= n; i++){ /* Iterates 'i' until it is less then the user input 'n'*/
    
    x = PrimeSearch(i);  /* Runs PrimeSearch Function */
    if(x==1){    /*If counter is returned true, the prime is printed */
      printf("%d,",i);
    
    
  }
  
  }
  
  return 0;
  }


/*------------------------------------------------------------------
Function: PrimeSearch
Purpose: To check each number up to the user input, and determine whether it is a prime number.

Input Arguments: i: Iterates every number up to (user input +1).

Return Value : 1= True, the number is prime.
	       0= False, the number is not prime.

*/


int PrimeSearch(int i){
  int  g, squareTest, counter;
  double squareofi;   /* Stores the square root of i*/
    squareofi = sqrt(i);
  
    
  
     counter =0;  /* counter that changes to 1 if 'i' is not prime*/
     
     
     
     
     for(g=2; g <= squareofi; g++){    /*loops through each number up to the square root of i */
       
       squareTest = i % g;    /*Finds remainder of i divided by g */
      
       if(squareTest == 0){   /* If squareTest =0, then it is not prime*/
	 
	 g=squareofi +1; /* Breaks out of the loop*/
	 counter =1;  /*Changes the counter to return a false value */
	 
       }
       
      
       }
        if(counter == 0){  /* Checks counter*/
	 return 1;  /* Returns true*/
	
	}
	 else {
	  return 0;  /* returns false*/
	}
  
  
  
  
  
  
  }
  


