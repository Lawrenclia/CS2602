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
    NODE* tail = nullptr; // 优化：增加尾指针，用于O(1)时间访问尾部
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
        if (head == nullptr) { // 空链表插入
            head = tail = newNode;
            newNode->next = head;
            return;
        }
        if (i == 0) { // 头部插入
            newNode->next = head;
            head = newNode;
            tail->next = head; // O(1) 操作
        }
        else if (i == len - 1) { // 尾部插入
            newNode->next = head;
            tail->next = newNode;
            tail = newNode; // O(1) 操作
        }
        else { // 中间插入
            NODE* prev = move(i - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    void remove(int i) {
        if (len == 0) return;

        NODE* toDelete;
        len--;
        if (len == 0) { // 删除后链表为空
            toDelete = head;
            head = tail = nullptr;
        }
        else if (i == 0) { // 头部删除
            toDelete = head;
            head = head->next;
            tail->next = head; // O(1) 操作
        }
        else {
            NODE* prev = move(i - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (i == len) { // 如果删除的是旧的尾结点
                tail = prev;
            }
        }
        delete toDelete;
    }

    void remove_insert(int i) {
        if (len <= 1 || i == len - 1) { // 只有一个结点或移动末尾结点，操作无意义
            return;
        }

        if (i == 0) { // 将头结点移到尾部，相当于左旋
            tail = head;
            head = head->next;
        }
        else { // 将中间结点移到尾部
            NODE* prev = move(i - 1);
            NODE* target = prev->next;

            // 从链中断开 target
            prev->next = target->next;

            // 将 target 链接到尾部
            tail->next = target;
            target->next = head;
            tail = target; // 更新尾指针
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
        // 使用 do-while 循环遍历可能更符合循环链表的语义
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

        // 断开环，使其变为普通链表，方便删除
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