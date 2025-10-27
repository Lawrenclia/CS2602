#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int person_id;
    int group_id;
    Node* next;
};

Node* head = nullptr; 
Node* tail = nullptr; 

int* group_ids = nullptr;

int next_person = 1;
int n = 0;

unordered_map<int, Node*> group_tails;

void enqueue() {
    if (next_person > n) {
        return;
    }

    int current_person_id = next_person;
    int current_group_id = group_ids[current_person_id];

    Node* newNode = new Node{ current_person_id, current_group_id, nullptr };

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        auto it = group_tails.find(current_group_id);
        Node* insertion_point = nullptr;

        if (it != group_tails.end()) {
            insertion_point = it->second;
        }

        if (insertion_point == nullptr) {

            tail->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = insertion_point->next;
            insertion_point->next = newNode;
            if (insertion_point == tail) {
                tail = newNode;
            }
        }
    }

    group_tails[current_group_id] = newNode;

    next_person++;
}


void dequeue() {
    if (head == nullptr) {
      
        cout << "-1" << endl;
    }
    else {
    
        cout << head->person_id << endl;

        int dequeued_group_id = head->group_id;
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        auto it = group_tails.find(dequeued_group_id);

        if (it != group_tails.end() && it->second == temp) {

            group_tails.erase(it);
        }

        delete temp;
    }
}

int main() {
    cin >> n;

    group_ids = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> group_ids[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int event_type;
        cin >> event_type;
        if (event_type == 0) {
            enqueue();
        }
        else {
            dequeue();
        }
    }

    delete[] group_ids;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}