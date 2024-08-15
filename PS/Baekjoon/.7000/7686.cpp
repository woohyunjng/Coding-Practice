#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1234567891
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    long double st = 0, en = 1, mid, res;
    vector<long double> temp;

    while (true) {
        cin >> N >> K;
        if (!N)
            break;

        for (int i = 1; i <= N; i++)
            cin >> arr[i][0];
        for (int i = 1; i <= N; i++)
            cin >> arr[i][1];

        st = 0, en = 100;
        while (en - st >= 0.0000000000001) {
            mid = (st + en) / 2, res = 0;
            temp.clear();

            for (int i = 1; i <= N; i++)
                temp.push_back(arr[i][0] * 100 - mid * arr[i][1]);
            sort(temp.begin(), temp.end(), greater<int>());

            for (int i = 0; i < N - K; i++)
                res += temp[i];

            if (res >= 0)
                st = mid;
            else
                en = mid;
        }

        cout << round(st) << '\n';
    }

    return 0;
}