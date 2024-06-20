#include <bits/stdc++.h>
#define int long long
#define MAX 500100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

set<int> S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, K, A, B;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> K;
        while (K--) {
            cin >> A;
            S[i].insert(A);
        }
    }

    while (Q--) {
        cin >> K;
        if (K == 1) {
            cin >> A >> B;
            if (S[A].size() < S[B].size())
                swap(S[A], S[B]);
            for (int i : S[B])
                S[A].insert(i);
            S[B].clear();

        } else if (K == 2) {
            cin >> A;
            cout << S[A].size() << '\n';
        }
    }

    return 0;
}