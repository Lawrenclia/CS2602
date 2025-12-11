#include <iostream>
using namespace std;


int searchfront(int* arr, int m, int n) {
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < m) {
            l = mid + 1;
        } else if (arr[mid] > m) {
            r = mid - 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int searchback(int* arr, int m, int n) {
    int l = 0;
    int r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < m) {
            l = mid + 1;
        } else if (arr[mid] > m) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1; 
        }
    }
    return ans;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int start_index = searchfront(arr, m, n);
    int end_index = searchback(arr, m, n);

    cout << start_index << " " << end_index << "\n";
    delete[] arr;
    return 0;
}
