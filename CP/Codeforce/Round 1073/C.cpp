#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int A[MAX];

void solve() {
    int N, cnt[2] = {0, 0};
    string S;
    vector<int> ans;

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        A[i] = S[i] - '0', cnt[A[i]]++;

    for (int i = 0; i < cnt[0]; i++)
        if (A[i] == 1)
            ans.push_back(i);
    for (int i = cnt[0]; i < N; i++)
        if (A[i] == 0)
            ans.push_back(i);

    if (ans.empty() || cnt[0] == 0 || cnt[1] == 0)
        cout << "Bob" << '\n';
    else {
        cout << "Alice" << '\n';
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i + 1 << ' ';
        cout << '\n';
    }
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