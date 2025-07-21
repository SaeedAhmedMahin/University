/* 
Create a function that simulates a store which provides discount if the price is 
1. >100 but <500 discount is 20
2. >1000 then discount is 5%
3. >5000 then discount is 10%
*/
#include<stdio.h>
float discount (float price){
    float d=0;
    if(price < 100){
        d = 0;
        return d;
    }
    if(price < 500 && price > 100){
        d = 20;
        return d;
    }
    if(price > 1000 && price < 5000){
        d=0.05 *price;
        return d;
    }
    if(price > 5000){
        d = 0.1 *price;
        return d;
    }
    return d;
}

int main(){
    float price;
    scanf("%f" , &price);
    float d, pay;
    d = discount(price);
    pay = price -d;
    printf("discount: %f and you're payment due : %f", d, pay);
    return 0;
}
