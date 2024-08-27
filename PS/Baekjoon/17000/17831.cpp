#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int parent[MAX], arr[MAX], dp[MAX][2];
vector<int> child[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, val;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        child[parent[i]].push_back(i);
    }

    stack<int> st;
    queue<int> q;

    q.push(1);
    while (!q.empty()) {
        A = q.front(), q.pop();
        st.push(A);

        for (int i : child[A])
            q.push(i);
    }

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    while (!st.empty()) {
        A = st.top(), st.pop();
        val = 0;

        for (int i : child[A])
            val += dp[i][1];
        dp[A][0] = val;

        for (int i : child[A])
            dp[A][1] = max(dp[A][1], val - dp[i][1] + dp[i][0] + arr[A] * arr[i]);
        dp[A][1] = max(dp[A][1], val);
    }

    cout << dp[1][1];

    return 0;
}