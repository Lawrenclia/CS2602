#include <iostream>
using namespace std;

int main() {
	int n, pivot;
	cin >> n >> pivot;
	int* temp = new int[n];
	int tempSize = 0;

	int smallerCount = 0;
	int pivotCount = 0;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		
		if (val < pivot) {
			cout << val << " ";
			smallerCount++;
		}
		else if (val == pivot) {
			pivotCount++;
		}
		else {
			temp[tempSize] = val;
			tempSize++;
		}
	}

	if (pivotCount) {
		for (int i = 0; i < pivotCount; i++) {
			cout << pivot << " ";
		}
	}

	if (tempSize) {
		for (int i = 0; i < tempSize; i++) {
			cout << temp[i] << " ";
		}
	}
	cout << endl;
	if (pivotCount) {
		cout << smallerCount << " " << smallerCount + pivotCount - 1 << endl;
	} else {
		cout << -1 << " " << - 1 << endl;
	}


	delete[] temp;
	return 0;
}