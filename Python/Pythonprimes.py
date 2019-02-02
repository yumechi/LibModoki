from math import sqrt
import collections

# refer: http://cocodrips.hateblo.jp/entry/2014/02/02/011119
def prime_factorization(n):
    ret = []
    for i in range(2, int(sqrt(n) + 2)):
        while n % i == 0:
            n //= i
            ret.append(i)
    # if n not equal 1, this number is maybe prime
    if n > 1:
        ret.append(n)
    return ret

def prime_counter(n):
    return collections.Counter(prime_factorization(n))

def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def test():
    print(prime_counter(30))
    print(prime_counter(2014))
    print(prime_factorization(5030))
    print(is_prime(3033))
    print(is_prime(7))

test()
