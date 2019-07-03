# Originates from:
# https://github.com/ansko/dpd_analyzers
# /commit/???
# /plot_mmt_distance.py

'''
This is a toll to compare exfoliation tempos.
'''


import math
import random
import sys

import matplotlib as mpl
import matplotlib.pyplot as plt


if __name__ == '__main__':
    regime = sys.argv[1]

    title = ''
    fnames = []
    legends = []
    ylims = []

    if regime == 'poly_mod_likeness':
        title = 'Полимер и хвост модификатора отталкиваются слабо'
        fnames = ['outs/' + regime + "_" + str(idx) for idx in range(4)]
        legends = [
            '100, ave', '100, closest',
            '200, ave', '200, closest',
            '300, ave', '300, closest',
            '400, ave', '400, closest'
        ]
        ylims = [0, 5]
    elif regime == 'article_params':
        title = 'Параметры из статей итальянцев'
        fnames = ['outs/' + regime + "_" + str(idx) for idx in range(4)]
        legends = [
            '100, ave', '100, closest',
            '200, ave', '200, closest',
            '300, ave', '300, closest',
            '400, ave', '400, closest'
        ]
        ylims = [0, 5]
    elif regime == 'npt_attraction':
        title = ('Полимер и хвост модификатора отталкиваются слабо'
                 '\nно (a_ij большие)')
        fnames = ['outs/' + regime + "_" + str(idx) for idx in range(4)]
        legends = [
            '100, ave', '100, closest',
            '200, ave', '200, closest',
            '300, ave', '300, closest',
            '400, ave', '400, closest'
        ]
        ylims = [0, 5]

    else:
        raise NotImplemented

    xlabel = r'Время, k$\tau$'
    ylabel = r'Расстояние в $r_c$ ($r_c$ = 5.23$\AA$)'
    out_fname = regime + '.pdf'

    colors = list('rgbk')
    plotted_lines = []
    for idx, fname in enumerate(fnames):
        xs = []
        ys = []
        ys2 = []
        for line in open(fname).readlines():
            xs.append(float(line.split()[0]))
            ys.append(float(line.split()[1]))
            try:
                ys2.append(float(line.split()[2]))
            except IndexError:
                pass
        color = random.choice(colors)
        colors.pop(colors.index(color))
        new_line, = plt.plot(xs, ys, color, label=legends[idx], linewidth=3)
        plotted_lines.append(new_line)
        new_line, = plt.plot(xs, ys2, color, label=legends[idx], linewidth=1)
        plotted_lines.append(new_line)
        

    plt.title(title)
    plt.gca().set_ylim(ylims)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.legend(plotted_lines, legends, fontsize=8)
    plt.savefig(out_fname)

    print('Successful finish for', regime)
