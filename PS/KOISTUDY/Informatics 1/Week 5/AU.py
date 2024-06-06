N = int(input())
res = 0
for i in range(1, int(N**0.5) + 1):
    if not N % i:
        res += N // i + i

if int(N**0.5) ** 2 == N:
    res -= int(N**0.5)

print(res)
