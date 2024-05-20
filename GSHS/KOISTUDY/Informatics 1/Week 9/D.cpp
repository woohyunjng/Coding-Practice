int f(int N)
{
    int val = 1;
    while (N > 1)
    {
        if (N & 1)
            N = N * 3 + 1;
        else
            N /= 2;
        val++;
    }
    return val;
}