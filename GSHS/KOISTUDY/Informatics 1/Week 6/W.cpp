#include <iostream>
using namespace std;

int main()
{
    int N, i = 1;
    cin >> N;

    while (i * (i + 1) < 2 * N)
        i++;
    cout << i * (i + 1) / 2;
}