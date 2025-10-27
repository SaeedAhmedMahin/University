#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_char(const void *a, const void *b) {
    return (*(const char*)a) - (*(const char*)b);
}

int main(void) {
    int n = 3;
    char *tmp;

    char **arr = malloc(n * sizeof(char *));
    if (!arr) { perror("malloc failed"); return 1; }

    arr[0] = malloc(strlen("bacchu") + 1);
    arr[1] = malloc(strlen("medical") + 1);
    arr[2] = malloc(strlen("dabor") + 1);

    strcpy(arr[0], "bacchu");
    strcpy(arr[1], "medical");
    strcpy(arr[2], "dabor");


    // sorting characters
    for (int i = 0; i < n; i++) {
        size_t len = strlen(*(arr+i));
        if (len > 1) {
            for (size_t k = 1; k < len; k++) {
                char key = *(*(arr+i)+k);
                size_t j = k;
                while (j > 0 && *(*(arr+i)+j-1) > key) {
                    *(*(arr+i)+j) = *(*(arr+i)+j-1);
                    j--;
                }
                *(*(arr+i)+j) = key;
            }
        }
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(*(arr+j), *(arr+j+1)) > 0) {
                tmp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1)= tmp;
            }
        }
    }


    for (int i = 0; i < n; i++) printf("%s\n", *(arr+i));

    for (int i = 0; i < n; i++) free(*(arr+i));
    free(arr);
    return 0;
}
