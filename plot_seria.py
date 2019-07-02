# Originates from:
# https://github.com/ansko/dpd_analyzers
# /commit/???
# /plot_mmt_distance.py

'''
This is a toll to compare exfoliation tempos.
'''


import math
import sys

import matplotlib as mpl
import matplotlib.pyplot as plt


if __name__ == '__main__':
    regime = sys.argv[1]

    title = regime
    fnames = ['outs/' + regime + "_" + str(idx) for idx in range(4)]
    legends = ['1', '2', '3', '4']

    ylims = [0, 20]
    xlabel = r'Время, $\tau$'
    ylabel = r'Расстояние в $r_c$ ($r_c$ = 5.23$\AA$)'
    out_fname = regime + '.pdf'

    plotted_lines = []
    for idx, fname in enumerate(fnames):
        xs = []
        ys = []
        for line in open(fname).readlines():
            xs.append(float(line.split()[0]) * 1000)
            ys.append(float(line.split()[1]))
        new_line, = plt.plot(xs, ys, label=legends[idx])
        plotted_lines.append(new_line)

    plt.title(title)
    plt.gca().set_ylim(ylims)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend(plotted_lines, legends, fontsize=8)
    plt.savefig(out_fname)

    print('Finished for', regime)
