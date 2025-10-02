#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
    node(int v): val(v), next(nullptr) {}
};

void pushback(node*& head, int v) {
    if (!head) { head = new node(v); return; }
    node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new node(v);
}

void display(node* head) {
    node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << "->";
        cur = cur->next;
    }
    cout << endl;
}

void bubblesort(node* head) {
    if (!head) return;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        node* cur = head;
        while (cur->next) {
            if (cur->val > cur->next->val) {
                int t = cur->val;
                cur->val = cur->next->val;
                cur->next->val = t;
                swapped = true;
            }
            cur = cur->next;
        }
    }
}

void mergealternate(node*& head1, node*& head2) {
    node* p1 = head1;
    node* p2 = head2;
    while (p1 && p2) {
        node* n1 = p1->next;
        node* n2 = p2->next;
        p1->next = p2;
        p2->next = n1;
        p1 = n1;
        p2 = n2;
    }
    head2 = p2;
}

int main() {
    node* a = nullptr;
    pushback(a, 3);
    pushback(a, 1);
    pushback(a, 4);
    pushback(a, 2);
    cout << "list before bubble sort:" << endl;
    display(a);
    bubblesort(a);
    cout << "list after bubble sort:" << endl;
    display(a);

    node* h1 = nullptr;
    node* h2 = nullptr;
    pushback(h1, 1);
    pushback(h1, 2);
    pushback(h1, 3);
    pushback(h2, 4);
    pushback(h2, 5);
    pushback(h2, 6);
    pushback(h2, 7);
    pushback(h2, 8);
    cout << "before merging: "<< endl;
    cout << "head1: ";
    display(h1);
    cout << "head2: ";
    display(h2);

    mergealternate(h1, h2);
    cout << "after inserting alternate: "<< endl;
    cout << "head1: ";
    display(h1);
    cout << "head2: ";
    display(h2);

    return 0;
}
