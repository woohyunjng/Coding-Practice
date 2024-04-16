N = int(input())
if N <= 3:
    print(N)
    exit()

res = 0

primes = [True for i in range(int(N**0.5) + 1)]
primes[0] = False
primes[1] = False

for i in range(int(N**0.5) + 1):
    if not primes[i]:
        continue
    for j in range(i * 2, int(N**0.5) + 1, i):
        primes[j] = False

prime_list = []
for i in range(int(N**0.5) + 1):
    if primes[i]:
        prime_list.append(i)

i = 0
while N > 1:
    while not N % prime_list[i]:
        N //= prime_list[i]
        print(prime_list[i], end=" ")
    i += 1
    if i >= len(prime_list) and N > 1:
        print(N)
        break
