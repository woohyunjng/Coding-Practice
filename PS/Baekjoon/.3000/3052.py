a = set()

for i in range(10):
    N = int(input())
    a.add(N % 42)

print(len(a))
