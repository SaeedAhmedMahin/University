// Problem: Exchange the variables a & b without setting a new variable
#include <stdio.h>

int main(){
	int a = 20;
	int b = 30;
	printf("Old values: a=%d and b=%d \n", a, b);
	// Write your code here
	a = a+b; // 50 
	b = a-b; // 20
	a = a-b; // 30
	
	printf("New values: a=%d and b=%d \n", a, b);
}
