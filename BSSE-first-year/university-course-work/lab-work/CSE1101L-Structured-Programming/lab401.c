/* Basic int Array problems 
1. Reverse an Array
2. Sum of elements in an int array
3. minimum & maximum value of an array
4. Merging 2 arrays 
*/
#include <stdio.h>

int sum(int n, int arr[n]){
    int s = 0;
    for (int i=0;i<n;i++){
        s+=arr[i];
    }
    return s;
}
void min_max(int n, int arr[n]){
    int min = arr[0];
    int max = arr[0];
    for (int i =1; i<n;i++){
        if (arr[i] < min){
            min = arr[i];
        }
        else if (arr[i]> max){
            max = arr[i];
        }
    }
    printf("max: %d \nmin: %d \n", max,min);
}


int main() {
    int arr[3] = {2, 5, 8};
    int arr1[5] = {1,3,10,13,16};
    int arr2[3];
    
    int k =0;
    for (int i =2;i>-1;i--){
        arr2[k] = arr[i];
        k++;
    }
    
   printf("Reverse: \n");
    for (int i=0;i<3;i++){
        printf("%d\n", arr2[i]);
    }
    printf("\nsum: %d\n", sum(3,arr));
    min_max(3, arr);
    
    // Merging arrays
    printf("\nMerged: \n");
    int merged_arr[8];
    int n =0;
    int f =0;
    int l =0;
    while (l<5){
        while (l<5){
            if (arr[f] > arr1[l]){
                merged_arr[n] = arr1[l];
                n++;
                l++;
            } 
            else if (f==3){
                merged_arr[n] = arr1[l];
                    n++;
                    l++;
            }
            else{
                merged_arr[n] = arr[f];
                n++;
                f++;
            }
        }
    }
    
    for (int i=0;i<8;i++){
        printf("%d\n", merged_arr[i]);
    }
   
    return 0;
}
