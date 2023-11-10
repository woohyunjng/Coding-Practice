#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, A;
    vector<int> arr;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr.push_back(A);
    }

    for (auto i = arr.end() - 1; i >= arr.begin(); i--)
        cout << *i << ' ';
}