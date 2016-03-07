def gcd(a, b):
    if a < b:
        a,b = b,a
    while b > 0:
        r = a % b
        a,b = b,r
    return a

def arrgcd(a):
    alen = len(a)
    if alen == 3:
        return gcd(a[0], gcd(a[1], a[2]))
    elif alen == 2:
        return gcd(a[0], a[1])
    elif alen == 1:
        return a[0] # 最初から1つ
    elif alen == 0:
        return 0
    else:
        return gcd(arrgcd(a[:alen//2]), arrgcd(a[alen//2:]))

def lcm(a, b):
    if a == 0 or b == 0:
        print("Error")
        return 0
    return int(a * b // gcd(a, b))

def arrlcm(a):
    alen = len(a)
    if alen == 3:
        return lcm(a[0], lcm(a[1], a[2]))
    elif alen == 2:
        return lcm(a[0], a[1])
    elif alen == 1:
        return a[0] # 最初から1つ
    elif alen == 0:
        return 0
    else:
        return lcm(arrlcm(a[:alen//2]), arrlcm(a[alen//2:]))
"""
    # Old Version
    ret = a[0]
    for i in a[1:]:
        ret = lcm(ret, i)
    return ret
"""

def test():
    print(arrgcd([3, 6, 9]))
    print(arrgcd([5, 8, 10]))
    print(arrlcm([3, 6, 9]))
    print(arrlcm([5, 8, 10]))

test()
