M, N = map(int, input().split())
prime_list = [True for i in range(N + 1)]

for i in range(2, round(N**0.5) + 1):
    j = 2
    while i * j <= N:
        prime_list[i * j] = False
        j += 1

for j in range(M, N + 1):
    if prime_list[j]:
        print(j)
