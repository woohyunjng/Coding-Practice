#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;

int ans[MAX], C[MAX], S[MAX], sm[2][MAX];
map<pr, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> C[i] >> S[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return S[x] < S[y]; });

    for (int i : arr) {
        X += S[i], sm[0][C[i]] += S[i], sm[1][S[i]] += S[i], cnt[{C[i], S[i]}] += S[i];
        ans[i] = X - sm[0][C[i]] - sm[1][S[i]] + cnt[{C[i], S[i]}];
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    return 0;
}