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

    int N, A, B, K = 0;
    vector<pr> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back({A, B});
    }

    sort(arr.begin(), arr.end());
    for (pr i : arr) {
        K = max(K, i.first);
        K += i.second;
    }

    cout << K;

    return 0;
}