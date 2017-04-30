/*
print contents of array in reversed order
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void reverseArr(vector<int> &arr, int start, int end) {
	int temp;
	if (start >= end)
		return;
	temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	reverseArr(arr, start+1, end-1);
}

void printArray(vector<int> &arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main() {
	int n; 
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// this is the iterative method --> O(n)
	for (int i = arr.size()-1; i >= 0; i--) {
		cout << arr[i] << " ";
	} 

	cout << endl;

	//recursive method using swap O(n)
	printArray(arr, n);
	reverseArr(arr, 0, n-1);
	// cout << "Reversed array is: " << endl;
	printArray(arr, n);

	return 0;
}