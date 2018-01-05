#include <iostream>
#include <vector>
using namespace std;

/*
sorts array by finding the min element from unsorted
part and putting it at the begining. algorithm
maintains 2 subarrays in a given array
1) subarray which is already sorted
2) remaining subarray that is unsorted

in every iteration of selection sort, the minimum element
from unsorted subarray is picked and moved to the sorted
subaray.

ex) arr[] = 64 24 12 22 11

// find min and put it at the beginning
11 24 12 22 62

// find next min and swap
11 12 24 22 62

// find next min
11 12 22 24 62


NOTE: TIME COMPLEXITY IS O(N^2)

*/

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(vector<int>& arr) {
	int i, j, minIndex;
	for (i = 0; i < arr.size()-1; i++) {
		minIndex = i;
		for (j = i+1; j < arr.size(); j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			} 
		}
		swap(&arr[minIndex], &arr[i]);
	}
}

void printArray(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> arr = {64, 25, 12, 22, 11};
	selectionSort(arr); 
	cout << "sorted array: " << endl;
	printArray(arr);

	return 0;

}