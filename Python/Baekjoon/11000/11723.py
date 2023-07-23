from sys import stdin

M = int(input())
st = {i: False for i in range(1, 21)}
all_st = {i: True for i in range(1, 21)}
empt_st = {i: False for i in range(1, 21)}

for i in range(M):
    S = stdin.readline().rstrip()

    if S.startswith("add"):
        st[int(S[4:])] = True
    elif S.startswith("remove"):
        st[int(S[7:])] = False
    elif S.startswith("check"):
        print(1 if st[int(S[6:])] else 0)
    elif S.startswith("toggle"):
        st[int(S[7:])] = not st[int(S[7:])]
    elif S == "all":
        st = all_st
    elif S == "empty":
        st = empt_st
