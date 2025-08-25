// Saeed Ahmed Mahin
// roll: 1703
// section: A

#include <stdio.h>

int arr_sum(int arr[],int len){
    if (len == 0){
        return 0;}
    return arr[len-1] + arr_sum(arr, len-1);
}


void arr_reverse(int arr[], int len, int i){
    if (len <= i){
        return;
    }
    int a = arr[i];
    arr[i] = arr[len-1];
    arr[len-1] = a;
    return arr_reverse(arr, len-1, i+1);
}


// Merge Sort unsuccesful, will try again
// void merge_sort(int arr[], int len, int i)
//     if (len <= 1){
//         return arr[0];
//     }
//     else if (len-1-i == 1) {
//         if (arr[len-1]>=arr[i] ){
//             return arr;
//         }    
//         else {
//             int a = arr[i];
//             arr[i] = arr[len-1];
//             arr[len-1] = a;
//         }
//     }
//     else{
//         merge_sort(arr,len-1)
//     }

// }


int main() {
    // Write C code here
    int arr[4] = {1,2,3,4};
    int sum = arr_sum(arr,4);
    printf("sum: %d \n", sum);
    
    arr_reverse(arr,4,0);
    printf("Reverse: \n");
    for (int i =0; i<4;i++){
        printf(" %d \n", arr[i]);
    }

    return 0;
}
