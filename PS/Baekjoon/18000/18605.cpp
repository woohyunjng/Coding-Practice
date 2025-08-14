#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], B[MAX], V[MAX][2], ans[MAX];

void dnc(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int m = l + r >> 1, opt = -1, val;

    ans[m] = 0;
    for (int i = optl; i <= min(m, optr); i++) {
        val = V[i][0] + V[m - i][1];
        if (val > ans[m])
            ans[m] = val, opt = i;
    }

    dnc(l, m - 1, optl, opt), dnc(m + 1, r, opt, optr);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    vector<int> arr, val;
    multiset<int> st[2];

    cin >> T;
    while (T--) {
        cin >> N, arr.clear(), val.clear();
        st[0].clear(), st[1].clear();

        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
            if (A[i] < B[i])
                arr.push_back(i), st[0].insert(A[i]);
            else
                val.push_back(A[i]), val.push_back(B[i]);
        }

        sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] + B[x] > A[y] + B[y]; });
        sort(val.rbegin(), val.rend());

        for (int i = 0; i < arr.size(); i++) {
            V[i << 1 | 1][0] = V[i << 1][0] + (*st[0].rbegin());
            V[(i + 1) << 1][0] = V[i << 1][0] + A[arr[i]] + B[arr[i]];
            st[0].erase(st[0].find(A[arr[i]])), st[1].insert(B[arr[i]]);
            V[i << 1 | 1][0] = max(V[i << 1 | 1][0], V[(i + 1) << 1][0] - (*st[1].begin()));
        }

        for (int i = 0; i < val.size(); i++)
            V[i + 1][1] = V[i][1] + val[i];

        dnc(1, N << 1, 0, N << 1);

        for (int i = 1; i <= N << 1; i++) {
            cout << ans[i] << ' ';
            V[i][0] = V[i][1] = ans[i] = 0;
        }
        cout << '\n';
    }

    return 0;
}