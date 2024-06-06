N = int(input())
i = 2

while N > 1:
    while not N % i:
        print(i)
        N //= i
    i += 1
