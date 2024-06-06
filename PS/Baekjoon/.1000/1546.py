N = int(input())
arr = list(map(int, input().split()))

M = max(arr)
sm = sum(arr) / N

print(sm / M * 100)
