#include <bits/stdc++.h>
#define int long long

using namespace std;

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f

int A[MAX];

void solve() {
    int N, K, X = 1;
    cin >> N >> K;

    if (N == 1 && K == 1) {
        cout << "YES\n";
        cout << 1 << '\n';
        return;
    }

    if (K == 1 || (N % 2 == 0 && K % 2 == 1)) {
        cout << "NO\n";
        return;
    }

    if (N <= 9) {
        for (int i = 1; i <= N; i++) {
            X *= i;
        }
        if (X < K || X - 1 == K) {
            cout << "NO\n";
            return;
        }
    }

    vector<vector<int>> res;

    if (K % 2 == 0) {
        K /= 2;
        vector<int> lst2(N);
        iota(lst2.begin(), lst2.end(), 1);

        for (int x = 1; x <= K; x++) {
            res.push_back(lst2);
            vector<int> lst22(N);
            for (int i = 0; i < N; i++) {
                lst22[i] = N - lst2[i] + 1;
            }
            res.push_back(lst22);
            next_permutation(lst2.begin(), lst2.end());
        }
    } else {
        K -= 3;
        vector<int> lstA(N), lstB(N), lstC(N);

        iota(lstA.begin(), lstA.end(), 1);
        int c = N - 1;
        for (int i = 0; i < N; i++) {
            lstB[i] = c;
            c = (c - 2 + N) % N;
            if (c == 0)
                c = N;
        }
        for (int i = (N + 1) / 2; i < N; i++) {
            lstC[i - (N + 1) / 2] = i + 1;
        }
        for (int i = 0; i < (N + 1) / 2; i++) {
            lstC[N / 2 + i] = i + 1;
        }

        res.push_back(lstA);
        res.push_back(lstB);
        res.push_back(lstC);

        vector<int> lst2(N);
        iota(lst2.begin(), lst2.end(), 1);

        K /= 2;

        while (K) {
            vector<int> lstX = lst2;
            vector<int> lstY(N);
            for (int i = 0; i < N; i++) {
                lstY[i] = N - lst2[i] + 1;
            }

            if (lstX == lstA || lstX == lstB || lstX == lstC || lstY == lstA || lstY == lstB || lstY == lstC) {
                if (!next_permutation(lst2.begin(), lst2.end()))
                    break;
                continue;
            }

            K--;
            res.push_back(lstX);
            res.push_back(lstY);
            if (!next_permutation(lst2.begin(), lst2.end()))
                break;
        }
    }

    cout << "YES\n";
    for (vector<int> i : res) {
        for (int j : i)
            cout << j << ' ';
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
