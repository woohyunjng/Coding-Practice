#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sa[MAX], lcp[MAX];

void sa_lcp(string S) {
    int N = S.size(), K = 1;
    vector<int> group(N + 1, 0), next_group(N + 1, 0), rnk(N + 1, 0);

    for (int i = 0; i < N; i++) {
        sa[i] = i;
        group[i] = S[i] - 'a';
    }

    function<bool(int, int)> cmp = [&](int X, int Y) {
        if (group[X] == group[Y])
            return group[X + K] < group[Y + K];
        return group[X] < group[Y];
    };

    group[N] = -1;
    while (K <= N) {
        sort(sa, sa + N, cmp);

        for (int i = 1; i < N; i++) {
            if (cmp(sa[i - 1], sa[i]))
                next_group[sa[i]] = next_group[sa[i - 1]] + 1;
            else
                next_group[sa[i]] = next_group[sa[i - 1]];
        }

        for (int i = 0; i < N; i++)
            group[i] = next_group[i];

        K <<= 1;
    }

    int X = 0, Y, j;

    for (int i = 0; i < N; i++)
        rnk[sa[i]] = i;

    for (int i = 0; i < N; i++) {
        Y = rnk[i];
        if (Y) {
            j = sa[Y - 1];
            while (S[i + X] == S[j + X])
                X++;
            lcp[Y] = X;
            if (X)
                X--;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int N;

    cin >> S;
    N = S.size();

    sa_lcp(S);

    for (int i = 0; i < N; i++)
        cout << sa[i] + 1 << ' ';
    cout << '\n';

    cout << "x ";
    for (int i = 1; i < N; i++)
        cout << lcp[i] << ' ';

    return 0;
}