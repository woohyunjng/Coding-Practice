N = int(input())
arr = []
boj = []

for i in range(N):
    S = input()
    if (
        S.startswith("boj.kr/")
        and S.lstrip("boj.kr/").isdecimal()
        and 1 <= int(S.lstrip("boj.kr/")) <= 30000
    ):
        boj.append(int(S.lstrip("boj.kr/")))
    else:
        arr.append((len(S), S))

arr = list(sorted(arr))
boj = list(sorted(boj))

for i, j in arr:
    print(j)
for i in boj:
    print(f"boj.kr/{i}")
