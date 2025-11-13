#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX];

bool find(int L, int R) {
    for (int i = L; i < R; i++) {
        if (A[i] * 2 >= A[i + 1]) {
            assert((A[i + 1] % A[i]) % 2 == 0);
            cout << A[i] << ' ' << A[i + 1] << '\n';
            return true;
        }
    }

    for (int i = L; i < R; i++)
        for (int j = i + 1; j <= R; j++)
            if ((A[j] % A[i]) % 2 == 0) {
                cout << A[i] << ' ' << A[j] << '\n';
                return true;
            }

    return false;
}

void solve() {
    int N, X;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 0)
            arr.push_back(i);
    }

    if (arr.size() >= 2) {
        cout << A[arr[0]] << ' ' << A[arr[1]] << '\n';
        return;
    }

    if (arr.empty()) {
        if (find(1, N))
            return;
    } else {
        X = arr[0];
        for (int i = 1; i < X; i++) {
            if ((A[X] % A[i]) % 2 == 0) {
                cout << A[i] << ' ' << A[X] << '\n';
                return;
            }
        }

        for (int i = X + 1; i <= N; i++) {
            if ((A[i] % A[X]) % 2 == 0) {
                cout << A[X] << ' ' << A[i] << '\n';
                return;
            }
        }

        if (find(1, X - 1))
            return;
        if (find(X + 1, N))
            return;

        for (int i = 1; i < N; i++)
            for (int j = i + 1; j <= N; j++)
                if ((A[j] % A[i]) % 2 == 0) {
                    cout << A[i] << ' ' << A[j] << '\n';
                    return;
                }
    }

    cout << -1 << '\n';
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