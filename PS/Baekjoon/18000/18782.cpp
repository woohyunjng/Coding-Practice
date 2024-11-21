#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int res[MAX], L, cnt[MAX];
vector<int> adj[MAX];

int dfs(int K, int pr) {
    vector<int> arr;
    int X, ret = 0;

    for (int i : adj[K]) {
        if (i == pr)
            continue;
        X = dfs(i, K);
        if (X == -1 || X + 1 > L)
            return -1;
        arr.push_back(X + 1);
    }

    for (int i : arr)
        cnt[i]++;

    for (int i : arr) {
        if (!cnt[i])
            continue;
        cnt[i]--;
        if (L == i)
            continue;
        else if (cnt[L - i])
            cnt[L - i]--;
        else if (ret == 0)
            ret = i;
        else
            ret = -1;
    }

    for (int i : arr)
        cnt[i] = 0;

    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i < N; i++) {
        if ((N - 1) % i != 0)
            continue;
        L = i;
        res[i] = dfs(1, 0) == 0;
    }

    for (int i = 1; i < N; i++)
        cout << res[i];
    cout << '\n';

    return 0;
}