/*
Algorithm fight club 
Round 1
9/8/2016
https://www.hackerrank.com/contests/2016-algorithm-fight-club-round-1/challenges/kangaroo

Alain Chen
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    
    //Solution in c.
    int x1; 
    int v1; 
    int x2; 
    int v2; 
    scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
    
    //Same speed, diffent location
    if( v1 == v2 && x1 != x2 ) 
    {
        printf("NO");
        return 0;
    }
    
    int i=0;
    for(;i<10000;i++)
    {
        //If they are ar the same location.
        if( x1==x2 )
        {
            printf("YES");
            return 0;
        }
        
        x1+=v1;
        x2+=v2;
    }
    printf("NO");
    
    /*
    C++ solution
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2; //This is like scanf in c.
    
    //Same speed, diffent location
    if( v1 == v2 && x1 != x2 ) 
    {
        cout << "NO"; //This is like printf in c.
        return 0;
    }
    
    for(int i=0;i<10000;i++)
    {
        if( x1==x2 )
        {
            cout << "YES";
            return 0;
        }
        
        x1+=v1;
        x2+=v2;
    }
    cout << "NO";*/

    return 0;
}