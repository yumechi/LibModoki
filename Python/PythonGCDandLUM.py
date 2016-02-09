def gcd(a, b):
    if a < b:
        a,b = b,a
    while b > 0:
        r = a % b
        a,b = b,r
    return a

def arrgcd(a):
    ret = a[0]
    for i in a[1:]:
        ret = gcd(ret, i)
    return ret

def lcm(a, b):
    if a == 0 or b == 0:
        print("Error")
        return 0
    return int(a * b // gcd(a, b))

def arrlcm(a):
    ret = a[0]
    for i in a[1:]:
        ret = lcm(ret, i)
    return ret

def test():
    print(arrgcd([3, 6, 9]))
    print(arrgcd([5, 8, 10]))
    print(arrlcm([3, 6, 9]))
    print(arrlcm([5, 8, 10]))

test()
