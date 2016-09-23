#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; //number of levels
    scanf("%d",&n);
    
    //counter
    int i;
    for( i=1;i<=n;i++ )
    {
        int j;
        //Print the spaces.
        for(j=1;j<=n-i;j++)
            printf(" ");
        //Print the #'s.
        for(j=1;j<=i;j++)
            printf("#");
        printf("\n");
    }
  
    return 0;
}
