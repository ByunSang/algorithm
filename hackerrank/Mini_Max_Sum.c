#include <stdio.h>
#include <stdlib.h>

static int compare(const void* a, const void* b)
{
    
    return (*(int *)a > *(int *)b ? 1 : 0);
}

int main()
{
    int arr[5];
    
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    
    qsort(arr, sizeof(arr)/ sizeof(int), sizeof(int), compare);
    
    printf("%ld %ld\n", 
        (long int)arr[0]+arr[1]+arr[2]+arr[3],
        (long int)arr[1]+arr[2]+arr[3]+arr[4]);
 
    return 0;
}


