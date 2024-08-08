#include "nostl.h"
#include <cstdio>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;

class Queue {
  public:
    int cur_left, cur_right, arr[MAX];

    Queue() { cur_left = 0, cur_right = 0; }
    void push(int X) { arr[++cur_right] = X; }
    bool empty() { return cur_left == cur_right; }
    int pop() {
        if (empty())
            return -1;
        return arr[++cur_left];
    }

    int size() { return cur_right - cur_left; }
    int front() {
        if (empty())
            return -1;
        return arr[cur_left + 1];
    }
    int back() {
        if (empty())
            return -1;
        return arr[cur_right];
    }
};

signed main() {
    int N, X;
    char query[10];
    Queue q;

    scanf("%lld", &N);
    while (N--) {
        scanf("%s", query);
        if (query[0] == 'P' && query[1] == 'U') {
            scanf("%lld", &X);
            q.push(X);
        } else if (query[0] == 'P') {
            printf("%lld\n", q.pop());
        } else if (query[0] == 'B') {
            printf("%lld\n", q.back());
        } else if (query[0] == 'F') {
            printf("%lld\n", q.front());
        }
    }

    printf("%lld\n", q.size());
    while (!q.empty()) {
        printf("%lld ", q.front());
        q.pop();
    }

    return 0;
}