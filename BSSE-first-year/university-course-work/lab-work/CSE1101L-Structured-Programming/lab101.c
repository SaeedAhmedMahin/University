// Problem: Exchange the variables a & b 
#include <stdio.h>

int main(){
	int a = 20;
	int b = 30;
	printf("Old values: a=%d and b=%d \n", a, b);
	// Write your code here
	int c = a;
	a = b;
	b = c;
	printf("New values: a=%d and b=%d \n", a, b);
}
