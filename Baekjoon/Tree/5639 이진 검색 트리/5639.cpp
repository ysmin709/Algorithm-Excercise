#include <cstdio>
using namespace std;

int tree[100000];

void postOrder(int start, int end) {
    if (start == end) return;
    if (start == end - 1) {
        printf("%d\n", tree[start]);
        return;
    }

    int idx = start + 1;
    while (true) {
        if (idx >= end && tree[idx] >= tree[start]) break;
        idx++;
    }

    postOrder(start + 1, idx);
    postOrder(idx, end);

    printf("%d\n", tree[start]);
}

int main(void) {
    int size;
    for (size = 0; scanf("%d", tree + size) > 0; size++);

    postOrder(0, size);
}