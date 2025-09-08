/*
You are required to implement a simplified regular expression matcher in C using recursion only (no dynamic programming, no loops for backtracking).

Description:

You are given two strings:
Text → a string consisting of lowercase English letters.
Pattern → a string consisting of lowercase English letters and the special characters . and *.

Your task is to check if the entire text string matches the given pattern. The rules of matching are as follows:




. (dot) → Matches any single character. Example: "a" matches "." Example: "b" matches "."* (asterisk) → Matches zero or more occurrences of the preceding character.
Example: "aaa" matches "a*" (because "a*" can represent "a", "aa", "aaa", etc.) Example: "" (empty text) matches "a*" (because "a*" can represent zero "a").The match must cover the entire text, not just a substring.

Input:
A text string (lowercase letters).
A pattern string (lowercase letters plus . and *).
Output:

Return true if the text matches the pattern completely, otherwise return false.

Task:
Write a recursive function in C: bool isMatch(const char *text, const char *pattern); that returns true if the text matches the pattern, otherwise false.

Example 1

Text: "aab"

Pattern: "c*a*b"

Output: true

Explanation: "c*" matches zero 'c' characters, "a*" matches two 'a' characters, and "b" matches 'b'.


Example 2

Text: "abc"

Pattern: "a.c"

Output: true

Explanation: 'a' matches 'a', '.' matches 'b', and 'c' matches 'c'.


Example 3

Text: "mississippi"

Pattern: "misp*."

Output: false


Example 4

Text: "abcd"

Pattern: "a.*" 

Output: true

allows repeating "." for the rest of "bcd".


*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int i = -1;
int j =-1;


bool isMatch(const char *text,const char *pattern){
    i++;
    j++;
    if (pattern[j] != '\0'){
        if (pattern[j+1] != '\0'){
            if (pattern[j+1] == '*'){
                if (pattern[j] != '.'){
                    while (text[i] == pattern[j]){
                        i++;
                    }
                    j+=2;
                        
                }
                else {
                    if(pattern[j+2] != '\0'){
                        if ((text[strlen(text)-1] == pattern[j+2] || pattern[j+2] == '.') && j+3 == strlen(pattern) )
                        return true;
                        }
                        else{ 
                            return false;
                        }
                    }
            }
                    else return true;
        }
    }
    if (i == strlen(text)){
        return true;
    }
    
    
    if (i==0 && j==0){
       // Work on this 
       if (text[i] == '\0' && pattern[j] !='\0'){
           
           return pattern[strlen(pattern)-1] == '*';
       }
       if (text[i] != pattern[j] && pattern[j] != '.'){
           return false;
       }
       
    }
    else if (i == strlen(text)-1){
        if (text[i] == pattern[strlen(pattern)-1] || pattern[strlen(pattern)-1] == '.'){
                return true;
            }
    }
    else{
        if (pattern[j] != '*'){
            if (text[i] != pattern[j] && pattern[j] != '.'){
                return false;
            }
        }
        
        if (pattern[j] == '*'){
            if (pattern[j+1]=='\0' && pattern[j-1]=='.'){
                return true;
            }
            
            else if (pattern[j+1]=='\0' && pattern[j-1]!='.'){
                int k = i;
                while (text[k]){
                    if (text[k]!= pattern[j-1]){
                        return false;
                    }
                    k++;
                }
                return true;
            }
            else if (pattern[j+1]!= '\0'){
                while (text[i] == pattern[j-1]){
                    i++;
                }
                return isMatch(text, pattern);
            }

        }
 
    }
    return isMatch(text, pattern);

}



int main() {
    char text[] = "aab";
    char pattern[] = "c*a*b";

    bool a = isMatch(text, pattern);

    if(a) printf("Match\n");
    else printf("No match\n");

    return 0;
}
