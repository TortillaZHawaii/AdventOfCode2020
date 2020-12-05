import sys

forest = sys.stdin.read().splitlines()

no_trees = 0

repeating_width = len(forest[0]) 

x = 3
y = 1

while y < len(forest):
    if forest[y][x] == '#':
        no_trees += 1
    x = (x + 3) % repeating_width
    y += 1

print(no_trees)