#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> hex >> N;

    for (int i = 1; i <= 15; i++)
        cout << uppercase << hex << N << '*' << i << '=' << N * i << '\n';
}