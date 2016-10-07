/*
Algorithm Fight Club round 3.
Sherlock and Array

Alain Chen
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
    int cases;
    scanf("%d", &cases);
    int array[100000];
    
    for(int i=0;i<cases;i++)
    {
        int size, sum=0;
        scanf("%d", &size);
        
        for(int j=0;j<size;j++)
        {
            int num;
            scanf("%d", &num);
            array[j]=num;
            sum+=num;
        }
        
        int currSum=0,found=0;
        for(int j=0;j<size;j++)
        {
            //Currsum is the sum left of this current index. 
            //sum-array[j] is the sum of all the elements to the left
            //and to the right of this element.
            //If the condition is met, then left subarray and right subarray must be equal.
            if(sum-array[j]==currSum*2)
            {
                printf("YES\n");
                found=1;
                break;
            }
            currSum+=array[j];
        }
        if(!found)
            printf("NO\n");
    }
    
    return 0;
}
