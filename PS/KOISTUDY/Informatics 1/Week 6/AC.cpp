#include <iostream>
using namespace std;

int main()
{
    int N, A, count[24] = {};
    cin >> N;

    while (N--)
    {
        cin >> A;
        count[A]++;
    }

    for (int i = 1; i <= 23; i++)
        cout << count[i] << ' ';
}