#include <bits/stdc++.h>
#define int long long

#define MAX 20
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bitset<MAX> arr[MAX], arr_copy[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = -1, val = 0, X;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> X;
            arr[i][j] = (bool)X;
        }
    }

    for (int x = 0; x < (1 << N); x++) {
        for (int i = 1; i <= N; i++)
            arr_copy[i] = arr[i];

        val = 0;
        for (int i = 0; i < N; i++) {
            if (x & (1 << i)) {
                if (i == 0) {
                    arr_copy[1] ^= bitset<MAX>(3);
                    arr_copy[2] ^= bitset<MAX>(1);
                } else {
                    arr_copy[1] ^= bitset<MAX>(7 << (i - 1));
                    arr_copy[2] ^= bitset<MAX>(1 << i);
                }
                val++;
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!arr_copy[i][j])
                    continue;
                if (j == 0) {
                    arr_copy[i + 1] ^= bitset<MAX>(3);
                    arr_copy[i + 2] ^= bitset<MAX>(1);
                } else {
                    arr_copy[i + 1] ^= bitset<MAX>(7 << (j - 1));
                    arr_copy[i + 2] ^= bitset<MAX>(1 << j);
                }
                val++;
            }
        }

        if ((arr_copy[N] & bitset<MAX>((1 << N) - 1)) == 0) {
            if (res == -1 || res > val)
                res = val;
        }
    }

    cout << res;

    return 0;
}