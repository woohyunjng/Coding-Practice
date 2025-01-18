X = int(input())
N, res = 2, 1

while res < X:
    res *= N
    N += 1

print(N - 1)
