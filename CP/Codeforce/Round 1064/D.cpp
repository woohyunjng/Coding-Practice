#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3000002;

int A[MAX];
bool L[MAX], R[MAX];

vector<int> arr[MAX];
set<int> stL[MAX], stR[MAX];

void solve() {
    int N, ans = 0;
    set<int>::iterator iter;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], arr[A[i]].push_back(i);
        stL[A[i]].insert(i), stR[A[i]].insert(i);
    }

    fill(L, L + N + 1, false), fill(R, R + N + 1, false);

    for (int i = 1; i <= N * 2; i++) {
        for (int j : arr[i]) {
            if (!L[j]) {
                iter = stR[i + 1].lower_bound(j);
                if (iter != stR[i + 1].begin())
                    iter = prev(iter), R[*iter] = true, L[j] = true, ans++, stR[i + 1].erase(iter);
            }

            if (!R[j]) {
                iter = stL[i + 1].lower_bound(j);
                if (iter != stL[i + 1].end())
                    L[*iter] = true, R[j] = true, ans++, stL[i + 1].erase(iter);
            }
        }
        arr[i].clear(), stL[i].clear(), stR[i].clear();
    }

    cout << N - ans << '\n';
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