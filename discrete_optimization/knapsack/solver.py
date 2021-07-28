#!/usr/bin/python
# -*- coding: utf-8 -*-

from collections import namedtuple
import numpy as np
Item = namedtuple("Item", ['index', 'value', 'weight'])

def solve_it(input_data):
    # parse the input
    lines = input_data.split('\n')

    firstLine = lines[0].split()
    item_count = int(firstLine[0])
    capacity = int(firstLine[1])

    items = []

    for i in range(1, item_count+1):
        line = lines[i]
        parts = line.split()
        items.append(Item(i-1, int(parts[0]), int(parts[1])))

    taken = [0]*len(items)
    value = 0

    if item_count < 100:

        matrix = np.zeros((capacity+1, item_count+1))    
            
        def dp(k, j):
            if j == 0:
                matrix[k, j] = 0
                return 0
            elif items[j-1][2] <= k:
                matrix[k, j] = max(dp(k, j-1), items[j-1][1] + dp(k-items[j-1][2], j-1))
                return matrix[k, j]
            else:
                matrix[k, j] = dp(k, j-1)
                return matrix[k, j]

        value = int(dp(capacity, item_count))

        j = matrix.shape[0] - 1
        for i in range(matrix.shape[1]-1, 0, -1):
            if matrix[j, i] != matrix[j, i-1]:
                j = j - items[i-1][2]
                taken[i-1] = 1

    else:
        items = sorted(items, key=lambda x: x[1]/x[2], reverse=True)

        value = 0
        weight = 0

        for item in items:
            if weight + item.weight <= capacity:
                taken[item.index] = 1
                value += item.value
                weight += item.weight
    

    # prepare the solution in the specified output format
    output_data = str(value) + ' ' + str(0) + '\n'
    output_data += ' '.join(map(str, taken))
    return output_data


if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        with open(file_location, 'r') as input_data_file:
            input_data = input_data_file.read()
        print(solve_it(input_data))
    else:
        print('This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)')

# Remizov.A.Igo@sberbank.ru