/****************** Usage: For finding the real roots of any given Transcendental equation. ****************************/

/********************* Specification: The program takes three approximate root values of the interval as the input and computes the root for the given equation using Muller's method ***********************/

/*************** Given Equation: 2x-log(x)-7 = 0 **************/
/*************** Roots is: 3.798224 ***************/

/*************** In this method, f(x) is approximated by a second degree curve in the vicinity of
a root. The roots of the quadratic are then assumed to be the approximations to
the roots of the equation f(x) = 0.
The method is iterative, converges almost quadratically, and can be used
to obtain complex roots.  **************************/

/*************** PROGRAM STARTS HERE ***************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* FUNCTION DECLARATION *********/
void muller1(float a, float b, float c);
float function(float val);
void check_bound(float a, float b, float c);

/********** MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   float         a, b, c;  //Declaration of variables in float

   if (argc != 4)  //Verification of arguments
   {
      fprintf(stderr, "Usage: %s <x_(k-2)> <x_(k-1)> <x_k>\n", argv[0]);
      exit(1);
   }

   a = atof(argv[1]);  //Converting arguments
   b = atof(argv[2]);  //Converting arguments
   c = atof(argv[3]);  //Converting arguments

   if ((a <= 0) || (b <= 0) || (c <= 0))
   {
      printf("log(0) is undefined so give a value which is other than zero\n");
      exit(2);
   }

   check_bound(a, b, c);  //Calling Function

   printf("By using Muller's method: \n");
   printf("The equation is: \n");
   printf("\t");
   printf("f(x) = 2x-log(x) -7\n");

   printf("------------------------------\n");
   printf("    f(a)     f(b)      f(c)\n");
   printf("------------------------------\n");

   muller1(a, b, c); //Calling Function

   exit(0);
}

void muller1(float a, float b, float c)
{
   float        h_b, h_c, lamk, sigk, gk, ck, lamda, lamda1;
   float        fa, fb, fc, val, val1, xk, i = 0;

   h_c = (c - b), h_b = (b - a), lamk = h_c/h_b, sigk = lamk + 1;

   while (i < 10)
   {
      fa = function(a);  //Calling Functions
      fb = function(b);  //Calling Functions
      fc = function(c);  //Calling Functions
      printf("%.5f    %.5f    %.5f\n", fa, fb, fc);

      gk = ((lamk*lamk*fa)-(sigk*sigk*fb)+((lamk+sigk)*fc));  //Value of gk
      ck = lamk*(((lamk*fa)-(sigk*fb)+fc));  //Value of ck

      val = (gk*gk - 4*sigk*ck*fc);
      val1 = sqrtf(val);

      lamda = (-2)*sigk*fc / (gk-val1);  //Value of lamda1
      lamda1 = (-2)*sigk*fc / (gk+val1);  //Value of lamda2

      if (floor(gk*10000) == floor(val1*10000)) //Comparing the gk and val1
      {
         printf("The given root is %f after %.1f iterations\n", c, i);
         break;  //Getting out of the loop
      }

      if (lamda1 > lamda)
      {
         lamda = lamda1;
      }

      xk = c + lamda*(c-b);

      if (isnan(xk))  //Checking whether xk is -nan or not
      {
         printf("The given root is %f after %.1f iterations\n", c, i);
         break;  //Getting out of the loop
      }
      xk = -xk;
      if (isnan(xk))  //Checking whether xk is -nan or not
      {
         printf("The given root is %f after %.1f iterations\n", c, i);
         break;  //Getting out of the loop
      }
      else
      {
         xk = -xk;
      }

      if (floor(c*10000) == floor(xk*10000)) //Comparing the roots
      {
         printf("The given root is %f after %.1f iterations\n", c, i);
         break;  //Getting out of the loop
      }

      a = b;
      b = c;
      c = xk;

      i++;  //Incrementing i
   }

   return ;
}

float function(float val)
{
   float        fx, x = val;  //Declaration of variables in float

   fx = 2 * x - log10f(x) - 7;  // Function Equation

   if(x != x)
   {
      printf("Roots are almost equal can't go further.\n");
      exit (2);
   }
   return fx;  //Returning the value of f(x) at x1
}

void check_bound(float a, float b, float c)
{
   float        fa, fb, fc;  //Declaration of variables in float

   fa = function(a);  //Calling Functions
   fb = function(b);  //Calling Functions
   fc = function(c);  //Calling Functions

   if ((fa * fb * fc) == 0)  //Check condition
   {
      printf("The root is one of the boundaries.\n");
      exit(0);
   }

   return ;
}
