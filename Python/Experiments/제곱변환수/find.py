from collections import deque, defaultdict


def get_number(N):
    S = str(N)
    l = len(S)

    res = []
    for i in range(l):
        for j in range(i, l):
            a = int(S[i : j + 1])
            res.append(
                int("".join([S[:i], str(a**2), S[j + 1 :] if j + 1 < l else ""]))
            )
            if int(a**0.5) ** 2 == a:
                res.append(
                    int(
                        "".join(
                            [S[:i], str(int(a**0.5)), S[j + 1 :] if j + 1 < l else ""]
                        )
                    )
                )

    return res


print("제곱변환수 관계 구하기")
A, B = map(int, input("두 숫자: ").split())
q = deque([[A, [A]]])
checked = defaultdict(bool)

while len(q):
    i, j = q.popleft()
    if i == B:
        break

    for k in get_number(i):
        if checked[k] or k > 10000000:
            continue
        checked[k] = True

        if k == B:
            q.appendleft([k, j + [k]])
        else:
            q.append([k, j + [k]])

print("결과:   ", " -> ".join(map(str, j)))
