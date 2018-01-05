#include <iostream>
#include <vector>

using namespace std;

int simpleArraySum(int n, vector<int>& arr) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	return sum;
}

int main() {
	int n; 
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // read in all the elements to vector
	}

	int result = simpleArraySum(n, arr); // store result of function;
	cout << result << endl;
}