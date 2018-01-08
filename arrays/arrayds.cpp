#include <iostream>
#include <vector>
using namespace std;

/*
Function to print all integers in array in reverse order
note: array is implemented as a vector in this problem
@param arr, array to reverse
@return void
*/
void reversePrint(vector<int>& array) {
	int size = array.size();
	while(size-- > 0) {
		cout << array[size] << " ";
	}
	cout << "\n";
}

int main() {
	int n;
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	reversePrint(array);

	return 0;
}