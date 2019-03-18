#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int mid1, int high);




// Perform mergeSort to sort an array of integers.
// Inputs:
//   arr is the input array of arrSize integers.
//   low and high are the indices to sort to/from, e.g. 0 arrSize-1 to sort entire array
// Postcondition:
//   arr[low] ... arr[high] will contain the original values, sorted in increasing order.
void mergeSort(int arr[], int low, int high) 
{
	if (low < high) 
    { 
        int mid = (low + high) / 2;

        // Sort first and second halves 
        mergeSort(arr, low, mid); 
        mergeSort(arr, mid+1, high); 
        merge(arr, low, mid, mid+1, high); 
    } 
}


// Perform a merge of two sorted sub-arrays.
// Inputs:
//   arr is the input array on which to perform a merge.
//   low-mid and mid1-high are the two sub-arrays to merge.
// Precondition:
//   arr[low]...arr[mid] is sorted in increasing order.
//   arr[mid1]...arr[high] is sorted in increasing order.
//   These should be disjoint, contiguous sub-arrays too.
// Postcondition:
//   arr[low]...arr[high] is sorted in increasing.
void merge(int arr[], int low, int mid, int mid1, int high) 
{
	cout << "\n\nNEW MERGE\n\n";
	// initializing iterators 
	int L_it = 0;
	int R_it = 0;
	int merged_it = low;

	// sizes for three arrays
	int L_size = mid - low + 1;
	int R_size = high - mid1 + 1;
	int merged_size = high - low + 1;

	// Initialize 3 arrays
	int L[L_size], R[R_size], merged[merged_size];

	// print out arr for debugging
	cout << " | ";
	for (int i=low; i<high+1; i++) {
		cout << arr[i] << " | ";
	}
	cout << endl;

	// COPY OVER SUB ARRAYS
	cout << "LHS => ";
	for(int i = 0; i < L_size; i++) 
	{
		cout << arr[low+i] << ", ";
		L[i] = arr[low + i];
	}
	cout << endl << "RHS => ";
	for(int i = 0; i < R_size; i++) 
	{
		cout << arr[mid1 + i] << ", ";
		R[i] = arr[mid1 + i];
	}


	// 	while both subarrays contain unmerged elements
	while(L_it < L_size && R_it < R_size)
	{
		if(L[L_it] < R[R_it]) 
		{
			merged[merged_it] = L[L_it];
			L_it++;
		}
		else 
		{
			merged[merged_it] = R[R_it];
			R_it++;
		}

		merged_it++;
	}
	
	// while subarray1 contains unmerged items
	// 	insert subarray1's next element in temp
	// 	increment subarray1 and temp's indexes
	while(L_it < L_size)
	{
		merged[merged_it] = L[L_it];
		L_it++;	
		merged_it++;
	}

	// while subarray2 contains unmerged items
	// 	insert subarray2's next element in temp
	// 	increment subarray2 and temp's indexes
	while(R_it < R_size)
	{
		merged[merged_it] = R[R_it];
		R_it++;	
		merged_it++;
	}

	// 	copy temp back to the original (sub)array low ... high 
	cout << "\nMERGED => | ";
	for(int i = low; i < high+1; i++) 
	{
		cout << merged[i] << " | ";
		arr[i] = merged[i];
	}
}


// A driver program to test mergeSort.
// Reads in a number of integers (number, then sequence of values).
// Sorts using mergeSort.
// Prints the values in sorted order.
int main (void) {
	int n;

	// Get the number of values.
	//	cout << "Enter the number of values to be sorted:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	int *values;
	values = new int[n];

	for (int i=0; i<n; i++) {
		// cout << "Enter a number:" << endl;
		cin >> values[i];
	}

	// Call mergeSort to sort entire array.
	mergeSort(values,0,n-1);

	cout << "\n\nFINAL RESULT...\n\n";
	// Print values, should be sorted.
	for (int i=0; i<n; i++) {
		cout << values[i] << " ";
	}
	cout << endl;


	// Free up memory.  Note use of delete [], since this is an array.
	delete [] values;

	return 0;
}
