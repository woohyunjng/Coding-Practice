#include <bits/stdc++.h>
#define int long long

#define MAX 13
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, string> pr;

pr _dp[MAX][1 << MAX];
int N, val[MAX][MAX];
vector<string> S;

pr dp(int K, int mask) {
    pr X, res = {601, ""};
    if (_dp[K][mask].first != -1)
        return _dp[K][mask];
    if (mask == (1 << N) - 1)
        return {S[K].size(), S[K]};

    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            continue;

        X = dp(i, mask | (1 << i));
        X.first += S[K].size() - val[K][i];
        X.second = S[K].substr(0, S[K].size() - val[K][i]) + X.second;

        if (X.first < res.first || (X.first == res.first && X.second < res.second))
            res = X;
    }

    return _dp[K][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int min_len = 601;
    pr K;
    string res = "", tmp;
    vector<string> S_temp;
    bool flag;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> tmp, S_temp.push_back(tmp);
    sort(S_temp.begin(), S_temp.end(), [](string a, string b) { return a.size() > b.size(); });

    for (int i = 0; i < N; i++) {
        flag = true;
        for (string j : S)
            if (j.find(S_temp[i]) != string::npos)
                flag = false;
        if (flag)
            S.push_back(S_temp[i]);
    }

    N = S.size();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            for (int k = min(S[i].size(), S[j].size()); k >= 0; k--) {
                if (S[i].substr(S[i].size() - k) == S[j].substr(0, k)) {
                    val[i][j] = k;
                    break;
                }
            }
        }

    fill(&_dp[0][0], &_dp[MAX][0], pr(-1, ""));

    for (int i = 0; i < N; i++) {
        K = dp(i, 0);
        if (K.first < min_len)
            min_len = K.first, res = K.second;
        else if (K.first == min_len && K.second < res)
            res = K.second;
    }

    cout << res << '\n';

    return 0;
}