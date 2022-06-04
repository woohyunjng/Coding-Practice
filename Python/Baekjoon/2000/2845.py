L, P = map(int, input().split())
print(*map(lambda x: int(x) - L * P, input().split()))
