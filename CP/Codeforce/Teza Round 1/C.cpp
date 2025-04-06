#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX], B[MAX], V[MAX], X[MAX];
vector<int> idx[MAX];

void solve() {
    int N, C = 0, K = 0;
    bool flag = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], idx[i].clear();
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1; i <= N; i++)
        V[A[i]] = B[i];
    for (int i = 1; i <= N; i++)
        flag &= V[B[i]] == A[i];

    for (int i = 1; i <= N; i++) {
        if (B[i] < A[i])
            swap(A[i], B[i]);
        if (A[i] == B[i])
            C++, K = i;
        idx[A[i]].push_back(i);
    }

    flag &= N % 2 == C;

    vector<pr> arr;

    function<void(int, int)> swp = [&](int x, int y) {
        arr.push_back({x, y});
        for (int i = 0; i < idx[A[x]].size(); i++)
            if (idx[A[x]][i] == x) {
                idx[A[x]].erase(idx[A[x]].begin() + i);
                break;
            }
        for (int i = 0; i < idx[A[y]].size(); i++)
            if (idx[A[y]][i] == y) {
                idx[A[y]].erase(idx[A[y]].begin() + i);
                break;
            }
        idx[A[x]].push_back(y), idx[A[y]].push_back(x);
        swap(A[x], A[y]);
    };

    if (flag) {
        if (N % 2 == 1 && K != (N + 1) / 2)
            swp(K, (N + 1) / 2);
        for (int i = 1; i <= N / 2; i++) {
            sort(idx[A[i]].begin(), idx[A[i]].end());
            if (idx[A[i]][1] == N - i + 1)
                continue;
            swp(idx[A[i]][1], N - i + 1);
        }
    }

    if (!flag)
        cout << -1 << '\n';
    else {
        cout << arr.size() << '\n';
        for (pr i : arr)
            cout << i[0] << ' ' << i[1] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}