#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P;

class SegTree {
  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1, 1), tree(n * 2 + 1, 1) {}

    int query(int l, int r) {
        int res = 1;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = (res * tree[l++]) % P;
            if (r & 1)
                res = (res * tree[--r]) % P;
        }
        return res;
    }
    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] * tree[pos ^ 1] % P;
    }
};

vector<int> arr[MAX];
int up[MAX], down[MAX], parent[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, K = 1, L;
    cin >> N >> P;

    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    queue<int> q;
    stack<int> st, st2;
    q.push(1);
    checked[1] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        st.push(A);

        for (int i : arr[A]) {
            if (checked[i])
                continue;
            checked[i] = true;
            parent[i] = A;
            q.push(i);
        }
    }

    fill(down, down + N + 1, 1);
    fill(up, up + N + 1, 1);

    while (!st.empty()) {
        A = st.top(), st.pop();
        st2.push(A);

        down[parent[A]] = down[parent[A]] * (down[A] + 1) % P;
    }

    SegTree tree(N);

    while (!st2.empty()) {
        A = st2.top(), st2.pop();

        K = 1, B = arr[A].size();
        for (int i = 1; i <= B; i++) {
            if (arr[A][i - 1] == parent[A])
                continue;
            tree.update(K++, down[arr[A][i - 1]] + 1);
        }

        L = K - 1;

        K = 1;
        for (int i = 1; i <= B; i++) {
            if (arr[A][i - 1] == parent[A])
                continue;
            up[arr[A][i - 1]] = (up[A] % P * tree.query(1, K - 1) % P * tree.query(K + 1, L) + 1) % P;
            K++;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << up[i] * down[i] % P << '\n';
    return 0;
}