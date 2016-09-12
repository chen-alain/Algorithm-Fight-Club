/*
Algorithm fight club 
Round 1
9/8/2016
https://www.hackerrank.com/contests/2016-algorithm-fight-club-round-1/challenges/unbounded-knapsack

Alain Chen
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numTrials;
    cin >> numTrials;
    int counterTrials = 0;
    
    while( counterTrials++<numTrials )
    {
        //Set up input.
        int numObjects, expectedSum,value;
        cin >> numObjects >> expectedSum;
        
        //We use 2001 since we may have number in the list greater than our expected sum
        vector<int> largestPossibleSum(2001); 
        
        for(int i=0;i<numObjects;i++)
        {
            cin >> value;
            
            //If a number appears on the list of elements,
            //then the largestPossibleSum of that number 
            //must be that number since it can use itself.
            largestPossibleSum[value] = value;
        }
        
        //Start of algorithm.
        
        //Start building the maximum sum from the left.
        for(int i=2; i<=expectedSum; i++ )
        {
            /*
                    The largestPossibleSum of a number Z must be the sum of the
                    largestPossibleSum of some two numbers A and B 
                    such that A + B = Z.
                    Eg. maxSum(4)=max(maxSum(0)+maxSum(4), mS(1)+mS(3), mS(2)+mS(2)).
                    This works because we have already assigned the value of 
                    the largestPossibleSum of numbers that already appear on the list of elements
                    that can be summed.
                    
                    For example,
                    if our list is 2 3 and we want to find the maximum sum that is <= 5,
                    we would have
                    largestPossibleSum(0)=0
                    largestPossibleSum(1)=0
                    largestPossibleSum(2)=2 which is given
                    largestPossibleSum(3)=3 which is given
                    largestPossibleSum(4)=largestPossibleSum(3)+largestPossibleSum(1) = 3 + 0 = 3
                    largestPossibleSum(5)=largestPossibleSum(3)+largestPossibleSum(2) = 3 + 2 = 5
                */
            int currMax = 0;
            
            //Find the pair whose largestPossibleSum is the greatest.
            for(int j=0;j<=i/2;j++)
            {                
                int sum = largestPossibleSum[j]+largestPossibleSum[i-j];
                if(sum>currMax)
                    currMax=sum;
            }
            //Finalize the largestPossible sum.
            largestPossibleSum[i] = currMax;
        }
        cout << largestPossibleSum[expectedSum] << endl;
    }
    
    
   
    return 0;
}
