T = int(input())

for i in range(T):
    N = int(input())
    if N <= 1:
        print(2)
        continue

    j = N

    while True:
        for k in range(2, int(j**0.5) + 1):
            if not j % k:
                break
        else:
            print(j)
            break
        j += 1
