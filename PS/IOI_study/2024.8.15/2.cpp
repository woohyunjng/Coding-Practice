#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, st, en, mid, sum = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    st = 1, en = *max_element(arr + 1, arr + N + 1);
    while (st <= en) {
        mid = st + en >> 1, sum = 0;
        for (int i = 1; i <= N; i++)
            sum += max(0LL, arr[i] - mid);
        if (sum >= M)
            st = mid + 1;
        else
            en = mid - 1;
    }

    cout << en;

    return 0;
}