#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007

using namespace std;

int F[MAX], parent[MAX];

int find(int X) { return parent[X] = parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    if (X != Y)
        parent[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, res;
    set<int> st;

    cin >> N >> C;

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 1; i < N; i++)
        cin >> F[i];

    for (int i = 1; i < N; i++)
        if (F[i] != 0)
            uni(i, F[i] - 1);

    res = C;
    for (int i = 1; i < N; i++) {
        if (F[i])
            continue;
        st.clear();
        for (int j = F[i - 1];; j = F[j - 1]) {
            st.insert(find(j));
            if (j == 0)
                break;
        }

        res = res * (C - st.size()) % MOD;
    }

    cout << res << '\n';

    return 0;
}