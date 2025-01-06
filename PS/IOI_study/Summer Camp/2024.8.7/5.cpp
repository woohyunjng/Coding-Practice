#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void divide_and_conquer(vector<int> &arr, int bit) {
    if (!arr.size())
        return;
    else if (arr.size() == 1) {
        cout << arr[0] << ' ';
        return;
    } else if (arr.size() == 2) {
        cout << arr[1] << ' ' << arr[0] << ' ';
        return;
    }

    vector<int> left, right;
    for (int i : arr) {
        if (i & (1 << bit))
            right.push_back(i);
        else
            left.push_back(i);
    }

    divide_and_conquer(left, bit + 1);
    divide_and_conquer(right, bit + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A;
    bool avail = true;
    cin >> N;

    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        arr.push_back(A);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N - 2; i++) {
        if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
            avail = false;
            break;
        }
    }

    if (!avail)
        cout << -1;
    else
        divide_and_conquer(arr, 0);

    return 0;
}