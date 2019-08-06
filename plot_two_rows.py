import matplotlib as mpl
import matplotlib.pyplot as plt
import sys


'''
1 26.9815
2 24.305
3 28.0855
4 15.9994
5 15.9994
6 15.9994
7 15.9994
8 1.00797
9 14.0067
10 12.0112
11 12.0112
12 1.00797
13 1.00797
14 12.0112
15 15.9994
16 14.0067
17 14.0067
'''

if __name__ == '__main__':
    fname = sys.argv[1]

    xlabel = '1 from ' + fname
    ylabel = '2 from ' + fname
    out_fname = fname + '.pdf'

    lines = open(fname).readlines()
    xs = [float(line.split()[0]) for line in lines]
    ys = [float(line.split()[1]) for line in lines]
    plotted_lines = [plt.plot(xs, ys, 'k', linewidth=1)]

    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    #plt.gca().set_xlim([0, 10])
    plt.savefig(out_fname)
