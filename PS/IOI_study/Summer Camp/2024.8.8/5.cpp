#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pr;

vector<pr> arr[23];

int swap_first(int A) { return A == 1 ? 1 : (A == 2 ? 3 : 2); }
int swap_second(int A) { return A == 3 ? 3 : (A == 2 ? 1 : 2); }

signed main() {
    int N;
    cin >> N;
    arr[0].push_back({1, 3});
    for (int i = 1; i < N; i++) {
        for (pr j : arr[i - 1])
            arr[i].push_back({swap_first(j.first), swap_first(j.second)});
        arr[i].push_back({1, 3});
        for (pr j : arr[i - 1])
            arr[i].push_back({swap_second(j.first), swap_second(j.second)});
    }

    for (pr i : arr[N - 1])
        cout << i.first << ' ' << i.second << '\n';
}