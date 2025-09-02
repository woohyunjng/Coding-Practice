#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX];

void solve() {
    int N, S = 0, ans = 1, X = 0;
    bool flag = false;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i : comp) {
        if (i != X + 1) {
            flag = true;
            break;
        }
        X = i, ans ^= 1;
    }

    if (!flag)
        ans ^= 1;

    cout << (ans ? "Alice" : "Bob") << '\n';
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