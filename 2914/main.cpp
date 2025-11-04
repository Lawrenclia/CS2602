#include <iostream>
#include <stack>
#include <sstream>
using namespace std;


int main() {
	string line;
	string ops;
	stack<int> s;
	getline(cin, line);

	stringstream ss(line);

	while (ss >> ops) {
		if (ops == "C") {
			s.pop();
		}
		else if (ops == "D") {
			int score = s.top();
			s.push(2 * score);
		}
		else if (ops == "+") {
			int firstScore = s.top();
			s.pop();
			int secondScore = s.top();
			int score = firstScore + secondScore;
			s.push(firstScore);
			s.push(score);
		}
		else {
			int score = stoi(ops);
			s.push(score);
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << endl;
	return 0;
}