import string

with open("sorted.txt", "w+") as f:
    for char in string.lowercase[:26]:
        for i in xrange(100000):
            f.write(char)
