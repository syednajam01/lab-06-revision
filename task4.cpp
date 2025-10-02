#include <iostream>
using namespace std;

void printboard(int* pos, int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (pos[r] == c) cout << "Q ";
            else cout << "- ";
        }
        cout << endl;
    }
}

void solverow(int row, int n, int* pos, bool* col, bool* d1, bool* d2) {
    if (row == n) {
        printboard(pos, n);
        return;
    }

    for (int c = 0; c < n; ++c) {
        int id1 = row + c;
        int id2 = row - c + n - 1;

        if (!col[c] && !d1[id1] && !d2[id2]) {
            pos[row] = c;
            col[c] = d1[id1] = d2[id2] = true;

            solverow(row+1, n, pos, col, d1, d2);
            col[c] = d1[id1] = d2[id2] = false;
        }
    }
}

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;

    if (n <= 0) return 0;

    int* pos = new int[n];
    bool* col = new bool[n];
    bool* d1 = new bool[2*n];
    bool* d2 = new bool[2*n];

    for (int i=0;i<n;i++) col[i] = false;
    for (int i=0;i<2*n;i++) {
        d1[i] = false;
        d2[i] = false;
    }
    
    cout << "solutions:";
    solverow(0, n, pos, col, d1, d2);
    delete[] pos;
    delete[] col;
    delete[] d1;
    delete[] d2;
    return 0;
}
