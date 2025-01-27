N = int(input())
k = list(map(int, input().split()))

mx = max(k)
prime = [i for i in range(mx + 1)]
prime[0], prime[1] = 0, 1

for i in range(2, int(mx**0.5) + 1):
    if prime[i] != i:
        continue
    for j in range(i * 2, mx + 1, i):
        prime[j] = i if prime[j] == j else prime[j]

for i in k:
    while i > 1:
        print(prime[i], end=" ")
        i //= prime[i]
    print()
