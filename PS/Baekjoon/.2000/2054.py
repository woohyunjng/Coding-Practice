from re import split

S = input()


def getString(string):
    if len(string) == 1:
        return [string]
    new_string = getString(string[1:])
    res = []
    for i in ["", "+", "-", "*"]:
        for j in new_string:
            res.append(i.join([string[0], j]))

    return res


strings = getString(S)
res = []


for string in strings:
    nums = split(r"[\+\*-]", string)
    for i in nums:
        if len(i) >= 2 and i[0] == "0":
            break
    else:
        if eval(string) == 2000:
            res.append(string)


for i in sorted(res):
    print(i)
