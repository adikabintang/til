l = lambda x: x ** 2

arr = [1, 2, 3, 4, 5, 6]
r = map(l, arr)
print(list(r))

r = filter(lambda x: x % 2, arr)
print(list(r))
