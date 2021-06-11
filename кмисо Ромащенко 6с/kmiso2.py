from math import gcd
from functools import reduce
from tabulate import tabulate


class Cell:
    def __init__(self, profit, amount):
        self.profit = profit
        self.amount = amount

    def __lt__(self, other):
        return self.profit < other.profit

    def __str__(self):
        if self.amount:
            return f'{self.profit} - {str(self.amount)[1:-1]} '
        else:
            return f'{self.profit} - 0 '

    def __repr__(self):
        return self.__str__()


def find_gcd(nums):
    x = reduce(gcd, nums)
    return x


def initialize_table(capacity, initial_condition):
    shift = find_gcd([num[0] for num in initial_condition])
    table = [[Cell(0, 0) for _ in range(0, capacity + shift, shift)] for __ in range(len(initial_condition))]
    for weight in range(0, capacity + shift, shift):
        amount = int(weight / initial_condition[-1][0])
        if amount < initial_condition[-1][2]:
            table[-1][int(weight / shift)] = Cell(initial_condition[-1][1] * amount, [amount, ])
        else:
            table[-1][int(weight / shift)] = Cell(initial_condition[-1][1] * initial_condition[-1][2],
                                                  [initial_condition[-1][2], ])
    return table


def how_much_fill(row, current_weight):
    if row[0] * row[2] < current_weight:
        return row[2]
    else:
        return int(current_weight / row[0])


def backpack_method(capacity, initial_condition):
    shift = find_gcd([num[0] for num in initial_condition])
    table = initialize_table(capacity, initial_condition)
    for i, row in reversed(list(enumerate(table[:-1]))):
        for j, cell in enumerate(row):
            current_max = 0
            current_amount = []
            # print('j =', j)
            for k in range(j + 1):
                # print(k * shift, ':', how_much_fill(initial_condition[i], k * shift),
                #       how_much_fill(initial_condition[i], k * shift) * initial_condition[i][1],
                #       table[i + 1][range(j + 1)[-k - 1]].profit)
                if how_much_fill(initial_condition[i], k * shift) * initial_condition[i][1] + \
                        table[i + 1][range(j + 1)[-k - 1]].profit >= current_max:

                    if how_much_fill(initial_condition[i], k * shift) * initial_condition[i][1] + \
                            table[i + 1][range(j + 1)[-k - 1]].profit > current_max:
                        current_amount = [how_much_fill(initial_condition[i], k * shift), ]
                    else:
                        current_amount.append(how_much_fill(initial_condition[i], k * shift))
                    current_max = how_much_fill(initial_condition[i], k * shift) * initial_condition[i][1] + \
                                  table[i + 1][range(j + 1)[-k - 1]].profit
            # print()
            table[i][j] = Cell(current_max, list(dict.fromkeys(current_amount)))
    return table


def main():
    capacity = 20
    initial_condition = (
        (8, 20, 2),
        (4, 46, 1),
        (8, 21, 2),
        (6, 21, 1)
    )
    # capacity = 50
    # initial_condition = (
    #     (10, 22, 2),
    #     (5, 11, 3),
    #     (20, 49, 3),
    #     (5, 26, 4)
    # )
    # capacity = 20
    # initial_condition = (
    #     (4, 14, 12),
    #     (8, 24, 4),
    #     (8, 44, 3),
    #     (6, 44, 1)
    # )
    table = backpack_method(capacity, initial_condition)
    shift = find_gcd([num[0] for num in initial_condition])
    print(tabulate(table, headers=range(0, capacity + shift, shift)))
    print('max =', max(max(i, key=lambda x: x.profit) for i in table))
    # print(*, sep='\n')


if __name__ == '__main__':
    main()
