/**********************************************************************/
/*** sigmoid.c:  This code contains the function routine            ***/
/***             sigmoid() which performs the unipolar sigmoid      ***/
/***             function for backpropagation neural computation.   ***/
/***             Accepts the input value x then returns it's        ***/
/***             sigmoid value in float.                            ***/
/***                                                                ***/
/***  function usage:                                               ***/
/***       float sigmoid(float x);                                  ***/
/***           x:  Input value                                      ***/
/***                                                                ***/
/***  Written by:  Kiyoshi Kawaguchi                                ***/
/***               Electrical and Computer Engineering              ***/
/***               University of Texas at El Paso                   ***/
/***  Last update:  09/28/99  for version 2.0 of BP-XOR program     ***/
/**********************************************************************/

#include <math.h>
#include <stdio.h>

float sigmoid(float x)
{
     float exp_value;
     float return_value;

     /*** Exponential calculation ***/
     exp_value = exp((double) -x);

     /*** Final sigmoid value ***/
     return_value = 1 / (1 + exp_value);

     return return_value;
}

int main(){
    printf("sigmoid(%.2f): %.2f\n", 0.0f, sigmoid(0.0f));
    printf("sigmoid(%.2f): %.2f\n", 1.0f, sigmoid(1.0f));
    printf("sigmoid(%.2f): %.2f\n", -1.0f, sigmoid(-1.0f));
    printf("sigmoid(%.2f): %.2f\n", 10000.0f, sigmoid(10000.0f));
    return 0;
}

/*
sigmoid(0.00): 0.50
sigmoid(1.00): 0.73
sigmoid(-1.00): 0.27
sigmoid(10000.00): 1.00
*/
