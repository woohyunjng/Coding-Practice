#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1234567891
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    long double st = 0, en = 1, mid, res;
    cin >> N >> K;

    vector<pr> arr(N);
    vector<long double> temp;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    while (en - st >= 0.0000000000001) {
        mid = (st + en) / 2, res = 0;
        temp.clear();

        for (pr i : arr)
            temp.push_back(i.first - mid * i.second);
        sort(temp.begin(), temp.end(), greater<int>());

        for (int i = 0; i < N - K; i++)
            res += temp[i];

        if (res >= 0)
            st = mid;
        else
            en = mid;
    }

    cout << fixed << setprecision(10) << st;

    return 0;
}