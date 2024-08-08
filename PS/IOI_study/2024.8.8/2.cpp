#include "nostl.h"
#include <cstdio>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;

class Stack {
  public:
    int cur, arr[MAX];

    Stack() { cur = 0; }
    void push(int X) { arr[++cur] = X; }
    bool empty() { return cur == 0; }
    int pop() {
        if (empty())
            return -1;
        return arr[cur--];
    }

    int size() { return cur; }
    int top() {
        if (empty())
            return -1;
        return arr[cur];
    }
};

signed main() {
    int N, X;
    char query[10];
    Stack st;

    scanf("%lld", &N);
    while (N--) {
        scanf("%s", query);
        if (query[0] == 'P' && query[1] == 'U') {
            scanf("%lld", &X);
            st.push(X);
        } else if (query[0] == 'P') {
            printf("%lld\n", st.pop());
        } else if (query[0] == 'T') {
            printf("%lld\n", st.top());
        }
    }

    printf("%lld\n", st.size());
    for (int i = 1; i <= st.size(); i++)
        printf(" %lld", st.arr[i]);

    return 0;
}