// Problem: Exchange the variables a & b using bitwise process
#include <stdio.h>

int main(){
	int a = 20;
	int b = 30;
	printf("Old values: a=%d and b=%d \n", a, b);
	// Write your code here
	a = a^b;
	b = a^b;
	a = a^b;
	
	printf("New values: a=%d and b=%d \n", a, b);
}
