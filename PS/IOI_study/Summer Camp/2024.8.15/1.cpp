#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void quick_sort(vector<int> &arr, int left, int right) {
    if (left >= right)
        return;

    int pivot = arr[left + (right - left) / 2], i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        arr.push_back(A);
    }

    quick_sort(arr, 0, arr.size() - 1);
    for (int i : arr)
        cout << i << ' ';

    return 0;
}