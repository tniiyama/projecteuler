import math

numberlist = []
anumbers = []
for i in range(1, 28124):
    numberlist.append(i)
for i in range(12, 28124):
    sum = 0
    for j in range(1, math.ceil(i / 2) + 1):
        if (i % j == 0):
            sum += j
    if (sum > i):
        anumbers.append(i)
print("abundants initialized")
for i in anumbers:
    for j in anumbers:
        if (j >= i):
            if (numberlist.count(i + j) == 1):
                numberlist.remove(i + j)
print("abudants removed")
sum = 0
for i in numberlist:
    sum = sum + i
print(sum)

sum2 = 0            
for i in range(28123):
    sum2 = sum2 + i
print(sum2)
