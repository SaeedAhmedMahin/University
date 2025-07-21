/* 
Create a function that prints hello 
n times using recursion
*/
#include<stdio.h>
long printHelloNtimes(int n){
    (n-1) && printHelloNtimes(n-1);
    printf("Hello: %d",n);
}
int main(){
    int n;
    scanf("%d" , &n);
    printHelloNtimes(n);
    return 0;
}
