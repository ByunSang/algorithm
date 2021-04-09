#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);
#define MIN(x, y) ((x > y) ? y : x)
int NUM_3N_MAGIC_SQUARE = 8;

int magic[8][3][3] = {
    {{8,1,6}, {3,5,7}, {4,9,2}},
    {{6,1,8}, {7,5,3}, {2,9,4}},
    {{4,9,2}, {3,5,7}, {8,1,6}},
    {{2,9,4}, {7,5,3}, {6,1,8}},
    {{8,3,4}, {1,5,9}, {6,7,2}},
    {{4,3,8}, {9,5,1}, {2,7,6}},
    {{6,7,2}, {1,5,9}, {8,3,4}},
    {{2,7,6}, {9,5,1}, {4,3,8}}
};

// Complete the formingMagicSquare function below.
int formingMagicSquare(int s_rows, int s_columns, int** s) {
    int sum = INFINITY;
    bool check[10] = {false,};
    
    for (int m = 0; m < NUM_3N_MAGIC_SQUARE; m++){
        int _sum = 0;
        for(int i = 0; i< s_rows; i++){
            for (int j = 0; j < s_columns; j++){
                
                _sum += abs(magic[m][i][j] - s[i][j]); 
                printf ("%d  ", _sum);
            }
        }  
        printf ("\n"); 
        sum = MIN(sum, _sum);
    }
    return sum;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(readline());

        for (int j = 0; j < 3; j++) {
            char* s_item_endptr;
            char* s_item_str = *(s_item_temp + j);
            int s_item = strtol(s_item_str, &s_item_endptr, 10);

            if (s_item_endptr == s_item_str || *s_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(s + i) + j) = s_item;
        }
    }

    int s_rows = 3;
    int s_columns = 3;

    int result = formingMagicSquare(s_rows, s_columns, s);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}


