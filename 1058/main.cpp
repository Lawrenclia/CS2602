#include <iostream>
#include <cstdio>

using namespace std;

namespace LIST
{
    struct NODE {
        int val;
        NODE* next;
        NODE(int v) : val(v), next(nullptr) {}
    };

    NODE* head = nullptr;
    NODE* tail = nullptr; // �Ż�������βָ�룬����O(1)ʱ�����β��
    int len = 0;

    void init() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    NODE* move(int i) {
        if (!head) return nullptr;
        NODE* p = head;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        return p;
    }

    void insert(int i, int x) {
        NODE* newNode = new NODE(x);
        len++;
        if (head == nullptr) { // ���������
            head = tail = newNode;
            newNode->next = head;
            return;
        }
        if (i == 0) { // ͷ������
            newNode->next = head;
            head = newNode;
            tail->next = head; // O(1) ����
        }
        else if (i == len - 1) { // β������
            newNode->next = head;
            tail->next = newNode;
            tail = newNode; // O(1) ����
        }
        else { // �м����
            NODE* prev = move(i - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    void remove(int i) {
        if (len == 0) return;

        NODE* toDelete;
        len--;
        if (len == 0) { // ɾ��������Ϊ��
            toDelete = head;
            head = tail = nullptr;
        }
        else if (i == 0) { // ͷ��ɾ��
            toDelete = head;
            head = head->next;
            tail->next = head; // O(1) ����
        }
        else {
            NODE* prev = move(i - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (i == len) { // ���ɾ�����Ǿɵ�β���
                tail = prev;
            }
        }
        delete toDelete;
    }

    void remove_insert(int i) {
        if (len <= 1 || i == len - 1) { // ֻ��һ�������ƶ�ĩβ��㣬����������
            return;
        }

        if (i == 0) { // ��ͷ����Ƶ�β�����൱������
            tail = head;
            head = head->next;
        }
        else { // ���м����Ƶ�β��
            NODE* prev = move(i - 1);
            NODE* target = prev->next;

            // �����жϿ� target
            prev->next = target->next;

            // �� target ���ӵ�β��
            tail->next = target;
            target->next = head;
            tail = target; // ����βָ��
        }
    }

    void get_length() {
        cout << len << endl;
    }

    void query(int i) {
        if (i < 0 || i >= len) {
            cout << -1 << endl;
        }
        else {
            NODE* target = move(i);
            cout << target->val << endl;
        }
    }

    void get_max() {
        if (head == nullptr) {
            cout << -1 << endl;
            return;
        }
        int max_val = head->val;
        NODE* p = head->next;
        // ʹ�� do-while ѭ���������ܸ�����ѭ�����������
        if (len > 1) {
            do {
                if (p->val > max_val) {
                    max_val = p->val;
                }
                p = p->next;
            } while (p != head);
        }
        cout << max_val << endl;
    }

    void clear() {
        if (head == nullptr) return;

        // �Ͽ�����ʹ���Ϊ��ͨ��������ɾ��
        tail->next = nullptr;
        NODE* current = head;
        while (current != nullptr) {
            NODE* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        len = 0;
    }
}

int n;

int main() {
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch (op) {
        case 0:
            LIST::get_length();
            break;
        case 1:
            cin >> p >> x;
            LIST::insert(p, x);
            break;
        case 2:
            cin >> p;
            LIST::query(p);
            break;
        case 3:
            cin >> p;
            LIST::remove(p);
            break;
        case 4:
            cin >> p;
            LIST::remove_insert(p);
            break;
        case 5:
            LIST::get_max();
            break;
        }
    }
    LIST::clear();
    return 0;
}