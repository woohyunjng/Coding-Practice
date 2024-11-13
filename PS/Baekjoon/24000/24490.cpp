#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> child[MAX];
int N, K, depth[MAX], X[MAX];

void dfs(int A) {
    X[A] = K--;

    for (int i : child[A]) {
        depth[i] = depth[A] - 1;
        dfs(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        child[A + 1].push_back(i);
    }

    for (int i = 1; i <= N + 1; i++)
        reverse(child[i].begin(), child[i].end());

    cout << N + 1 << '\n';
    depth[N + 1] = N + 1, K = N;

    dfs(N + 1);

    for (int i = 1; i <= N; i++)
        cout << depth[i] * (N + 1) + X[i] << '\n';

    return 0;
}