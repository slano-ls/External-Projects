#include <stdio.h>
#include <math.h>

int main (){
int Lorentz_Factor; // The Initialization of our Lorentz Factor
int C=299792458; // We are defining the constant (speed of light) with the variable C
int time,velocity,position1,position2;

// First Person Input
printf("Enter Your Position> ");
scanf("%d", &position1);
getchar();
printf("Enter Your Second Position> ");
scanf("%d", &position2);
getchar();
printf("Enter Your Velocity> ");
scanf("%d", &velocity);
getchar();
printf("Enter Your Time> ");
scanf("%d", &time);
getchar();

// Second Person Input
int sposition1, sposition2, svelocity, stime;
printf("Enter Your Position> ");
scanf("%d", &sposition1);
getchar();
printf("Enter Your Second Position> ");
scanf("%d", &sposition2);
getchar();
printf("Enter Your Velocity> ");
scanf("%d", &svelocity);
getchar();
printf("Enter Your Time> ");
scanf("%d", &stime);
getchar();

// First Person Calculation
int f_p_calculation_2;

f_p_calculation_2=(1/(sqrt(1-(velocity/C))));

int l;
int t_prime;
l=f_p_calculation_2;
t_prime=l*(time-((velocity*(position2-position1))/(C*C)));

printf("%d", t_prime);
}




