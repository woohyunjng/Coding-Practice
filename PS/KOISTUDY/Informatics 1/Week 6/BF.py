A, B, C = map(int, input().split())
for i in range(1, A * B * C + 1):
    if not i % A and not i % B and not i % C:
        break
print(i)
