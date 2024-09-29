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

    int N, K, A, B, res = 0;
    vector<long double> arr;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back((long double)sqrt(A * A + B * B));
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i <= N; i++)
        res = max(res, upper_bound(arr.begin(), arr.end(), arr[i] + K) - arr.begin() - i);

    cout << setprecision(6) << fixed;
    cout << (long double)100 / N * res;

    return 0;
}