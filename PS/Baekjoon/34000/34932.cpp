#include <bits/stdc++.h>
using namespace std;

const int MAX = 5001;

int V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool ans = false, flag;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> V[i];

    if (N % 2 == 0)
        ans = true;
    else {
        for (int i = 0; i < N; i++) {
            rotate(V, V + 1, V + N), flag = V[0] == 0;
            for (int j = 1; j < N; j++)
                flag &= V[j] == V[N - j];
            ans |= flag;
        }
    }

    cout << (ans ? "Lulu" : "Terra") << '\n';

    return 0;
}