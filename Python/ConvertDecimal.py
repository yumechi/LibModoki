# please use positive value
def convert10toDecimal(
            num, # expected Integer type
            decimal, # expected Integer type
            characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", # expected upper case
            lowercharacter=False
    ):

    # decimal only can use 2 to 36
    if num < 0 and not 2 <= decimal <= len(characters):
        return None

    convertedValue = ""
    while num > 0:
        convertedValue = \
            characters[num % decimal] + convertedValue
        num //= decimal
    return convertedValue

# please use positive value
def convertDecimalto10(
            numstr, # expected String type
            decimal, # expected String type
            characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" # expected upper case
    ):

    # decimal only can use 2 to 36
    if not 2 <= decimal <= len(characters):
       return None

    numstr = numstr.upper() # use characters upper case
    powercnt = 1
    decimal10value = 0
    for chara in numstr[::-1]:
        decimal10value += powercnt * characters.index(chara)
        powercnt *= decimal

    return decimal10value

def test():
    for i in range(16, 20):
        print("\n--------- CASE DECIMAL %d ------------\n" % (i))
        for j in range(11, 50):
            converted = convert10toDecimal(num=j, decimal=i)
            print("num:%d, decimal:10 -> converted:%s, decimal:%d" \
                % (j, converted, i))
            restored = convertDecimalto10(numstr=converted, decimal=i)
            print("converted:%s decimal:%d -> num:%d, decimal:10" \
                % (converted, i, restored))
            print("\n" * 2)

if __name__=="__main__":
    test()