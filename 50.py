import math

def is_prime(x):
    if (x < 1):
        return 0
    k = 1
    a = 1
    b = 1
    n = int(math.sqrt(x))
    if (x == 1):
        return 0
    if (x == 2):
        return 1
    if (x == 3):
        return 1
    if (x == 4):
        return 0
    if (x % 2 == 0 or x % 3 == 0):
        return 0
    while (b < n):
        a = 6 * k - 1
        b = 6 * k + 1
        if (x % a == 0 or x % b == 0):
            return 0
        k += 1
    return 1

greatest = 0
gsum = 0
primes = []
for i in range(1, 1000000):
    if (is_prime(i) == 1):
        primes.append(i)
i = 0
while (i < 50000):
    j = i
    tempsum = 0
    while (tempsum < 1000000):
        tempsum = tempsum + primes[j]
        if (is_prime(tempsum) == 1):
            if (j - i > greatest):
                greatest = j - i
                gsum = tempsum
        j += 1
    i += 1
print(gsum)
