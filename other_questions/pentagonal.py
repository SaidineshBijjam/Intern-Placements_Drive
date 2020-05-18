import time
def is_pentagonal(n):
    """function to check if the number is pentagonal number or not"""
    if (1 + ((24 * n) + 1) ** 0.5) % 6 == 0:
        return True
    return False

def find_pair():
    """Finds the required pair"""
    i = 1
    not_found = 1
    n, m = 0, 0
    while(not_found):
        n = (i * (3 * i - 1)) / 2
        # For every number going backwards
        for j in range(i - 1, 0, -1):
            m = (j * (3 * j - 1)) / 2
            if is_pentagonal(n - m) and is_pentagonal(n + m):
                not_found = 0
                break
                # print(n, m, n - m)
        i += 1
    return n, m

if __name__ == "__main__":
    start = time.time()
    one, two = find_pair()
    end = time.time()
    print(one, two)
    print(end - start)
    pass