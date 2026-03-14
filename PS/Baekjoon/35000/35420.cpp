#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;
typedef array<int, 2> pr;

int N, H[MAX], T[MAX], F[8] = {1, 2, 6, 24, 120, 720, 5000, 5000};
vector<pr> arr;

int ceil_div(int X, int Y) { return (X + Y - 1) / Y; }

int calc(vector<int> &chk) {
    int res = 0;
    for (int j = 0; j < N; j++)
        T[j] = H[j];
    for (int j = 0; j < N * (N - 1) / 2; j++) {
        if (!chk[j])
            continue;
        res++;
        for (int k = arr[j][0]; k <= arr[j][1]; k++)
            T[k] -= F[N - (arr[j][1] - arr[j][0] + 1)];
    }
    for (int j = 0; j < N; j++)
        res += ceil_div(max(0, T[j]), F[min(7, N - 1)]);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int ans = 5001, X, Y;
    vector<int> perm;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> H[i];

    if (*max_element(H, H + N) == 1)
        ans = 1;
    else if (N >= 12)
        ans = 2;
    else {
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                arr.push_back({i, j});
        X = arr.size();

        if (N >= 7) {
            Y = ceil_div(N, N - 6);
            for (int i = 0; i <= Y; i++) {
                perm.clear(), perm.resize(X, 0);
                for (int j = 0; j < i; j++)
                    perm[j] = 1;
                do {
                    ans = min(ans, calc(perm));
                } while (prev_permutation(perm.begin(), perm.end()));
            }
        } else {
            for (int i = 0; i < (1 << X); i++) {
                perm.clear();
                for (int j = 0; j < X; j++)
                    perm.push_back((i & (1 << j)) >> j);
                ans = min(ans, calc(perm));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}