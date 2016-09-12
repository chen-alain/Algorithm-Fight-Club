/*
Algorithm fight club 
Round 1
9/8/2016
https://www.hackerrank.com/contests/2016-algorithm-fight-club-round-1/challenges/simple-array-sum

Alain Chen
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int sum=0;
    int n, entry;
    scanf("%d",&n);
	
	//You do not need to remember the entire array, you just need to do a running sum.
    for(int i = 0; i < n; i++){
       scanf("%d",&entry);
       sum+=entry;
    }  
    printf("%d",sum);
    return 0;
}