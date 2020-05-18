def int_with_commas(x):
    if x < 0:
        return '-' + int_with_commas(-x)
    # build up string backwards
    result = []
    while x > 0:
        if len(result) % 4 == 3:
            result.append(',')
        result.append(str(x % 10))
        x //= 10
    return ''.join(reversed(result))


# for i in range(0, 10000, 100):
print(int_with_commas(0))