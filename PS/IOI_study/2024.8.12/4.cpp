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

    vector<pr> arr;
    vector<int> X, Y, res;
    int N, A, K;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        arr.push_back({A, i});
    }

    for (pr i : arr) {
        if (X.empty() || X.back() < i.first) {
            X.push_back(i.first);
            Y.push_back(X.size() - 1);
        } else {
            Y.push_back(lower_bound(X.begin(), X.end(), i.first) - X.begin());
            X[Y.back()] = i.first;
        }
    }

    K = X.size() - 1;
    for (int i = Y.size() - 1; i >= 0; i--) {
        if (Y[i] == K) {
            K--;
            res.push_back(arr[i].second);
        }
    }
    reverse(res.begin(), res.end());

    cout << res.size() << '\n';
    for (int i : res)
        cout << i << ' ';

    return 0;
}