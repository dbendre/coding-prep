#include <iostream>
#include <algorithm> // note you can use sort()
using namespace std;

/*
sort array elements in non-decreasing (ascending) order

*/

bool sorting(string a, string b) {
	int x = a.length();
	int y = a.length();

	if (x == y) 
		return a < b;
	return x < y; // return ascending
}

int main() {
	int n;
	cin >> n; 
	vector<string> unsorted(n);
	for (int i = 0; i < n; i++) {
		cin >> unsorted[i]; // read in all values
	}

	sort(unsorted.begin(), unsorted.end(), sorting);
	for (int i = 0; i < n; i++) {
		cout << unsorted[i] << endl;
	} 


	return 0;
}