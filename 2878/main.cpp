#include<iostream>
#include<algorithm>
using namespace std;

class outOfBound {};

template<class elemType>
class linkList;


template<class elemType>
class node {
	friend class linkList<elemType>;

private:
	elemType data;
	node<elemType>* next;

public:
	node() {
		next = NULL;
	};
	node(const elemType& e, node<elemType>* n = NULL) {
		data = e; next = n;
	};
};


template<class elemType>
class linkList {
private:
	node<elemType>* head;

public:
	linkList() {
		head = new node<elemType>;
	}

	bool isEmpty() const {
		return head->next == NULL;
	}

	int length() const {
		node<elemType>* p = head->next;
		int len = 0;
		while (p != NULL) {
			len++;
			p = p->next;
		}
		return len;
	}

	elemType get(int i) const {
		if (i < 1) {
			throw outOfBound();
		}
		int j = 1;
		node<elemType>* p = head->next;

		while (p && j < i) {
			j++;
			p = p->next;
		}
		if (p) {
			return p->data;
		}
		else {
			throw outOfBound();
		}
	}

	//插入一组元素
	void insert(const elemType* e, int n) {
		node<elemType>* tmp;
		for (int i = 0; i < n; i++) {
			tmp = new node<elemType>(e[i], head->next);
			head->next = tmp;
		}
	}

	//插入单个元素
	void insert(const elemType& e) {
		node<elemType>* tmp = new node<elemType>(e, head->next);
		head->next = tmp;
	}

	void clear() {
		node<elemType>* p = head->next;
		node<elemType>* q;
		while (p) {
			q = p->next;
			delete p;
			p = q;
		}
	}

	~linkList() {
		clear();
		delete head;
	}
};

int char2Int(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 10;
	}
	else {
		return c - 'a' + 10;
	}
}

int int2Char(int x) {
	if (x >= 0 && x <= 9) {
		return x + '0';
	}
	else if (x >= 10 && x <= 35) {
		return x - 10 + 'A';
	}
	else {
		return '0';
	}
}

template<class elemType>
int* add(elemType a[], int len1, elemType b[], int len2, int base) {
	linkList<elemType> list1, list2;
	list1.insert(a, len1); // list1: [a[len1-1], ..., a[0]]
	list2.insert(b, len2); // list2: [b[len2-1], ..., b[0]]

	linkList<elemType> result;
	int carry = 0;
	int i = 1;
	int maxLen = max(len1, len2);

	while (i <= len1 || i <= len2 || carry) {
		int sum = carry;

		if (i <= len1) {
			sum += list1.get(i);
		}
		if (i <= len2) {
			sum += list2.get(i);
		}

		if (result.length() < maxLen) {
			result.insert(sum % base);
		}
		else if (result.length() == maxLen) {
			carry = sum / base;
			i++;
			continue;
		}

		carry = sum / base;
		i++;
	}

	int* resArr = new int[result.length()];
	for (int i = 0; i < result.length(); i++) {
		resArr[i] = int2Char(result.get(i + 1));
	}
	return resArr;
}

int main() {
	int len1, len2, base;
	cin >> len1 >> len2 >> base;
	len1--;
	len2--;
	int maxLen = max(len1, len2);
	string str1, str2;
	int* arr1 = new int[len1];
	int* arr2 = new int[len2];

	cin >> str1 >> str2;

	for (int i = 0; i < len1; i++) {
		arr1[i] = char2Int(str1[i]);
	}
	for (int j = 0; j < len2; j++) {
		arr2[j] = char2Int(str2[j]);
	}

	int* res = add(arr1, len1, arr2, len2, base);
	string resStr = "";
	for (int k = 0; k < maxLen; k++) {
		resStr += res[k];
	}
	cout << resStr << endl;
	delete[] arr1;
	delete[] arr2;
	delete[] res;
	return 0;
}