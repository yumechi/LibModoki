def gcd(a, b)
    if a < b
        a,b = b,a
    end
    while b > 0
        r = a % b
        a = b
        b = r
    end
    return a
end

def arrgcd(a)
    a.inject{|a,b| a.gcd(b)}
end

def lcm(a, b)
    if a == 0 || b == 0
        puts "Error"
        return 0
    end
    return (a * b / gcd(a, b)).to_i
end

def arrlcm(a)
    a.inject{|a,b| a.lcm(b)}
end

puts arrgcd([3, 6, 9])
puts arrgcd([5, 8, 10])
puts arrlcm([3, 6, 9])
puts arrlcm([5, 8, 10])
