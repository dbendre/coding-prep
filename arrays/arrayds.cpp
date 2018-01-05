#include <iostream>
#include <vector>
using namespace std;

/*
print contents of array in reverse order
note: if using stack, you technically don't even have to read it into the array
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

	// to reverse using while loop: 
	/* 
	while (n-- > 0) {
		cout << arr[n] << " ";
	} */



	return 0;
}