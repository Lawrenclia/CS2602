#include <iostream>
using namespace std;


template <class elemType>
class seqQueue {
private:
	elemType* array;
	int maxSize;
	int front, rear;
	void doubleSpace();
public:
	seqQueue(int size = 10);
	int size() const;
	elemType getFront();
	void enQueue(const elemType& x);
	void deQueue();
	~seqQueue();
};

template <class elemType>
seqQueue<elemType>::seqQueue(int size) {
	array = new elemType[size];
	maxSize = size;
	front = rear = 0;
}

template <class elemType>
int seqQueue<elemType>::size() const {
	return (rear - front + maxSize) % maxSize;
}

template <class elemType>
elemType seqQueue<elemType>::getFront() {
	return array[front];
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType& x) {
	if (isFull()) doubleSpace();
	array[rear] = x;
	rear = (rear + 1) % maxSize;
}

template <class elemType>
void seqQueue<elemType>::deQueue() {
	if (isEmpty()) return;
	front = (front + 1) % maxSize;
}

template <class elemType>
seqQueue<elemType>::~seqQueue() {
	delete[] array;
}

template <class elemType>
void seqQueue<elemType>::doubleSpace() {
	elemType* newArray = new elemType[2 * maxSize];
	int i, j;
	for (i = 0, j = front; j != rear; i++, j = (j + 1) % maxSize) {
		newArray[i] = array[j];
	}
	delete[]array;
	array = newArray;
	front = 0;
	rear = j;
	maxSize *= 2;
}


int main() {
	int N, Q;
	int sum = 0;
	cin >> N >> Q;
	seqQueue<int> q(N + 1);
	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		q.enQueue(t);
		sum += t;
		if (q.size() > N) {
			sum -= q.getFront();
			q.deQueue();
		}
		cout << sum / q.size() << endl;
		
	}
}