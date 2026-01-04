#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    rope<int> rp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X, rp.insert((int)rp.size() - X, i);
    for (int i : rp)
        cout << i << ' ';
    cout << '\n';

    return 0;
}