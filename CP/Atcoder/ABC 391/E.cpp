#include <bits/stdc++.h>
#define int long long

#define MAX 2000000
using namespace std;

int A[MAX];

int get(int x, int y) {
    if (x == y)
        return A[x];
    int S = y - x + 1, cnt[2] = {0, 0};
    for (int i = 0; i < 3; i++)
        cnt[get(x + i * S / 3, x + (i + 1) * S / 3 - 1)]++;
    return cnt[1] >= 2 ? 1 : 0;
}

int val(int x, int y, int V) {
    int S = y - x + 1, cnt[2] = {0, 0};
    vector<int> arr;

    if (S == 3) {
        for (int i = x; i <= y; i++)
            cnt[A[i]]++;
        if (cnt[V] >= 2)
            return 0;
        else if (cnt[V] == 1)
            return 1;
        else
            return 2;
    }

    for (int i = 0; i < 3; i++)
        arr.push_back(val(x + i * S / 3, x + (i + 1) * S / 3 - 1, V));
    sort(arr.begin(), arr.end());

    return arr[0] + arr[1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 1, V;
    string s;

    cin >> N >> s;
    for (int i = 1; i <= N; i++)
        S = S * 3;

    for (int i = 1; i <= S; i++)
        A[i] = s[i - 1] - '0';
    V = get(1, S);

    cout << val(1, S, V ^ 1) << '\n';

    return 0;
}