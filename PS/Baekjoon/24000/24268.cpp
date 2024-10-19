#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, X, res = INF;
    cin >> N >> D;

    vector<int> vec;
    for (int i = 0; i < D; i++)
        vec.push_back(i);

    do {
        if (vec[0] == 0)
            continue;
        X = 0;
        for (int i = 0; i < D; i++) {
            X *= D;
            X += vec[i];
        }

        if (X > N)
            res = min(res, X);
    } while (next_permutation(vec.begin(), vec.end()));

    cout << (res == INF ? -1 : res);

    return 0;
}