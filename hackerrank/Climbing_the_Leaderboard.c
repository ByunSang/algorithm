#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
    int stack[200001] = {0,};
    int player_count = 0;
    int ranked_count = 0;
    int top = 0;
    int tmp = 0;
    
    scanf("%d", &ranked_count);
    
    //ranked top-down order
    
    for(int i = 0; i < ranked_count; i++){
        scanf("%d", &stack[top+1]);
        if (stack[top] != stack[top+1]) ++top;
    }

    scanf("%d", &player_count);

    //player down-top order
    
    for (int i = 0; i < player_count; i++){
        scanf("%d", &tmp);
        
        while(top && (tmp >= stack[top])){
            
            top--;
        }
        printf ("%d\n", top+1);
        
    }

    
        
    return 0;
}


