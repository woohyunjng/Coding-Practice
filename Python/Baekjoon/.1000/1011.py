T = int(input())

for i in range(T):
    x, y = map(int, input().split())
    n = y - x

    j = 1
    while True:
        if n <= j ** 2:
            print(j * 2 - 1)
            break
        if n <= j * (j + 1):
            print(j * 2)
            break
        
        j += 1
