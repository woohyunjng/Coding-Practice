#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];

pr dfs(int K, int pr) {
    pr X, res = {1, 0};

    for (int i : arr[K]) {
        if (i == pr)
            continue;
        X = dfs(i, K);
        res.first += min(X.first, X.second);
        res.second += X.first;
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    pr res;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    res = dfs(1, -1);
    cout << min(res.first, res.second);

    return 0;
}