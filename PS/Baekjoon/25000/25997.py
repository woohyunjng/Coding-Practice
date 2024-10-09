X, Y = input().rstrip().split()
A, B = 0, 0

dir = {"N": 0, "E": 90, "S": 180, "W": 270}


def get_degree(S):
    if len(S) == 1:
        return dir[S]

    st, en = 0, 0
    if S[-2:] == "NE":
        st, en = 0, 90
        for i in range(len(S) - 3, -1, -1):
            if S[i] == "N":
                en = (st + en) / 2
            elif S[i] == "E":
                st = (st + en) / 2
    elif S[-2:] == "SE":
        st, en = 90, 180
        for i in range(len(S) - 3, -1, -1):
            if S[i] == "S":
                st = (st + en) / 2
            elif S[i] == "E":
                en = (st + en) / 2
    elif S[-2:] == "SW":
        st, en = 180, 270
        for i in range(len(S) - 3, -1, -1):
            if S[i] == "S":
                en = (st + en) / 2
            elif S[i] == "W":
                st = (st + en) / 2
    elif S[-2:] == "NW":
        st, en = 270, 360
        for i in range(len(S) - 3, -1, -1):
            if S[i] == "N":
                st = (st + en) / 2
            elif S[i] == "W":
                en = (st + en) / 2

    return (st + en) / 2


A = get_degree(X)
B = get_degree(Y)

res = min(abs(A - B), 360 - abs(A - B))
print(res)
