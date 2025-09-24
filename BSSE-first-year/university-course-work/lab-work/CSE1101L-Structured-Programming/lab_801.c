// Saeed Ahmed Mahin
// 1703 

#include <stdio.h>
#include <string.h>
#include <math.h>


// PROBLEM 1: Implement Remove, Replace and Insert Methods on arrays
void removes(char arr[],  int len, int index){
    for (index; index<len-1;index++){
        arr[index] = arr[index+1];
    }
    arr[len-1] = '\0';
}

void replace(char arr[],  int len, int index, char c){
    if (len>index){
    arr[index] = c;
    }
}

void insert(char arr[],  int len, int index, char c){
    arr[len+1] = '\0';
    if (index == len){
        arr[index] = c;
    }
    else {
        int i = len;
        for(i;i>index-1;i--){
            arr[i+1] = arr[i];
        }
        arr[index] = c;
    }
}

// PROBLEM 2: Generate the power set of a given array, the result should be a 2D array and print it.
// Will try later

// PROBLEM 3: FIND PALINDROME IN AN ARRAY
void palindrome(char arr[][100], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {

            int m = strlen(arr[i]);
            int n = strlen(arr[j]);
            if (m != n) {
            	continue;
            }      

            int pal = 1;               
            for (int k = 0; k < m; k++) {
                if (arr[i][k] != arr[j][m - 1 - k]) {
                    pal = 0;
                    break;
                }
            }

            if (pal) {
                printf("Palindrome Pairs: %s  ---  %s\n", arr[i], arr[j]);
            }
        }
    }
}





// PROBLEM 4: Valid Parenthesis
int valid_parenthesis(char arr[], int len){

	if (len%2==1){
		return 0;
	}
	
        if ((arr[len-1] == '(') || (arr[len-1] == '{') || (arr[len-1] == '[')){
        	return 0;
        }
        else if ((arr[0] == ')') || (arr[0] == '}') || (arr[0] == ']')){
        	return 0;
        }
        
        int i = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int m = 0;
        int n = 0;
        int o = 0;
        for(i;i<len-1;i++){
        	char p = arr[i];
        	char q = arr[i+1];
        	if (p == '('){
        		a++;
        		if (q == '}' || q == ']'){
        			return 0;
        		}
        	}
        	else if (p == '{'){
        		b++;
        		if (q == ')' || q == ']'){
        			return 0;
        		}
        	}
        	else if (p == '['){
        		c++;
        		if (q == ')' || q == '}'){
        			return 0;
        		}
        	}
        	else if (p == ')'){
        		m++;
        	}
        	else if (p == '}'){
        		n++;
        	}
        	else if (p == ']'){
        		o++;
        	}
        	
        }
       	char ni = arr[len-1];
       	if (ni == ')'){
       		m++;
       	}
       	else if (ni == '}'){
       		n++;
       	}
       	else if (ni == ']'){
       		o++;
       	}
       	
        if ( a!=m || b!=n || c!=o){
        	return 0;
        }
        return 1;
}


int main() {
    // Problem 1:
    
    char arr[] = "pales";
    
    
    insert(arr, 5, 0,'a');
    for (int i =0; i<6;i++){
        printf("%c", arr[i]); // apales
    }
    printf("\n");
    removes(arr,6,0);
    for (int i =0; i<5;i++){
        printf("%c", arr[i]);  // pales
    }
    printf("\n");
    replace(arr,5,0,'b');
    for (int i =0; i<5;i++){
        printf("%c", arr[i]); // bales
    }
    
    
    // Problem 3:
    char words[][100] = {"abc", "cba", "nice", "hello", "olleh"};
    palindrome(words, 5);
    
    // PROBLEM 4:
    
    char arr2[] = "{}{([])([])}";
    
    int valid = valid_parenthesis(arr2, 12);
    
    printf("%d", valid); // Returns 0 if invalid and 1 if valid
    
    
    
    

    return 0;
}
