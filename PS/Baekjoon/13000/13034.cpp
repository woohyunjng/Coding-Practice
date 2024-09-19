#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int grundy[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<int> arr;
    cin >> N;

    grundy[0] = 0;

    for (int i = 1; i <= N; i++) {
        arr.clear();
        for (int j = 0; j <= i - 2; j++)
            arr.push_back(grundy[j] ^ grundy[i - 2 - j]);

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        X = 0;

        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == X)
                X++;
            else if (arr[j] > X)
                break;
        }

        grundy[i] = X;
    }

    cout << (grundy[N] == 0 ? 2 : 1);

    return 0;
}