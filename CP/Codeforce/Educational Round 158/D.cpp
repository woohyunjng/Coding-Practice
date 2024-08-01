#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int arr[MAX], dp[MAX], parent[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, A, res;
    cin >> T;

    queue<int> q;
    stack<int> st;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            dp[i] = LLONG_MAX;
            adj[i].clear();
        }

        for (int i = 2; i <= N; i++) {
            cin >> A;
            adj[A].push_back(i);
        }

        q.push(1);
        parent[1] = 0;

        while (!q.empty()) {
            A = q.front(), q.pop();
            st.push(A);
            for (int i : adj[A]) {
                q.push(i);
                parent[i] = A;
            }
        }

        while (!st.empty()) {
            A = st.top(), st.pop();
            if (A == 1) {
                cout << arr[A] + dp[A] << '\n';
                break;
            }

            if (adj[A].size() == 0)
                dp[A] = arr[A];
            else if (arr[A] <= dp[A])
                dp[A] = (arr[A] + dp[A]) / 2;

            dp[parent[A]] = min(dp[parent[A]], dp[A]);
        }
    }

    return 0;
}