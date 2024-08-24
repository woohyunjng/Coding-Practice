#include <bits/stdc++.h>
#define int long long

#define MAX 1010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Cow {
    int S, T, R;

    int calculate(int K) {
        int X = K / (S * T), res = 0;
        res = X * T;

        if (K % (S * T) == 0)
            res += (X - 1) * R;
        else
            res += X * R + ceil((double)(K % (S * T)) / S);
        return res;
    }
};

Cow arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= K; i++)
        cin >> arr[i].S >> arr[i].T >> arr[i].R;

    for (int i = 1; i <= K; i++)
        cout << arr[i].calculate(N) << '\n';

    return 0;
}