#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1000000;
const int BUCKET = 300;

vector<int> pos[MAX];
map<pr, int> cache;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, ans, X;
    string S, _A, _B;

    cin >> S, N = S.size();

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= min(i + 1, 4); j++) {
            A = 0;
            for (int k = i - j + 1; k <= i; k++)
                A = A * 26 + (S[k] - 'a' + 1);
            pos[A].push_back(i);
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> _A >> _B, A = B = 0, ans = N;
        for (char i : _A)
            A = A * 26 + (i - 'a' + 1);
        for (char i : _B)
            B = B * 26 + (i - 'a' + 1);

        if (pos[A].empty() || pos[B].empty()) {
            cout << -1 << '\n';
            continue;
        }

        if (cache.count({min(A, B), max(A, B)})) {
            cout << cache[{min(A, B), max(A, B)}] << '\n';
            continue;
        }

        if (pos[A].size() > pos[B].size())
            swap(A, B), swap(_A, _B);

        for (int i : pos[A]) {
            X = lower_bound(pos[B].begin(), pos[B].end(), i) - pos[B].begin();
            if (X < pos[B].size())
                ans = min(ans, pos[B][X] - min(i - (int)_A.size() + 1, pos[B][X] - (int)_B.size() + 1) + 1);
            if (X > 0)
                ans = min(ans, i - min(i - (int)_A.size() + 1, pos[B][X - 1] - (int)_B.size() + 1) + 1);
        }

        cout << ans << '\n', cache[{min(A, B), max(A, B)}] = ans;
    }

    return 0;
}