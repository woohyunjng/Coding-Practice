#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, A, B, res = 0, X, Y;
    cin >> N >> L;

    vector<tp> arr;
    vector<int> comp_A, comp_B;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back({A, B, abs(A - B) + L});
        comp_A.push_back(A);
        comp_B.push_back(B);
    }

    sort(comp_A.begin(), comp_A.end());
    sort(comp_B.begin(), comp_B.end());
    comp_A.erase(unique(comp_A.begin(), comp_A.end()), comp_A.end());
    comp_B.erase(unique(comp_B.begin(), comp_B.end()), comp_B.end());

    for (int i = 0; i < N; i++)
        arr[i] = {lower_bound(comp_A.begin(), comp_A.end(), arr[i][0]) - comp_A.begin() + 1, lower_bound(comp_B.begin(), comp_B.end(), arr[i][1]) - comp_B.begin() + 1, arr[i][2]};

    sort(arr.begin(), arr.end());
    for (int i = N - 1; i >= 0; i--) {
        A = arr[i][0], B = arr[i][1];
        X = max(dp[A][0], dp[B][1] + arr[i][2]);
        Y = max(dp[B][1], dp[A][0] + arr[i][2]);

        dp[A][0] = X, dp[B][1] = Y;
        res = max({res, dp[A][0], dp[B][1]});
    }

    cout << res;

    return 0;
}