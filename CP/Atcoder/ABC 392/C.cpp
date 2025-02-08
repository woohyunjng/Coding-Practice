#include <bits/stdc++.h>
#define int long long

#define MAX 400000

using namespace std;

int P[MAX], Q[MAX], val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i];
    for (int i = 1; i <= N; i++)
        cin >> Q[i], val[Q[i]] = i;

    for (int i = 1; i <= N; i++)
        cout << Q[P[val[i]]] << ' ';
    cout << '\n';

    return 0;
}