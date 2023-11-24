#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, res = 0, A;
    cin >> N;

    int arr[N], max_length = 0;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N - 1; i++)
        max_length = max(max_length, arr[i + 1] - arr[i]);

    cin >> M;
    while (M--)
    {
        cin >> A;
        res += (int)(A >= max_length);
    }
    cout << res;
}