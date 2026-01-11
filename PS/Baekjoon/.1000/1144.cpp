#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 10;
const int INF = 0x3f3f3f3f3f3f3f3f;

int N, M, K, A[MAX][MAX];
map<int, int> _dp[MAX][MAX];

int abst(vector<int> arr) {
    int res = 0;
    for (int i : arr)
        res = res * 6 + i;
    return res;
}

vector<int> rearrange(vector<int> &arr) {
    vector<int> comp, idx(6, INF);
    for (int i = 0; i < M; i++)
        if (arr[i] != 0)
            comp.push_back(arr[i]), idx[arr[i]] = min(idx[arr[i]], i);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    sort(comp.begin(), comp.end(), [&](int x, int y) { return idx[x] < idx[y]; });
    for (int i = 0; i < M; i++)
        if (arr[i] != 0)
            for (int j = 0; j < (int)comp.size(); j++)
                if (arr[i] == comp[j]) {
                    arr[i] = j + 1;
                    break;
                }
    return arr;
}

bool chk(vector<int> arr) {
    vector<int> cnt(6, 0);
    for (int i : arr)
        cnt[i]++;
    int T = 0;
    for (int i = 1; i < 6; i++)
        T += cnt[i] > 0;
    return T <= 1;
}

int dp(int X, int Y, int mask) {
    if (_dp[X][Y].find(mask) != _dp[X][Y].end())
        return _dp[X][Y][mask];

    int res = INF, T = mask, DY = (Y + 1) % M, DX = X + (Y + 1) / M, P, Q;
    vector<int> val, cnt(6, 0);

    for (int i = 0; i < M; i++)
        cnt[T % 6]++, val.push_back(T % 6), T /= 6;
    reverse(val.begin(), val.end());
    vector<int> tmp = val;

    if (X == N)
        return _dp[X][Y][mask] = chk(val) ? 0 : INF;

    if (val[0] == 0 || cnt[val[0]] > 1 || chk(val)) {
        tmp = val, T = tmp[0];
        tmp.erase(tmp.begin()), tmp.push_back(0);
        if (!(*max_element(tmp.begin(), tmp.end()) == 0 && T != 0))
            res = min(res, dp(DX, DY, abst(rearrange(tmp))));
        else
            res = 0;
    }

    if (Y == 0) {
        tmp = val, T = tmp[0];
        tmp.erase(tmp.begin()), tmp.push_back(T ? T : *max_element(tmp.begin(), tmp.end()) + 1);
        res = min(res, dp(DX, DY, abst(rearrange(tmp))) + A[X][Y]);
    } else {
        tmp = val, P = tmp[0], Q = tmp.back(), tmp.erase(tmp.begin());
        if (P == 0)
            P = -1, Q = Q ? Q : 6;
        else if (Q == 0)
            Q = P;
        tmp.push_back(Q);
        for (int j = 0; j < M; j++)
            if (tmp[j] == P)
                tmp[j] = Q;
        res = min(res, dp(DX, DY, abst(rearrange(tmp))) + A[X][Y]);
    }

    return _dp[X][Y][mask] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    K = 1;
    for (int i = 0; i < M; i++)
        K *= 6;

    cout << dp(0, 0, 0) << '\n';

    return 0;
}