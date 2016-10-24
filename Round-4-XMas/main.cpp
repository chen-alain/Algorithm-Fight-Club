/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: L
 *
 * Created on October 20, 2016, 7:19 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void christmasOne(string ordinals[], string actions[]);
void christmasTwo(string ordinals[], string actions[], int day);
void christmasTwoHelper(string ordinals[], string actions[], int day, int curr);
void christmasThree(string ordinals[]);

int main(int argc, char** argv) {

    string ordinals[] = { "", "first", "second", "third", "fourth", "fifth",
        "sixth", "seventh", "eight", "ninth", "tenth", "eleventh", "twelfth" };
 
    string actions[] = { "", " Partridge in a Pear Tree\n", 
        "Two Turtle Doves,\nAnd ", "Three French Hens,\n", 
        "Four Calling Birds,\n", "Five Golden Rings,\n", 
        "Six Geese-a-Laying,\n", "Seven Swans-a-Swimming,\n",
        "Eight Maids-a-Milking,\n", "Nine Ladies Dancing,\n", 
        "Ten Lords a Leaping,\n", "Eleven Pipers Piping,\n", 
        "Twelve Drummers Drumming,\n" };
    
    //christmasOne(ordinals, actions);
    //christmasTwo(ordinals, actions,1);
    //christmasThree(ordinals);
    
    return 0;
}

//Prints out the lyrics of the 12 days of Christmas using
//nested for loops.
void christmasOne(string ordinals[], string actions[])
{
    for(int i = 1; i <= 12; i++ )
    {
        cout << "On the " << ordinals[i] << " day of Christmas "
                << "my true love gave to me:\n";
        
        for(int j=i; j>=1; j-- )
        {
            if( j == 1 )
            {
                if( i == 1 )
                    cout << "A";
                else
                    cout << "a";
            }           
            cout << actions[j];
        }
        cout << endl;
    }
}

void christmasTwo(string ordinals[], string actions[], int day)
{
    if( day >= 13 )
        return;
    
    cout << "On the " << ordinals[day] << " day of Christmas "
                << "my true love gave to me:\n";
    
    christmasTwoHelper(ordinals, actions, day, day);   
    
    christmasTwo(ordinals, actions, day+1);
}

void christmasTwoHelper(string ordinals[], string actions[], int day, int curr)
{
    if( curr <= 0 )
    {
        cout << endl;
        return;
    }
        
    if( curr == 1 )
    {
        if(day==1)
            cout << "A";
        else
            cout << "a";
    }
    
    cout << actions[curr];
    
    christmasTwoHelper(ordinals, actions, day, curr-1);
}

void christmasThree(string ordinals[])
{
    for(int i=1;i<12;i++)
    {
        cout << "On the " << ordinals[i] << " day of Christmas " 
                << "my true love gave to me:\n";
        switch(i)
        {
            case 12: 
                cout << "Twelve Drummers Drumming,\n";
            case 11: 
                cout << "Eleven Pipers Piping,\n";
            case 10: 
                cout << "Ten Lords a Leaping,\n";
            case 9: 
                cout << "Nine Ladies Dancing,\n";
            case 8: 
                cout << "Eight Maids-a-Milking,\n";
            case 7: 
                cout << "Seven Swans-a-Swimming,\n";
            case 6: 
                cout << "Six Geese-a-Laying,\n";
            case 5: 
                cout << "Five Golden Rings,\n";
            case 4: 
                cout << "Four Calling Birds,\n";
            case 3: 
                cout << "Three French Hens,\n";
            case 2: 
                cout << "Two Turtle Doves,\nAnd ";
            case 1: 
                cout << (i == 1 ? "A" : "a") 
                    << " Partridge in a Pear Tree\n\n";
        }
    }
}