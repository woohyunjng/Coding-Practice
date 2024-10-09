#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, M, A;
    vector<int> arr, arr_cp;

    cin >> K >> M;
    for (int i = 1; i <= K; i++)
        arr.push_back(i);

    while (M--) {
        cin >> A;
        arr_cp.clear();
        for (int i = 0; i < arr.size(); i++)
            if ((i + 1) % A != 0)
                arr_cp.push_back(arr[i]);
        arr = arr_cp;
    }

    for (int i : arr)
        cout << i << '\n';

    return 0;
}