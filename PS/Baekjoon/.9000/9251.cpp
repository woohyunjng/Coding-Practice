#include <bits/stdc++.h>
#define int long long
#define MAX 7010
using namespace std;

int S[MAX];
vector<int> idx[30];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B;
    int N, M, l = 1;

    cin >> A >> B;
    N = A.size(), M = B.size();

    fill(S, S + MAX, -1);

    for (int i = M; i--;)
        idx[B[i] - 'A'].push_back(i);

    for (int i = 0; i < N; i++) {
        for (int j : idx[A[i] - 'A']) {
            if (S[l - 1] < j)
                S[l++] = j;
            else
                S[lower_bound(S, S + l, j) - S] = j;
        }
    }

    cout << l - 1;

    return 0;
}