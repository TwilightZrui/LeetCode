import sys

const_d = 0
const_h = 1


def main():
    while True:
        rec = []
        line = map(int, sys.stdin.readline().strip().split())
        if len(line) < 2:
            return

        n, m = line[0], line[1]
        for i in range(m):
            line = map(int, sys.stdin.readline().strip().split())
            rec.append((line[0], line[1]))

        rec = sorted(rec)

        flag = True
        result = 0
        for i in range(m - 1):
            if abs(rec[i + 1][const_h] - rec[i][const_h]) > rec[i + 1][const_d] - rec[i][const_d]:
                flag = False
                print 'IMPOSSIBLE'
                break
            else:
                h = (rec[i + 1][const_d] - rec[i][const_d] + rec[i + 1][const_h] + rec[i][const_h]) / 2
                # print '---->', h
                hy_max = max(rec[i + 1][const_h], rec[i][const_h])
                result = max(result, max(hy_max, h))

        if flag:
            hy_board_max = max(rec[0][const_h] + rec[0][const_d] - 1, rec[-1][const_h] + n - rec[-1][const_d])
            result = max(hy_board_max, result)
            print result


if __name__ == '__main__':
    main()