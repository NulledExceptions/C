/*

File: bisection.c

Author: Mark Marnell

Purpose: Implements the bisection method for finding a solution to the equation f(x)=0

Inputs:  a, b, maxTol, maxIteration

Outputs:  approxSolution, f(approxSolution) *function value of approximate solution*, iters 

Compile: gcc -g - Wall -o bisection bisection.c -lm

Note: All your base are belong to us

Usage:  Tests the minimum value (a) and the maximum value (b) to find solutions to f(x) = 0.  		The minimum and maximum guesses are then havled and tested again to find f(x) = 0 		within the given tolerance.  This is done maxIteration number of times, or until the 		the solution is found within the given tolerance.


*/




#include <stdio.h>  //imports input and output headers
#include <math.h>  //imports the math headers for calculating absolute values


//function declaration for later use
double Bisection(double a, double b, double maxTol, int maxIteration); 
double f(double x);

/*--------------------------------------------------------------------------*/

int main() {
	
	
	double a, b, maxTol, approxSolution; //initialize variables for inputs, 
	int maxIteration;		     // calculation, and ouputs
	

	printf("Enter the left value (approximate minimum) of the function: ");
	scanf("%lf", &a);
	
	printf("Enter the right value (approximate maximum of the function: ");
	scanf("%lf", &b);

	
	printf("Enter the number of iterations: ");
	scanf("%d",&maxIteration);
	
	printf("Enter the max tolerance: ");
	scanf("%lf", &maxTol);

	

	if ((f(a) *f(b)) >0){  			          // Checks if f(x) = 0 is within 
		printf("Error: Your minimum and your  "); // minimum and maximum values
		printf("maximum values are incorrect!\n");
		return 0;  				//If not, alerts user and quits
	}else if(f(a) == 0) {				
		printf("Solution is : %lf", a);		//if f(x)=0 at a,
		return 0;				//alerts user and quits
	}else if (f(b) == 0) {
		printf("The solution is : %lf", b);  //if f(x)=0 at b,
		return 0;			     //alerts user and quits
	}   


	// Calls Bisection function passing a, b, maxTol, and 
	// maxIteration respectively and catches the return value 
	// with variable approxSolution

	approxSolution = Bisection(a,b,maxTol,maxIteration);   
	printf("The approximate solution is: %lf\n", approxSolution);  // Prints the 
									//approx. Solution
	printf("The function value at the approximate ");
	printf("solution is: %lf\n",f(approxSolution)); // Prints the function 
							// value at approximate solution
	


return 0;  // returns 0 for error checking in main function

} //end of main 


/*------------------------------------------------------------*/


// Function:   f
// Purpose:    The math function which we are finding the 
//             approximate solution for.
// Input arg:  x
// Return val: x 


double f(double x) {
			// Multiplies x by x and subtracts 2.  
	x = x*x -2;  	// This is a hardwired func (x^2)-2
	return x;  //Modified value x is then returned
	
	} //End of function f


/*------------------------------------------------------------*/


// Function:   Bisection
// Purpose:   The function takes the midpoint of a and b and then checks 
//	      if it equals 0. If it does not equal 0, it then checks 
//	      whether to replace b with m, or a with m.
//            This runs until iters is equal to maxIteration and the absolute value 
//            of b-a is less then the maxtolerance.  Or until the solution f(m) = 0 
//	      is satisfied.
//
// Input arg:  a, b, maxTol, maxIteration, m
// Return val: m (which is the approximate solution)


double Bisection(double a, double b, double maxTol, int maxIteration){
	int iters = 0;  //initializes variables
	double m;

	while (iters < maxIteration && fabs(b-a) > maxTol){  //checks conditions to run

		iters ++;             //iterates iters
		m = (a + b) / 2;     // finds the midpoint of a and b

		if (f(m) == 0) {     // stops running if f(m) =0 i.e.the solution is found
			break;
		}
		else if (f(m)*f(a) < 0) {  //checks which variable to replace with m
			b = m;
		} else { 
			a = m;
		}

	}
	
	printf("Solution: \n");    
	printf("The number of iterations is: %d\n",iters);  //prints the number of iterations
	
	if (iters < maxIteration) {     //checks whether the function converged over interval
		printf("The function converged.\n");     // prints whether conversion occured
	}else {
		printf("The function did not converge.\n");
	}

return m;  //returns the solution, m
} //End of Bisection
	


