#include <iostream>
#include <vector>
using namespace std;

/*
print contents of array in reverse order
*/

int main() {
	int n;
	cout << "Enter number of items to insert into array: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Enter values to insert into array: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// to reverse: 
	while (n-- > 0) {
		cout << arr[n] << " ";
	}

	return 0;
}