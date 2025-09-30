#include<iostream>
using namespace std;

class illegalSize{};

class outOfBound{};

template <class elemType>
class seqList {
private:
	elemType* list;
	int length;
	int maxSize;

	void doubleSpace() {
		elemType* tmp = new int[maxSize * 2];
		if (!tmp)
			throw illegalSize();
		for (int i = 1; i <= length; i++) {
			tmp[i] = list[i];
		}
		delete[] list;
		list = tmp;
		maxSize = 2*maxSize - 1;
	}

public:
	seqList(int size) {
		list = new elemType[size];
		if (!list) {
			throw illegalSize();
		}
		length = 0;
		maxSize = size - 1;
	}

	~seqList() { 
		delete[] list; 
	}

	int getLength() const { 
		return length; 
	}

	void insert(int pos, const elemType &x) {
		if (length == maxSize) {
			doubleSpace();
		}
		if (pos < 1 || pos > length + 1) {
			return;
		}
		for (int i = length + 1; i > pos; i--) {
			list[i] = list[i - 1];
		}
		list[pos] = x;
		length++;
	}

	void remove(int pos) {
		if (pos < 1 || pos > length) {
			return;
		}
		for (int i = pos; i < length; i++) {
			list[i] = list[i + 1];
		}
		length--;
	}

	elemType get(int pos) const {
		if (pos < 1 || pos > length) {
			throw outOfBound();
		}
		return list[pos];
	}

};

int main() {
	int length = 0;
	cin >> length;
	seqList<int> list(length + 1);

	for (int i = 1; i <= length; i++) {
		int x;
		cin >> x;
		list.insert(i, x);
	}
	int steps;
	char op;
	int pos;
	int x;

	cin >> steps;
	for (int i = 0; i < steps; i++) {
		cin >> op;
		if (op == 'I') {
			cin >> pos >> x;
			list.insert(pos, x);
		} else if (op == 'D') {
			cin >> pos;
			list.remove(pos);
		} else {
			continue;
		}
	}

	if (list.getLength() == 0) {
		cout << "EMPTY" << "\n" << endl;
	} else {
		for (int i = 1; i <= list.getLength(); i++) {

			cout << list.get(i) << " ";
		}
	}
	return 0;
}