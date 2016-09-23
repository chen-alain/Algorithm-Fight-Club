#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int array[101];//Keeps tracks how many times an element occurs.

    int i = 0;
    for( i = 0; i<101; i++)
        array[i]=0;

    int n, input;
    scanf("%d", &n );
    
    //Input.
    while( n > 0 )
    {
        scanf("%d", &input );
        array[input]++;
        n--;
    }
    
    n = 0;
    int j;
    while( n <= 100 )
    {
        j = 0;
        //Output each integer the number of times it has appeared.
        while( j < array[n] )
        {
            printf("%d ", n );
            j++;
        }
        n++;
    }
    
    return 0;
}
