import pdb
# this solution assumes an argument that is a valid nxn matrix
def rotate(mtx):
    length = len(mtx)
    # row iteration
    for i in range(length/2):
        # column iteration
        for j in range(i, length - i - 1):
            # now, we swap 4 items at a time
            # "top" item goes into temp variable
            tmp = mtx[i][j]
            # work backwards
            mtx[i][j] = mtx[length - j - 1][i]
            mtx[length - j - 1][i] = mtx[length - i - 1][length - j - 1]
            mtx[length - i - 1][length - j - 1] = mtx[j][length - i - 1]
            mtx[j][length - i - 1] = tmp
    return mtx

def printmtx(mtx):
    for i in mtx:
        tmp = ''
        for item in i:
            tmp += str(item) + " "
        print(tmp)

def main():
    l1 = [[1,2,3],[4,5,6],[7,8,9]]
    print('Before:')
    printmtx(l1)
    l1 = rotate(l1)
    print('After:')
    printmtx(l1)

main()
