#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

int A[MAX], B[MAX], C[MAX], cnt[MAX], L, R, D[MAX];
bool chk[MAX];

queue<int> q;
vector<int> arr[MAX];

void dfs(int val) {
    if (val == 39606 || val == 72299 || val == 62582)
        cout << val << "ang\n";
    vector<int> us;
    int X, Y[2] = {0, 0};

    for (int i : arr[val]) {
        if (chk[i])
            continue;
        chk[i] = true, us.push_back(i);
        if (--cnt[B[i]] == 0)
            q.push(B[i]);
    }

    if (!q.empty())
        X = q.front(), q.pop(), dfs(X);

    for (int i : us)
        Y[D[B[i]] < D[A[i] == val ? C[i] : A[i]]]++;
    D[val] = Y[1] > Y[0] ? --L : ++R;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;
    vector<int> ans;

    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i];
        cnt[B[i]]++;
        arr[A[i]].push_back(i), arr[C[i]].push_back(i);
    }

    for (int i = 1; i <= M; i++) {
        ans.push_back(i);
        if (cnt[i] == 0)
            q.push(i);
    }

    X = q.front(), q.pop(), dfs(X);

    sort(ans.begin(), ans.end(), [&](int x, int y) { return D[x] < D[y]; });

    for (int i : ans)
        cout << i << ' ';
    cout << '\n';

    return 0;
}