#include <iostream>

using namespace std;

int sumArray(int arr[], int arrSize);

int main()
{
    int* arr = NULL;   // Pointer to int, initialize to nothing.
    int n;           // Size needed for array
    int result;

    // cout << "Enter array capacity: ";
    cin >> n;        // Read in the size
    arr = new int[n];  // Allocate n ints and save ptr in a.

    for (int i=0; i<n; i++) 
    {
        int tempEl = 0;

        // cout << "Enter value of arr[" << i << "]: ";
        cin >> tempEl;

        arr[i] = tempEl;    // Initialize all elements defaults to 0.
    }

    // calculate the sum
    result = sumArray(arr, n);
    
    delete [] arr;  // When done, free memory pointed to by a.
    arr = NULL;     // Clear a to prevent using invalid memory reference.

    return(result);
}

int sumArray(int arr[], int arrSize)
{
    int sum = 0;

    for(int it = 0; it<arrSize; it ++)
    {
        sum = sum + arr[it];
    }

    return(sum);
}
