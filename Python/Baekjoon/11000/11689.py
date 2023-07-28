N = int(input())
res = N

for i in range(2, round(N**0.5) + 1):
    if N % i:
        continue

    while not N % i:
        N //= i
    res //= i
    res *= i - 1

if N != 1:
    res //= N
    res *= N - 1

print(res)
