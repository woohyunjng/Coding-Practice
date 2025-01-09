#include <bits/stdc++.h>
#define int long long

#define MAX 50100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, X = 0;
    tp K;

    vector<pr> temp, arr;
    vector<tp> F;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A >> B, temp.push_back({A, B});

    sort(temp.begin(), temp.end());
    for (pr i : temp) {
        while (!arr.empty() && arr.back().second <= i.second)
            arr.pop_back();
        arr.push_back(i);
    }

    N = arr.size();
    for (int i = 1; i <= N; i++) {
        A = arr[i - 1].first, B = arr[i - 1].second;
        K = {B, dp[i - 1], 0};

        while (!F.empty()) {
            K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
            if (F.back()[2] < K[2])
                break;
            F.pop_back();
            if (F.size() == X)
                --X;
        }
        F.push_back(K);

        while (X + 1 < F.size() && F[X + 1][2] < A)
            X++;
        dp[i] = F[X][0] * A + F[X][1];
    }

    cout << dp[N] << '\n';

    return 0;
}