def spiral_order(matrix):
    if not matrix or not matrix[0]: return []
    rows = len(matrix)
    cols = len(matrix[0])
    result = []
    i = j = 0       # indices; i corresponds to row# and j to col#
    diff = [0, 1]   # index incrementation values
    cycle = 0       # a count of the number of complete loops traversed so far
    # begin spiral traverse
    for cell in range(rows * cols):
        result.append(matrix[i][j])
        # check if cycle is terminating and new inner spiral is about to start
        # (also corresponds to end of bottom to top traversal in spiral)
        if diff == [-1, 0] and i - cycle == 1:
            cycle += 1
            diff = [0, 1]
        # check if row or col traversal exceeded bounds
        elif diff == [0, 1] and j + cycle >= cols - 1:
            # reached end of left to right traversal
            diff = [1, 0]
        elif diff == [1, 0] and i + cycle >= rows - 1:
            # reached end of top to bottom traversal
            diff = [0, -1]
        elif diff == [0, -1] and j - cycle == 0:
            # reached end of right to left traversal
            diff = [-1, 0]
        i += diff[0]
        j += diff[1]
    return result
