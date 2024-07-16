#include <bits/stdc++.h>
#define int long long
#define MAX 300100

using namespace std;
typedef pair<int, int> pr;

vector<pr> arr[MAX];
bool checked[MAX];
int S[MAX], dp[MAX], child[MAX], parent[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, U, V, W, A;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> U >> V >> W;
        arr[U].push_back({V, W});
        arr[V].push_back({U, W});
    }

    queue<int> q, track;
    stack<int> st;

    checked[1] = true;
    q.push(1);
    dp[1] = 0;

    while (!q.empty()) {
        A = q.front(), q.pop();
        track.push(A);
        st.push(A);
        for (pr i : arr[A]) {
            if (checked[i.first])
                continue;
            checked[i.first] = true;
            dp[i.first] = dp[A] + i.second;
            S[1] += dp[i.first];
            parent[i.first] = A;
            q.push(i.first);
        }
    }

    while (!st.empty()) {
        A = st.top(), st.pop();
        child[A]++;
        if (A == 1)
            break;

        child[parent[A]] += child[A];
    }

    while (!track.empty()) {
        A = track.front(), track.pop();
        if (A == 1)
            continue;

        S[A] = S[parent[A]] + (dp[A] - dp[parent[A]]) * (child[1] - child[A] * 2);
    }

    for (int i = 1; i <= N; i++)
        cout << S[i] << '\n';

    return 0;
}