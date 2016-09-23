#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int numTestCases;
    cin >> numTestCases;
    vector<int> listOfNums;
    vector<int> currSum;
    
    for(int i=0;i<numTestCases;i++)
    {
        listOfNums.clear();
        currSum.clear();
        int size;
        cin >> size;
        int nonContiguousSum = 0;
        bool hasNonNegative = false;
        
        //Get the numbers into our data structure.
        int num;
        for(int j=0;j<size;j++)
        {      
            cin >> num;
            listOfNums.push_back(num);
            if(num>=0)
                hasNonNegative=true;
        }
        
        
        //Obtain the largest contigous array sum.        
        currSum.push_back(listOfNums[0]);
        int maxSum = listOfNums[0];
        for(int j=1,m=listOfNums.size();j<m;j++)
        {      
            //The largest sum of the contiguous arrays
            //CONTAINING THIS ELEMENT
            //must either be this element alone,
            //or the sum of this element and the previous element.
            int curr = currSum[j-1]+listOfNums[j];
            if(curr>listOfNums[j])
                currSum.push_back(curr);
            else
                currSum.push_back(listOfNums[j]);                            
        }
        
        //Find the maximum sum.
        int maxNum = currSum[0];
        for(int k=1;k<currSum.size();k++)
            if(currSum[k]>maxNum)
                maxNum = currSum[k];
            
        cout << maxNum << " ";
        
        //Obtain the sum of the subarray with largest nonContiguousSum.
        //This is simply the sum of all positive integers.        
        if(hasNonNegative)
        {
            int sum=0;
            for(int k=0;k<listOfNums.size();k++)
                if(listOfNums[k]>0)
                    sum+=listOfNums[k];
            cout << sum << endl;
        }
        else
        {
            //If all integers are negative, then report the largest negative number.
            int max = listOfNums[0];
            for(int k=1;k<listOfNums.size();k++)
                if(listOfNums[k]>max)
                    max = listOfNums[k];
            cout << max << endl;   
        }
       
            
    }
    
    
    return 0;
}
