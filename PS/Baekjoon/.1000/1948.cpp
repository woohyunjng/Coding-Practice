#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX], rev_arr[MAX];
int dp[MAX], in_degree[MAX], rev_in_degree[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, S, E, res = 0;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
        rev_arr[B].push_back({A, C});

        in_degree[B]++;
        rev_in_degree[A]++;
    }

    cin >> S >> E;

    queue<int> q;
    q.push(S);
    dp[S] = 0;

    while (!q.empty()) {
        A = q.front(), q.pop();
        for (pr i : arr[A]) {
            if (--in_degree[i.first] == 0)
                q.push(i.first);
            dp[i.first] = max(dp[i.first], dp[A] + i.second);
        }
    }

    cout << dp[E] << '\n';

    q.push(E);
    checked[E] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        for (pr i : rev_arr[A]) {
            if (dp[A] - i.second == dp[i.first] && checked[A]) {
                checked[i.first] = true;
                res++;
            }
            if (--rev_in_degree[i.first] == 0)
                q.push(i.first);
        }
    }

    cout << res;

    return 0;
}