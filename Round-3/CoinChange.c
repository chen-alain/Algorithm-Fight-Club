/*
Algorithm Fight Club Round 3
10/6/2016
https://www.hackerrank.com/contests/2016-algorithm-fight-club-round-3/challenges/coin-change
Alain Chen
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count( int c[], int m, int n );

int main() {

    
    //Get input.
    int n, m;  
    scanf("%d", &n);
    scanf("%d", &m);    
    
    int coinFaceValues[51], temp;
    for(int i=0;i<m;i++)
    {
        scanf("%d", &temp);
        coinFaceValues[i]=temp;
    }
    
    //The actual fuctionality.
    printf("%d", count(coinFaceValues, m, n));
    return 0;
}

//c is list of coin values
//m is number of coins
//n is the desired sum
int count( int c[], int m, int n )
{
    int i, j, x, y;
 
    //table[a][b] gives the number of solutions
    //with sum a and coins used up to coin b, which has a value of c[b].
    int table[251][51];
    
    // There are exactly 1 way to make 0 dollars, regardless of denomination.
    for(i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for(i = 1; i < n+1; i++)
    {
        for(j = 0; j < m; j++)
        {
            x=0;
            y=0;          
            
            // Count of solutions including the coin with value c[j].
            if(i-c[j] >= 0)
                x=table[i - c[j]][j];
 
            // Count of solutions excluding the coin with value c[j], 
            //which consists of all other possible combinations
            if(j >= 1)
                y= table[i][j-1];
 
            // total count
            table[i][j] = x + y;
        }
    }
    
    //table[a][b] gives the number of solutions
    //with sum a and coins used up to coin b.
    //Here, we want the entire sum and entire set of coins used.
    return table[n][m-1];
}
