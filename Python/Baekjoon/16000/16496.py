from sys import stdin

N = int(stdin.readline())
arr = stdin.readline().rstrip().split()

arr = list(sorted(arr, key=lambda x: int((x * 20)[:10]), reverse=True))
print(int("".join(arr)))
