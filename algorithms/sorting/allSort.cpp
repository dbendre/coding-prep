#include <iostream>
#include <vector>

using namespace std;

/*
BUBBLE SORT: 
repeatedly swap adjacent elements if they are in the wrong
order. 
 5 1 4 2 8 => 1 5 4 2 8 => 1 4 5 2 8 => 
 1 4 2 5 8

1 2 4 5 8 and that's it

NOTE: algorithm NEEDS to do one whole pass to without any
swaps to know if it's sorted

*/

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size()-1; i++) {
		for (int j = 0; j < arr.size()-i-1; j++) {
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

// optimized version of bubble sort (stop algorithm if 
// inner loop doesn't swap)

void optimizedBubbleSort(vector<int>& arr) {
	bool swapped;

	for (int i = 0; i < arr.size()-1; i++) {
		swapped = false;
		for (int j = 0; j < arr.size()-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
	// if no 2 elements were swapped by inner loop, then break;
	if (!swapped) 
		break;
	}
}

// recursive bubble sort 
// 1. base: if array size is 1, return
// 2. do one pass of bubble sort to fix last element of current subarray
// 3. recurse for all elements except last element of current subarray
void recursiveBubbleSort(vector<int>& arr, int n) {
	// base case: 
	if (n == 1) {
		return;
	}

	// one pass of bubble sort so the largest element is moved to the end
	for (int j = 0; j < n - 1; j++) {
		if (arr[j] > arr[j+1])
			swap(arr[j], arr[j+1]);
	}

	// fixed the last element, now call the recursive case
	recursiveBubbleSort(arr, n-1);
}

// insertion sort: 
/*
similar to the way we sort playing cards in our hands
12 11 13 5 6 ; loop for i = 1 to 5 => 11 12 13 5 6
loop for i = 2 => 11 12 13 5 6
loop for i = 3 => 5 11 12 13 6
loop for i = 4 => 5 6 11 12 13
*/

/* Function to sort an array using insertion sort*/
void insertionSort(vector<int>& arr, int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

/*
mergesort
- divide input array into 2, call itself for the 2 havles
and then merges

*/

void merge(vector<int>& arr, int l, int r, int m) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// make temp vectors
	vector<int>L(n1);
	vector<int>R(n2);

	for (i = 0; i < n1; i++) {
		L[i] = arr[l+i];
	}

	for (j = 0; j < n2; j++) {
		R[j] = arr[m+j+1];
	}

	// merge temp arrays back into arr[]
	i = 0; j = 0; k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[i]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// copy any remaining elements of L if any
	while (i < n1) {
		arr[k] = L[i];
		i++; k++;
	}
	// copy remaining elements of R if any
	while (j < n2) {
		arr[k] = R[j];
		j++; k++;
	}
}

void mergesort(vector<int>& arr, int l, int r) {
	int middle;
	if (r > l) {
		middle = (l+r)/2;
		mergesort(arr, l, middle);
		mergesort(arr, middle+1, r);
		merge(arr, l, r, middle);
	}
}

int main() {
	vector<int> arr = {64, 25, 12, 22, 11};
	int n = arr.size();
	mergesort(arr, 0, arr.size()-1);

	cout << "sorted array: " << endl;
	printArray(arr);

	return 0;

}