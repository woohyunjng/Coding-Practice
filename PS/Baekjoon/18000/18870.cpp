#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++)
        cin >> X[i];

    vector<int> arr(X);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i = 0; i < N; i++)
        cout << lower_bound(arr.begin(), arr.end(), X[i]) - arr.begin() << ' ';
}