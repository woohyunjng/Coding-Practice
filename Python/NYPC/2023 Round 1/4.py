# 100 / 100

N, M = map(int, input().split())
now = 0


def pprint(nw, S):
    if nw == 0:
        print(S.ljust(M, "-"))
    elif nw == 1:
        if (M - len(S)) % 2:
            print(
                "".join(["-" * ((M - len(S)) // 2), S, "-" * ((M - len(S) + 1) // 2)])
            )
        else:
            print("".join(["-" * ((M - len(S)) // 2), S, "-" * ((M - len(S)) // 2)]))
    else:
        print(S.rjust(M, "-"))


for i in range(N):
    S = input()
    if S == "<CENTER>":
        now = 1
    elif S == "<RIGHT>":
        now = 2
    elif S in ["</CENTER>", "</RIGHT>"]:
        now = 0
    else:
        arr = S.split()
        cur = ""
        for j in arr:
            if len(cur) >= 1 and len(cur + "-" + j) > M:
                pprint(now, cur)
                cur = j
            else:
                cur = "-".join([cur, j]) if len(cur) >= 1 else j
        pprint(now, cur)
