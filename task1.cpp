#include <iostream>
using namespace std;

struct node {
    int val;
    node* prev;
    node* next;
    node(int v): val(v), prev(nullptr), next(nullptr) {}
};

void pushback(node*& head, int v) {
    if (!head) {
        head = new node(v);
        return;
    }
    node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new node(v);
    cur->next->prev = cur;
}

void display(node* head) {
    node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " <-> ";
        cur = cur->next;
    }
    cout << endl;
}

void deletefront(node*& head) {
    if (!head) return;
    node* t = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete t;
}

void deletelast(node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    node* cur = head;
    while (cur->next) cur = cur->next;
    cur->prev->next = nullptr;
    delete cur;
}

void deleteatpos(node*& head, int pos) {
    if (!head || pos <= 0) return;
    if (pos == 1) {
        deletefront(head);
        return;
    }
    node* cur = head;
    int i = 1;
    while (cur && i < pos) {
        cur = cur->next;
        i++;
    }
    if (!cur) return;
    if (cur->next) cur->next->prev = cur->prev;
    if (cur->prev) cur->prev->next = cur->next;
    delete cur;
}

node* reverserecursive(node* head) {
    if (!head) return nullptr;
    node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    if (!head->prev) return head;
    return reverserecursive(head->prev);
}

int main() {
    node* head = nullptr;
    pushback(head, 10);
    pushback(head, 20);
    pushback(head, 30);
    pushback(head, 40);
    cout << "original list: "<< endl;
    display(head);

    deletefront(head);
    cout << "after delete front:" << endl;
    display(head);

    deletelast(head);
    cout << "after delete last:" << endl;
    display(head);

    deleteatpos(head, 2);
    cout << "after delete at pos 2:" << endl;
    display(head);

    pushback(head, 50);
    pushback(head, 60);
    cout << "before reverse:" << endl;
    display(head);

    head = reverserecursive(head);
    cout << "after recursive reverse:" << endl;
    display(head);

    return 0;
}
