#include <bits/stdc++.h>
#define int long long

#define MAX 1500000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res;
    cin >> N;

    if (N == 1) {
        cout << 1;
        return 0;
    }

    vector<int> arr = {
        21,
        291,
        2817,
        2991,
        4435,
        20617,
        45421,
        69271,
        75841,
        162619,
        176569,
        284029,
        400399,
        474883,
        732031,
        778669,
        783169,
        1014109,
        1288663};

    auto iter = lower_bound(arr.begin(), arr.end(), N + 1);
    iter = prev(iter);

    cout << *iter;

    return 0;
}