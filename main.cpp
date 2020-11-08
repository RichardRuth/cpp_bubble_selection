// Richard Ruth
// COP2535.CM1
// Program creates two arrays where each holds contents of random.txt file of 200 integer values.
// Program then calls four functions with data. First function uses bubble sort to sort array in ascending order, and
// returns number of exchanges for output display. Second function uses selection sort to sort the other array, and
// returns number of exchanges for output display. Third function uses linear search program to locate value 869, and
// returns number of comparisons for output display. Fourth function uses binary search program to locate value 869,
// and returns number of comparisons for output display.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes

int sortArrayOne(int [], int);
int sortArrayTwo(int [], int);
int linearSearchArrayOne(int [], int);
int binarySearchArrayOne(int [], int);

const int SIZE = 200;     // sets constant for size of array based on size of random.txt file

int main()
{
    int arrayOne[SIZE];     // holds contents of array one
    int arrayTwo[SIZE];     // holds contents of array two
    int countOne = 0;       // Loop control variable that counts data items read into array one
    int countTwo = 0;       // Loop control variable that counts data items read into array two
    int sortBubble;         // holds contents of returned exchange value of bubble sort
    int sortSelection;      // holds contents of returned exchange value of selection sort
    int searchLinear;       // holds contents of returned comparison value of linear search
    int searchBinary;       // holds contents of returned comparison value of binary search
    ifstream inputFile;     //input file stream object
    
    // Open the data file for arrayOne input
    
    inputFile.open("random.txt");
    
    if (!inputFile)
        cout << "Error opening data file\n";
    else
    {
        // Read the numbers from the file into array one
        while (countOne < SIZE && inputFile >> arrayOne[countOne])
            countOne++;
        
        // Close the input file
        inputFile.close();
    }
    
    // Open the data file for arrayTwo input
    
    inputFile.open("random.txt");
    
    if (!inputFile)
        cout << "Error opening data file\n";
    else
    {
        // Read the numbers from the file into array two
        while (countTwo < SIZE && inputFile >> arrayTwo[countTwo])
            countTwo++;
        
        // Close the input file
        inputFile.close();
    }
    
    // call program functions for each sort or search purpose and assign values to variables
    
    sortBubble = sortArrayOne(arrayOne, SIZE);
    sortSelection = sortArrayTwo(arrayTwo, SIZE);
    searchLinear = linearSearchArrayOne(arrayOne, SIZE);
    searchBinary = binarySearchArrayOne(arrayOne, SIZE);
    
    // display output values
    
    cout << "\nNumber of sort exchanges made for array one using bubble sort: " << sortBubble << "\n";
    cout << "\nNumber of sort exchanges made for array two using selection sort: " << sortSelection << "\n";
    cout << "\nNumber of comparisons to find number 869 using linear search of sorted array one: " << searchLinear << "\n";
    cout << "\nNumber of comparisons to find number 869 using binary search of sorted array one: " << searchBinary << "\n";
    
    return 0;
}

/****************************************************************************
 *                                                                          *
 *                          sortArrayOne                                    *
 * This function uses a bubble sort algorithm to sort array one in          *
 * ascending order, and then returns the value of the number of exchanges   *
 * made in the sort.                                                        *
 *                                                                          *
 ***************************************************************************/

int sortArrayOne(int arrayOne[], int size)
{
    int temp;
    bool madeASwap;
    int exchangesBubble = 0;
    
    do
    {   madeASwap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (arrayOne[count] > arrayOne[count + 1])
            {
                temp = arrayOne[count];
                arrayOne[count] = arrayOne[count + 1];
                arrayOne[count + 1] = temp;
                madeASwap = true;
                exchangesBubble++;
            }
        }
    } while (madeASwap); // Loop again if a swap occured on this pass.
    
    return exchangesBubble;
}

/****************************************************************************
 *                                                                          *
 *                          sortArrayTwo                                    *
 * This function uses a selection sort algorithm to sort array two in       *
 * ascending order, and then returns the value of the number of exchanges   *
 * made in the sort.                                                        *
 *                                                                          *
 ***************************************************************************/

int sortArrayTwo(int arrayTwo[], int size)
{
    int startScan;
    int minIndex;
    int minValue;
    int exchangesSelection = 0;
    
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = arrayTwo[startScan];
        for (int index = startScan +1; index < size; index++)
        {
            if (arrayTwo[index] < minValue)
            {
                minValue = arrayTwo[index];
                minIndex = index;
            }
        }
        if (minValue != arrayTwo[startScan])
        {
            exchangesSelection++;
        }
        arrayTwo[minIndex] = arrayTwo[startScan];
        arrayTwo[startScan] = minValue;
    }
    
    return exchangesSelection;
}

/****************************************************************************
 *                                                                          *
 *                          lineearSearchArrayOne                           *
 * This function uses a linear search algorithm to search array one and     *
 * find value 869, and then returns the value of the number of comparisons  *
 * made in the search.                                                      *
 *                                                                          *
 ***************************************************************************/

int linearSearchArrayOne(int arrayOne[], int size)
{
    int index = 0;               // used as a subscript to search array
    int comparisonLinear = 0;    // used to record number of comparisons
    bool found = false;          // flag to indicate if the value was found
    
    while (index < size && !found)
    {
        comparisonLinear++;             // one comparison is always made even if first comparison finds value
        if (arrayOne[index] == 869)
        {
            found = true;
        }
        index++;                        // if value not found, increase array pointer index and compare again
    }
    
    return comparisonLinear;
}

/****************************************************************************
 *                                                                          *
 *                          binarySearchArrayOne                            *
 * This function uses a binary search algorithm to search array one and     *
 * find value 869, and then returns the value of the number of comparisons  *
 * made in the search.                                                      *
 *                                                                          *
 ***************************************************************************/

int binarySearchArrayOne(int arrayOne[], int size)
{
    int first = 0;               // first array element
    int last = size - 1;         // last array element
    int middle;                  // midpoint of search
    int comparisonBinary = 0;    // used to record number of comparisons
    bool found = false;          // flag to indicate if the value was found
    
    while (!found && first <= last)
    {
        comparisonBinary++;                 //  one comparison is always made even if first comparison finds value
        middle = (first + last) / 2;        // calculate midpoint
        if (arrayOne[middle] == 869)
        {
            found = true;
        }
        else if (arrayOne[middle] > 869)    // value is contained in lower half of array
            last = middle - 1;
        else
            first = middle + 1;             // value is contained in upper half of array
    }
    
    return comparisonBinary;
}
