#include <bits/stdc++.h>
#define int long long

#define MAX 1020
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX];
pr dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, cur, res = 0, X = 0, cse = 0;
    stack<pr> st;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= N; i++) {
        while (!st.empty())
            st.pop();
        cse = 0;

        for (int j = 1; j <= M; j++) {
            if (dp[i - 1][j].first == arr[i][j])
                dp[i][j] = {arr[i][j], dp[i - 1][j].second + 1};
            else
                dp[i][j] = {arr[i][j], 1};

            if (cur != arr[i][j]) {
                cse = 0;
                while (!st.empty())
                    st.pop();
                cur = arr[i][j];
            }

            X = 0;
            while (!st.empty() && st.top().first >= dp[i][j].second) {
                X += st.top().second;
                cse -= st.top().first * st.top().second;
                st.pop();
            }
            X++;
            st.push({dp[i][j].second, X});
            cse += dp[i][j].second * X;

            res += cse;
        }
    }

    cout << res;

    return 0;
}