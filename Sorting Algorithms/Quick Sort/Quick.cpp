/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdlib>
using namespace std; 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high - 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	
	for (i = 0; i < size; i++) 
		cout << arr[i] << "\t"; 
	
	cout << endl; 
} 

// Driver Code 
int main() 
{ 
	int N, i;
	float sec;

	clock_t t;

	srand(time(NULL));
	
	cout << "Insert a value --> ";
	cin >> N;
	
	int arr[N];
	
	for (i=0; i<N; ++i)
	{
		arr[i] = rand()%99+1;
	}

	t = clock();
	quickSort(arr, 0, N - 1); 
	sec = (clock() - t) / static_cast <float> (CLOCKS_PER_SEC);
	
	cout << "Sorted array: \n"; 
	printArray(arr, N);

	cout << "Time --> " << sec;
	
	return 0; 
}