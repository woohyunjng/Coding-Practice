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

    int N, K, st = 0, en = 1000000, mid, res;
    cin >> N >> K;

    vector<pr> arr(N);
    vector<long double> temp;

    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    while (en > st) {
        mid = (st + en) / 2, res = 0;
        temp.clear();

        for (pr i : arr)
            temp.push_back(i.first * 1000000 - mid * i.second);
        sort(temp.begin(), temp.end(), greater<int>());

        for (int i = 0; i < K; i++)
            res += temp[i];

        if (res >= 0)
            st = mid + 1;
        else
            en = mid - 1;
    }

    cout << fixed << setprecision(6) << (double)st / 1000000;

    return 0;
}