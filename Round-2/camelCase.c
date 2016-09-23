#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    
    char* current = s;
    int count = 1;//The first word is not capitalized
    while( *current != '\0')
    {
        //if count falls below the range of ABCD...XYZ.
        //You can compare char's this way because char's are essentially ints
        if(*current >= 'A' && *current <= 'Z')
            count++;
        current++;
    }
    printf("%d",count);
    return 0;
}
