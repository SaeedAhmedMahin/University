/*
Solve the following problems,

1. Create a function that takes in integer value n and produces a pyramid of n lines like:
  *
 ***
*****
2. Similarly create an hourglass

*****
 ***
  *
 ***
*****

3. Similarly Create pascals triangle without the use of arrays
    1
   1 1
  1 2 1
 1 3 3 1
*/

#include <stdio.h>

int factorial(int n);
void pyramid(int n);
void hourglass(int n);
void pascal(int n);

int main(){
    int n;
    printf("Enter number of rows:");
    scanf("%d", &n);
    printf("\n");
    pascal(n);
    printf("\n \n");
    pyramid(n);
    printf("\n \n");
    ulta_pyramid(n);
    return 0;
}

void pyramid(int n){
    int spaces = n - 1;
    int stars = 1;
    for (int i = 0; i < n; i++){
        for (int j = spaces; j > 0; j--){
            printf(" ");
        }
        spaces--;
        for (int k = stars; k > 0; k--){
            printf("*");
        }
        stars += 2;
        printf("\n");
    }
}

void hourglass(int n){
    int stars = 2 * n - 1;
    int spaces = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = spaces; j > 0; j--){
            printf(" ");
        }
        spaces++;
        for (int k = stars; k > 0; k--){
            printf("*");
        }
        stars -= 2;
        printf("\n");
    }
    pyramid(n);
}

int factorial(int n){
    int a = 1;
    for (int i = 1; i <= n; i++){
        a *= i;
    }
    return a;
}

void pascal(int n){
    int spaces = n - 1;
    double val;
    int value;
    for (int i = 0; i < n; i++){
        for (int j = spaces; j > 0; j--){
            printf(" ");
        }
        spaces--;
        for (int j = 0; j <= i; j++){
            val = factorial(i) / (factorial(j) * factorial(i - j));
            value = (int) val;
            printf("%d ", value);
        }
        printf("\n");
    }
}
