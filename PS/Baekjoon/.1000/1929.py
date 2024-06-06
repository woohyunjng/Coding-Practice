M, N = map(int, input().split())
prime = [True for i in range(N + 1)]
prime[0] = prime[1] = False

for i in range(2, int(N**0.5) + 1):
    if not prime[i]:
        continue
    for j in range(i * 2, N + 1, i):
        prime[j] = False

for i in range(M, N + 1):
    if prime[i]:
        print(i)
