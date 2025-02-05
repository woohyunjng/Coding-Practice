#include <bits/stdc++.h>
#define int long long

#define MAX 600000

using namespace std;

int A[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    vector<int> comp;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);
    sort(comp.begin(), comp.end());

    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        V[A[i]] = i;
    }

    for (int i = N; i >= 1; i--) {
        if (A[i] != i) {
            X = comp[A[i] - 1], Y = comp[i - 1];
            swap(A[i], A[V[i]]), swap(V[A[i]], V[A[V[i]]]);

            if (--K == 0) {
                cout << min(X, Y) << ' ' << max(X, Y) << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}