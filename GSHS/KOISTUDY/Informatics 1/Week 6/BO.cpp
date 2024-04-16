#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int L, N;
    cin >> L >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int mn = 0, mx = 0;
    for (int i = 0; i < N; i++)
    {
        mn = max(mn, min(arr[i], L - arr[i]));
        mx = max(mx, max(arr[i], L - arr[i]));
    }
    cout << mn << ' ' << mx;
}