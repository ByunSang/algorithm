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

// Complete the appendAndDelete function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* appendAndDelete(char* s, char* t, int k) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    
    int min_len = s_len > t_len ? t_len : s_len;
    
    int need_k = 0;
    int not_match_index = min_len;
    
    for (int i = 0; i < min_len; i++){
            if (s[i] != t[i]) {
                not_match_index = i;
                break;
        }
    }
    
    need_k = s_len + t_len - 2 * not_match_index;
    printf ("not_match_index : %d  need_k : %d\n", not_match_index, need_k);
    if (need_k == k || 
        ((need_k <= k) && ((abs(k-need_k)%2) == 0)) ||
        s_len + t_len <= k) return "Yes";
    else return "No"; 

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* t = readline();

    char* k_endptr;
    char* k_str = readline();
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = appendAndDelete(s, t, k);

    fprintf(fptr, "%s\n", result);

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

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}


