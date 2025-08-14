#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int MAX = 1000001;

int X[MAX], Y[MAX];
vector<int> arr[MAX];
double dp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, S;
    double ans;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        comp.push_back(X[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        arr[lower_bound(comp.begin(), comp.end(), X[i]) - comp.begin()].push_back(Y[i]);

    for (int i = 0; i < S; i++) {
        sort(arr[i].begin(), arr[i].end()), K = arr[i].back(), arr[i].pop_back();
        while (arr[i].size() > 1)
            arr[i].pop_back();
        arr[i].push_back(K);
        if (arr[i].size() == 1)
            arr[i].push_back(K);
    }

    for (int i = 1; i < S; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + sqrt((comp[i] - comp[i - 1]) * (comp[i] - comp[i - 1]) + (arr[i][j] - arr[i - 1][k]) * (arr[i][j] - arr[i - 1][k])));

    ans = max(dp[S - 1][0], dp[S - 1][1]);
    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}