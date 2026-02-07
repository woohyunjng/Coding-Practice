#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;

int N, A[MAX];
map<int, int> _dp[MAX];

int dp(int node, int val) {
    if (_dp[node].find(val) != _dp[node].end())
        return _dp[node][val];

    int res, X, Y;
    if ((node << 1) > N)
        res = node;
    else if ((node << 1 | 1) > N)
        res = A[node << 1] < val ? dp(node << 1, val) : node;
    else if (val < A[node << 1] && val < A[node << 1 | 1])
        res = node;
    else if (A[node << 1] < val && A[node << 1] < A[node << 1 | 1])
        return dp(node << 1, val);
    else {
        X = min(val, A[node << 1]), Y = max(val, A[node << 1]);
        if (dp(node << 1, X) < dp(node << 1 | 1, X))
            res = dp(X == val ? (node << 1) : (node << 1 | 1), val);
        else
            res = dp(X == val ? (node << 1 | 1) : (node << 1), val);
    }
    return _dp[node][val] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y;
    vector<pr> ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        if ((i << 1) <= N && (i << 1 | 1) > N) {
            if (A[i << 1] < A[i])
                swap(A[i << 1], A[i]);
        } else if ((i << 1 | 1) <= N) {
            if (A[i << 1] < A[i] && A[i << 1] < A[i << 1 | 1])
                swap(A[i << 1], A[i]);
            else if (A[i << 1 | 1] < A[i] && A[i << 1 | 1] < A[i << 1]) {
                X = min(A[i], A[i << 1]), Y = max(A[i], A[i << 1]), A[i] = A[i << 1 | 1];
                if (dp(i << 1, X) < dp(i << 1 | 1, X))
                    A[i << 1] = X, A[i << 1 | 1] = Y;
                else
                    A[i << 1] = Y, A[i << 1 | 1] = X;
            }
        }

        cout << A[i] << ' ';
    }
    cout << '\n';

    return 0;
}