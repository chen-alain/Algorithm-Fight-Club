/* 
 * Alain Chen
 * Algorithm Fight Club
 * 11/3/16 
 * Comb Sort
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;


const double SHRINK_FACTOR = 1.3;
const int ARRAY_SIZE  = 20;

int printArray(int array[]);

int main(int argc, char** argv) {

    cout << "Comb Sort" << endl;
    
    int array[ARRAY_SIZE] = {100,2,234,123,2345,68234,45,9,3,14,
                    28,324,9,3,1,79,46,4,67,1 };
    
    /*srand(time(NULL));
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        array[i]= rand()%50+1;
    }*/
    
    
    bool sorted = false;
    int gap = ARRAY_SIZE;    
    cout << "Initial: ";
    printArray(array);
    
    while(!sorted)
    {
        gap = gap / SHRINK_FACTOR;
        
        
        if( gap > 1 )
            sorted = false;
        else
        {
            gap = 1;
            sorted = true;
        }
        cout <<  "Gap " << setw(2) << gap << ":  ";
        
        //Comb over the list.
        int counter = 0;
        while( counter + gap < ARRAY_SIZE )
        {
            //Out of order, so swap elements.
            if(array[counter] > array[counter+gap])
            {
                int temp = array[counter+gap];
                array[counter+gap] = array[counter];
                array[counter] = temp;
                sorted = false;
            }
            
            counter++;
        }
        
        printArray(array);
    }
    
    
    
    return 0;
}


int printArray(int array[])
{
    for( int i=0;i<ARRAY_SIZE; i++)
    {
        cout << setw(6) << array[i] << " ";
    }
    cout << endl;
    
}
