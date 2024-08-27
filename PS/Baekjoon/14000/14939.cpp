#include <bits/stdc++.h>
#define int long long

#define MAX 12
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bitset<10> arr[MAX], arr_copy[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N = 10, res = -1, val = 0;
    string X;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        for (int j = 0; j < N; j++)
            arr[i][j] = X[j] == 'O';
    }

    for (int x = 0; x < 1024; x++) {
        for (int i = 1; i <= N; i++)
            arr_copy[i] = arr[i];

        val = 0;
        for (int i = 0; i < N; i++) {
            if (x & (1 << i)) {
                if (i == 0) {
                    arr_copy[1] ^= bitset<10>(3);
                    arr_copy[2] ^= bitset<10>(1);
                } else {
                    arr_copy[1] ^= bitset<10>(7 << (i - 1));
                    arr_copy[2] ^= bitset<10>(1 << i);
                }
                val++;
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!arr_copy[i][j])
                    continue;
                if (j == 0) {
                    arr_copy[i + 1] ^= bitset<10>(3);
                    arr_copy[i + 2] ^= bitset<10>(1);
                } else {
                    arr_copy[i + 1] ^= bitset<10>(7 << (j - 1));
                    arr_copy[i + 2] ^= bitset<10>(1 << j);
                }
                val++;
            }
        }

        if (arr_copy[N].none()) {
            if (res == -1 || res > val)
                res = val;
        }
    }

    cout << res;

    return 0;
}