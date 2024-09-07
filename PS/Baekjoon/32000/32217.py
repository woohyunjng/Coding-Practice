N = int(input())
S = sum(list(map(int, input().split())))

print((N - 1) * 180 - S * 2)
