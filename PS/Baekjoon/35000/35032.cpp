#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;

int X[MAX], Y[MAX], R[MAX];

bool chk(int L1, int R1, int L2, int R2) {
    if (L1 > L2)
        swap(L1, L2), swap(R1, R2);
    return L2 < R1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool flag;
    vector<int> arr, ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i] >> R[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return R[x] > R[y]; });
    for (int i : arr) {
        flag = true;
        for (int j : ans) {
            flag &= !(chk(X[i] - R[i], X[i] + R[i], X[j] - R[j], X[j] + R[j]) && chk(Y[i] - R[i], Y[i] + R[i], Y[j] - R[j], Y[j] + R[j]));
        }
        if (flag)
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << '\n';
}