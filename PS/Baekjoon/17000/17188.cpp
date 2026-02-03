#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 501;
const int MAX_K = 6;

int K, A[MAX][MAX_K], B[MAX_K];
bool chk[MAX];
unordered_set<uint64_t> mp;

int comp(vector<int> &arr) {
    int res = 0;
    for (int i = K; i > 0; i--)
        res = res * 500, res += arr[i];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, S = 0, X, MX = -1, ans = 0;
    vector<int> arr, val;

    set<vector<int>> st;
    pr V;

    cin >> N >> K >> C, mp.reserve(4000000), mp.max_load_factor(0.7);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            cin >> A[i][j];

    fill(B, B + K, -1);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            if (chk[j])
                continue;
            if (B[i] == -1 || A[j][i] > A[B[i]][i])
                B[i] = j;
        }
        chk[B[i]] = true, arr.push_back(B[i]), S += A[B[i]][i];
    }
    sort(arr.begin(), arr.end()), arr.insert(arr.begin(), S);
    mp.insert(comp(arr)), st.insert(arr);

    fill(chk, chk + N, false);

    for (int t = 0; t < C; t++) {
        arr = *st.rbegin(), st.erase(prev(st.end()));
        ans = arr[0];

        for (int i = 0; i < K; i++)
            chk[arr[i + 1]] = true;
        for (int i = 0; i < K; i++) {
            chk[arr[i + 1]] = false, fill(B, B + K, 0);
            for (int j = 0; j < K; j++) {
                for (int k = 0; k < K; k++)
                    if (k ^ i)
                        B[j] = max(B[j], A[arr[k + 1]][j]);
            }
            for (int j = 0; j < N; j++) {
                if (chk[j])
                    continue;
                val = arr, val[i + 1] = j, val[0] = 0;
                sort(val.begin() + 1, val.end());
                for (int k = 0; k < K; k++)
                    val[0] += max(B[k], A[j][k]);
                X = comp(val);
                if (val[0] <= MX || mp.find(X) != mp.end())
                    continue;
                st.insert(val), mp.insert(X);
            }
            chk[arr[i + 1]] = true;
        }
        for (int i = 0; i < K; i++)
            chk[arr[i + 1]] = false;

        while (st.size() > C)
            MX = max((*st.begin())[0], MX), st.erase(st.begin());
    }

    cout << ans << '\n';

    return 0;
}