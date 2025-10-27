#include <iostream>
using namespace std;

template <class elemType>
class seqStack {
private:
	elemType* array;
	int top;
	int maxSize;
	void doubleSpace();
public:
	seqStack(int initSize = 10);
	~seqStack() { delete[] array; }
	int isEmpty() const { return top == -1; }
	int isFull() const { return top == maxSize - 1; }
	elemType getTop() const;
	void push(const elemType& x);
	void pop();

};

template <class elemType>
seqStack<elemType>::seqStack(int initSize) {
	array = new elemType[initSize];
	top = -1;
	maxSize = initSize;
}

template <class elemType>
void seqStack<elemType>::doubleSpace() {
	elemType* tmp;
	tmp = new elemType[maxSize * 2];
	for (int i = 0; i <= top; i++) {
		tmp[i] = array[i];
	}
	delete []array;
	array = tmp;
	maxSize *= 2;
}

template <class elemType>
elemType seqStack<elemType>::getTop() const {
	return array[top];
}

template <class elmeType>
void seqStack<elmeType>::push(const elmeType& x) {
	if (isFull()) doubleSpace();
	array[++top] = x;
}

template <class elemType>
void seqStack<elemType>::pop() {
	top--;
}

int main() {
	int n;
	cin >> n;

	//input height
	int* height = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	//output result
	int* result = new int[n];
	for (int i = 0; i < n; i++) {
		result[i] = 0;
	}

	seqStack<int> s;

	for (int i = 0; i < n; i++) {
		while (!s.isEmpty()&& height[i] > height[s.getTop()]) {
			int top_index = s.getTop();
			result[top_index] = i + 1;
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; ++i) {
		cout << result[i] << ' ';
	}
	cout << std::endl;

	delete[] height;
	delete[] result;
}   