#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], B[MAX];
bool chk[MAX];

void solve() {
    int N, ans = -1, S, L, R;
    bool flag = true;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], B[i] = A[i], comp.push_back(A[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    sort(B + 1, B + N + 1);
    for (int i = 1; i <= N; i++) {
        chk[i] = A[i] == B[i];
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
    }
    for (int i = 1; i < N; i++)
        flag &= A[i] <= A[i + 1];

    if (flag) {
        cout << -1 << '\n';
        return;
    }

    for (int st = 1, en = 1e9, md; st <= en;) {
        md = st + en >> 1, flag = true;
        L = lower_bound(comp.begin(), comp.end(), comp[0] + md) - comp.begin();             // [0, L]에 속하면 uni
        R = lower_bound(comp.begin(), comp.end(), comp.back() - md + 1) - comp.begin() - 1; // [0, R] 에 속하면 uni

        if (L > R)
            flag = true;
        for (int i = 1; i <= N; i++)
            if (!chk[i])
                flag &= A[i] <= R || A[i] >= L;

        if (flag)
            st = md + 1, ans = md;
        else
            en = md - 1;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}