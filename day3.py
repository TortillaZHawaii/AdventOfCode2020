import sys

forest = sys.stdin.read().splitlines()

repeating_width = len(forest[0]) 


def no_trees_on_path(path)->int:
    no_trees = 0

    x = path[0]
    y = path[1]

    while y < len(forest):
        if forest[y][x] == '#':
            no_trees += 1
        x = (x + path[0]) % repeating_width
        y += path[1]

    return no_trees


paths = [[1,1], [3,1], [5,1], [7,1], [1,2]]

answer = 1

for slope in paths:
    answer *= no_trees_on_path(slope)

print(answer)
