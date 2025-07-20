/* Create a function to 
1. find the population of a region after 5 years 
2. if the government gives everyone a loan with some interest and
   a percentage of people dont pay back what is the net revenue
*/
#include<stdio.h>

// Both functions take percentage values like r=70 

float pop_increase(int n, float br){
	br = br/100;
	return n*(1+br)*(1+br)*(1+br)*(1+br)*(1+br);
}
float revenue(int n, float d, float r, float p){
	d = d/100;
	r=r/100;
	return (n*(1-d)*p*(1+r)-(n*p));
	}	
int main(){
	int n; // number of people
	float d, r, p, br; //defaulter percent, rate, principal, birth rate
	scanf("%d %f %f %f %f", &n, &br, &d, &r, &p);
	float new_pop = pop_increase(n, br);
	float net = revenue(n,d,r,p);
	printf("New Population after 5 years: %f \n", new_pop);
	printf("Net income: %f \n", net);
	return 0;
}

