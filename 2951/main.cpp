#include <iostream>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int* list = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	int result;
	int l = 0;
	int r = n - 1;
	int target = k - 1;
	while (l <= r) {
		if (l == r) {
			cout << list[l] << endl;
			break;
		}
		int mid = (l + r) / 2;
		swap(list[mid], list[r]);

		int pivot = list[r];
		int i = l;

		for (int j = l; j < r; j++) {
			if (list[j] <= pivot) {
				swap(list[i], list[j]);
				i++;
			}
		}
		swap(list[i], list[r]);
		if (i == target) {
			cout << list[i] << endl;
			break;
		}
		else if (i < target) {
			l = i + 1;
		}
		else {
			r = i - 1;
		}
	}

	delete[] list;
	return 0;
}