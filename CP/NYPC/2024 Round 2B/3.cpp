#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;

int arr[MAX][2];
vector<int> stand[4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    vector<pr> X, Y, match;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        X.push_back({arr[i][0], i});
        Y.push_back({arr[i][1], i});
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (int i = 1; i <= N; i++) {
        if (lower_bound(X.begin(), X.end(), pr(arr[i][0], i)) - X.begin() < N / 2) {
            if (lower_bound(Y.begin(), Y.end(), pr(arr[i][1], i)) - Y.begin() < N / 2)
                stand[1].push_back(i);
            else
                stand[2].push_back(i);
        } else {
            if (lower_bound(Y.begin(), Y.end(), pr(arr[i][1], i)) - Y.begin() < N / 2)
                stand[3].push_back(i);
            else
                stand[0].push_back(i);
        }
    }

    for (int i = 0; i < stand[0].size(); i++) {
        match.push_back({stand[0][i], stand[1][i]});
        res += abs(arr[stand[0][i]][0] - arr[stand[1][i]][0]) + abs(arr[stand[0][i]][1] - arr[stand[1][i]][1]);
    }

    for (int i = 0; i < stand[3].size(); i++) {
        match.push_back({stand[3][i], stand[2][i]});
        res += abs(arr[stand[3][i]][0] - arr[stand[2][i]][0]) + abs(arr[stand[3][i]][1] - arr[stand[2][i]][1]);
    }

    cout << res << '\n';
    for (pr i : match)
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}