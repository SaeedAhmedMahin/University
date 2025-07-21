/* 
Create a function that simulates the
the factorial operator using recursion
*/
#include<stdio.h>
long factorial (long a){
    if( a==1){
        return a;
    }
    return a*factorial((a-1));
}
int main(){
    long a,fac;
    scanf("%ld" , &a);
    fac = factorial(a);
    printf("factorial of %ld is %ld", a,fac);
    return 0;
}
