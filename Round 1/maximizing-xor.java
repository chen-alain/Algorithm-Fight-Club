/*
Algorithm fight club 
Round 1
9/8/2016
https://www.hackerrank.com/contests/2016-algorithm-fight-club-round-1/challenges/maximizing-xor

Alain Chen
*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        //Get input.
        Scanner reader = new Scanner(System.in);
        int left = reader.nextInt();
        int right = reader.nextInt();
        
        /*
            We want to find out in the binary system,
            which power of two has the possibility of 0 occuring.
            & "bit-wise and" will give us this information.
            Eg. 10 & 12 in binary is ...00001010 | ...0000110 = ...00000010
        */
        int resultAnd=left;
        /*
            We want to find out in the binary system, 
            which power of two has the possibility of 1 occuring.
            | "bit-wise or" will give us this information. 
            Eg. 10 & 12 in binary is ...00001010 | ...0000110 = ...00001110
        */
        int resultOr=left;
        
        for(int i = left+1; i <= right; i++ )
        {
            resultAnd&=i;//The bit-wise and of all integers between left and right.
            resultOr|=i;//The bit-wise or of all integers between left and right.
        }
        
        /*
            ^ is XOR for C, C++, Java, and some languages.
            This works because 0^1=1, and we want to find the maximum number.
            By & and | all the integers we find the possible values of each position,
            and by ^ them together we get the largest possible integer.
        */
        System.out.print(resultAnd^resultOr); 

    }
}