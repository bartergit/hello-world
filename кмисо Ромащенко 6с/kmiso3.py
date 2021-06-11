from tabulate import tabulate


def print_table(matrix):
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print('\n'.join(table))


def calculate(needed, hire_cost, doing_nothing_cost):
    needed = list(reversed(needed))
    maximum = max(needed) + 1
    table = [['-'] * maximum for _ in range(len(needed))]
    for i in range(len(needed)):
        j_range = range(needed[i + 1], maximum) if i != len(needed) - 1 else range(0, 1)
        for j in j_range:
            if i == 0:
                cost = hire_cost(needed[i] - j)
                # cost += doing_nothing_cost(j - needed[i])
                cell = cost, needed[i] - j
            if i != 0:
                start_with = needed[i]
                k = 0
                costs = []
                while start_with + k < maximum:
                    d = start_with - j + k
                    cost = table[i - 1][j + d][0] + hire_cost(d) + doing_nothing_cost(j + d - needed[i])
                    costs.append((cost, d))
                    k += 1
                min_cost = min(costs, key=lambda x: x[0])[0]
                costs = list(filter(lambda x: x[0] == min_cost, costs))
                cell = min_cost, "/".join([str(x[1]) for x in costs]) if len(costs) > 1 else costs[0][1]
            table[i][j] = cell
    table = list(reversed([[str(x)[1:-1] for x in row] for row in table]))
    print(tabulate(table, list(range(maximum)), tablefmt="grid"))


def main():
    hire_cost = lambda n: 7 + 4 * n if n > 0 else 0
    doing_nothing_cost = lambda n: 4 * n if n > 0 else 0
    calculate([8, 1, 4, 3, 6], hire_cost, doing_nothing_cost)
    # hire_cost = lambda n: 5 + 6 * n if n > 0 else 0
    # doing_nothing_cost = lambda n: 6 * n if n > 0 else 0
    # calculate([3, 2, 1, 4, 6], hire_cost, doing_nothing_cost)
    # hire_cost = lambda n: 5 + 1 * n if n > 0 else 0
    # doing_nothing_cost = lambda n: 6 * n if n > 0 else 0
    # calculate([5, 6, 3, 4, 6, 9], hire_cost, doing_nothing_cost)


if __name__ == '__main__':
    main()
