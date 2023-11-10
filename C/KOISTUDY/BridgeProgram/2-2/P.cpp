#include <iostream>
using namespace std;

int main()
{
    int N, A;
    cin >> N;

    int arr[24] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr[A]++;
    }

    for (int i = 1; i <= 23; i++)
        cout << arr[i] << ' ';
}