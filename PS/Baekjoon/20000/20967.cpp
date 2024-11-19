#include <bits/stdc++.h>
#define int long long

#define MAX 21
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int adj[MAX][MAX], dp[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, val;
    vector<char> comp;
    string S;

    cin >> S;
    N = S.size();

    for (char i : S)
        comp.push_back(i);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 0; i < N - 1; i++)
        adj[lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin()][lower_bound(comp.begin(), comp.end(), S[i + 1]) - comp.begin()]++;

    N = comp.size();
    for (int i = 1; i < (1 << N); i++) {
        dp[i] = INF;
        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j)))
                continue;
            val = dp[i ^ (1 << j)];
            for (int k = 0; k < N; k++) {
                if (i & (1 << k))
                    val += adj[j][k];
            }
            dp[i] = min(dp[i], val);
        }
    }

    cout << dp[(1 << N) - 1] + 1 << '\n';

    return 0;
}