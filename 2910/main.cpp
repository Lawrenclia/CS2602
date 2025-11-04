#include <iostream>
#include <vector>
#include <queue>       

using namespace std;

int main() {


    int n;
    cin >> n;

    priority_queue<int> lower;

    priority_queue<int> upper;  //存储较大的数据的相反数

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (lower.empty() || num <= lower.top()) {
            lower.push(num);
        } else {
            upper.push(-1 * num);
        }

        if (lower.size() > upper.size() + 1) {
            upper.push(-1 * lower.top()); 
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(-1 * upper.top()); 
            upper.pop();
        }

        if ((i + 1) % 2 != 0) {
            cout << lower.top() << "\n";
        }
    }

    return 0;
}