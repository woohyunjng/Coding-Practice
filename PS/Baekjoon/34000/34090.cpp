#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, ans;
    vector<int> comp;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 0; i < N; i++)
        cnt[lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin()]++;

    ans = N * (N - 1) / 2 + 1;
    for (int i = 0; i < S; i++)
        ans -= cnt[i] * (cnt[i] - 1) / 2;

    cout << ans << '\n';

    return 0;
}