#include "nostl.h"
#include <cstdio>
#include <cstdlib>
#define int long long

#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

signed main() {
    int N, A;
    char K;
    scanf("%lld", &N);

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = '!';

    head->left = nullptr, head->right = nullptr;
    Node *cur = head;

    while (N--) {
        scanf("%lld", &A);
        if (A == 1) {
            if (cur->left != nullptr)
                cur = cur->left;
        } else if (A == 2) {
            if (cur->right != nullptr)
                cur = cur->right;
        } else if (A == 3) {
            scanf(" %c", &K);
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = K;
            newNode->left = cur;

            if (cur->right != nullptr) {
                newNode->right = cur->right;
                cur->right->left = newNode;
            } else
                newNode->right = nullptr;

            cur->right = newNode;
            cur = cur->right;
        } else {
            if (cur->left == nullptr)
                continue;
            Node *del = (Node *)malloc(sizeof(Node));
            del = cur;
            cur = cur->left;
            if (del->right != nullptr) {
                cur->right = del->right;
                del->right->left = cur;
            } else
                cur->right = nullptr;

            free(del);
        }
    }

    head = head->right;
    while (head) {
        printf("%c", head->data);
        head = head->right;
    }

    return 0;
}