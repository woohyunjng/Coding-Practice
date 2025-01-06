#include <bits/stdc++.h>
#define int long long

#define MAX 5100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
int dp[MAX], val[MAX];
bool checked[MAX];

void dfs(int K) {
    checked[K] = true;
    val[K]++;

    for (int i : arr[K]) {
        if (!checked[i])
            dfs(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, Y, N, M, A, B, resX = 0, resY = 0, resXY = 0;
    cin >> X >> Y >> N >> M;

    while (M--) {
        cin >> A >> B;
        arr[++A].push_back(++B);
    }

    for (int i = 1; i <= N; i++) {
        fill(checked, checked + N + 1, false);
        dfs(i);
        for (int j = 1; j <= N; j++) {
            if (checked[j])
                dp[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (N - dp[i] < X)
            resX++;
        if (N - dp[i] < Y)
            resY++;
        if (val[i] > Y)
            resXY++;
    }

    cout << resX << '\n';
    cout << resY << '\n';
    cout << resXY;

    return 0;
}