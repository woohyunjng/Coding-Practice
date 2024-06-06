N = int(input())
i = 1

while True:
    if 1 + i * (i - 1) * 3 >= N:
        print(i)
        break
    i += 1
