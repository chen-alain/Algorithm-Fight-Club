/*

Algorithm Fight Club Round 3
10/6/2016
Alain Chen

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n);

int main() {  
    
    int n;
    scanf("%d",&n);
    
    int input;
    for(int counter=0;counter<n;counter++)
    {
        scanf("%d",&input);
        if(isPrime(input))
        {
            printf("%d\n", input);
        }
        else
        {
            
            int primeFound = 0;
            //We only need to check numbers starting from 
            //half the original number since a number cannot have
            //a factor larger than half its value.
            for(int i=input/2;i>=2;i--)
            {
                //printf("%d, ", i);
                if(input%i==0&&isPrime(i)&&primeFound==0)
                {
                    printf("%d\n", i);
                    primeFound=1;
                }
            }
        }
    }
    return 0;
}

//Checks if a number is prime. Ignore cases for 0 and 1.
int isPrime(int n)
{
    //Number is even and not 2;
    if(n>2&&n%2==0)
        return 0;
    //Checks all the odd integers for factors.
    for(int i=3;i<n/2;i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}*/
/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findLargestPrime(int n);

int main() {
   
    
    int n;
    scanf("%d",&n);
    
    int input;
    for(int counter=0;counter<n;counter++)
    {
        scanf("%d",&input);
        printf("%d\n", findLargestPrime(input));
    }
    return 0;
}

int findLargestPrime(int n)
{
    int largestPrime=2;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            int a = findLargestPrime(i);
            int b = findLargestPrime(n/i);
            if(a>largestPrime)
                largestPrime=a;
            if(b>largestPrime)
                largestPrime=b;
        }            
    }
    
    if(largestPrime!=2)
        return largestPrime;
    
    if(n%2==1)
        return n;
    return 2;
}*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int greatestPrime(long long int a);

int main() {
    int numTimes;
    scanf("%d", &numTimes);
    
    for(int i=0;i<numTimes;i++)
    {
        long long int target;
        scanf("%lld", &target);
        printf( "%lld\n", greatestPrime(target) );
    }
    return 0;
}

long long int greatestPrime(long long int a)
{
    long long int greatestFactor = (int)sqrt(a);
    
    
    int found = 0;
    
    //Find the largest factor of a (not necessary prime)
    while( !found && greatestFactor > 1)
    {
        if( a % greatestFactor == 0 )
            found = 1;
        else
            greatestFactor--;
    }    
    
    //a must be prime since no factor other than 1 was found.
    if(!found)
        return a;
    
    //The greatest prime factor of a number
    //must be a factor of one of its factors.
    long long int b = greatestPrime(a/greatestFactor);
    long long int c = greatestPrime(greatestFactor);
    
    if(b>c)
        return b;
    return c;
}


