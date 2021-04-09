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

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int buf[512] = {0,};
    
    int result_size = 1;
    buf[0] = 1;
    
    for (int i = 2; i <= n; i++){
        int carry = 0;
        
        for (int x = 0; x < result_size; x++){
            int tmp = (buf[x] * i) + carry;
            buf[x] = tmp % 10;
            carry = tmp / 10;
            //printf("buf [%d] : %d\n", x, buf[x]);
        }
        while (carry){
            buf[result_size] = carry % 10;
            carry = carry / 10;
            result_size++; 
        }
    }
   
    for (int i = result_size -1; i >= 0; i --)
        printf("%d", buf[i]);
}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    extraLongFactorials(n);

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


