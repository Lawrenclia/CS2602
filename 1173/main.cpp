#include <iostream>

using namespace std;

void swap(long long* a, long long* b) {
	long long t = *a;
    *a = *b; 
    *b = t;
}


void heapify(long long* arr, long long n, long long i) {
	long long largest = i;
	long long left = 2 * i + 1;
	long long right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(long long* arr, long long n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	long long* arr1 = new long long[n];
	long long* arr2 = new long long[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	heapSort(arr1, n);
	heapSort(arr2, n);
	long long result1 = 0;
	long long result2 = 0;
	for (int i = 0; i < n; i++) {
		result1 += arr1[i] * arr2[i];
		result2 += arr1[i] * arr2[n - i - 1];
	}
	cout << result1 << " " << result2 << endl;
	
	delete []arr1;
	delete[]arr2;

	return 0;
}