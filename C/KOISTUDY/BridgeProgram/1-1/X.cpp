#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 10000; i > 0; i /= 10)
    {
        cout << '[' << (int)(N / i) * i << "]\n";
        N %= i;
    }
}