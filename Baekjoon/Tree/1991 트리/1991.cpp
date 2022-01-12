#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> arr(26, vector<char>(2, -1));

void preorder(int node) { // 전위
    if (node == -1) return;
    cout << char(node + 'A');
    preorder(arr[node][0]);
    preorder(arr[node][1]);
}

void inorder(int node) { // 중위
    if (node == -1) return;
    inorder(arr[node][0]);
    cout << char(node + 'A');
    inorder(arr[node][1]);
}

void postorder(int node) { // 후위
    if (node == -1) return;
    postorder(arr[node][0]);
    postorder(arr[node][1]);
    cout << char(node + 'A');
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        parent -= 'A';

        if (left != '.') arr[parent][0] = left - 'A';
        if (right != '.') arr[parent][1] = right - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
}