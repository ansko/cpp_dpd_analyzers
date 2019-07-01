#ifndef MMT_DISTANCE_HPP
#define MMT_DISTANCE_HPP


#include "datafile_content.hpp"


float platelets_distance()
{
/*
def platelets_distance(dfc, mmt_atom_type, platelets_count):
    # extract mmt atoms
    atoms = [atom for atom in dfc.atoms if atom['atom_type_id'] == mmt_atom_type]

    # map atoms onto platelets
    platelet_atoms = {idx: [] for idx in range(platelets_count)}
    for atom in atoms:
        platelet_idx = (atom['atom_id'] - 1) // (len(atoms) // platelets_count)
        platelet_atoms[platelet_idx].append({
            'x': atom['x'], 'y': atom['y'], 'z': atom['z']})
    # get data
    data = {idx_1: {idx_2: None} for idx_1 in range(platelets_count)
        for idx_2 in range(idx_1 + 1, platelets_count)}
    lx = dfc.xhi - dfc.xlo
    ly = dfc.yhi - dfc.ylo
    lz = dfc.zhi - dfc.zlo
    big_distance = max(lx, ly, lz)
    for plat_idx_1 in range(platelets_count):
        n1 = len(platelet_atoms[plat_idx_1])
        for plat_idx_2 in range(plat_idx_1 + 1, platelets_count):
            n2 = len(platelet_atoms[plat_idx_2])
            data[plat_idx_1][plat_idx_2] = 0
            for atom1 in platelet_atoms[plat_idx_1]:
                closest = big_distance
                for atom2 in platelet_atoms[plat_idx_2]:
                    dx = abs(atom1['x'] - atom2['x']); dx = min(dx, lx - dx)
                    dy = abs(atom1['y'] - atom2['y']); dy = min(dy, ly - dy)
                    dz = abs(atom1['z'] - atom2['z']); dz = min(dz, lz - dz)
                    dr = (dx**2 + dy**2 + dz**2)**0.5
                    closest = min(closest, dr)
                data[plat_idx_1][plat_idx_2] += closest / n1
    return data


if __name__ == '__main__':
    mmt_atom_type = 1
    platelets_count = 2

    tail = 5; count = 700

    hd_dir = ('/media/anton/Seagate Expansion Drive/dpd_calculations/')

    # Weak repulsion between modifier tail and polymer
    #hd_dir += 'a34=0.5_mod_tail5_coeff3/mod_n400_poly_n50156'
    #hd_dir += 'a34=0.5_mod_tail5_coeff3/mod_n500_poly_n50096'
    #hd_dir += 'a34=0.5_mod_tail5_coeff3/mod_n600_poly_n50036'
    #hd_dir += 'a34=0.5_mod_tail5_coeff3/mod_n700_poly_n49976'
    #hd_dir += 'a34=0.5_mod_tail5_coeff3/mod_n800_poly_n49916'

    # The most usual systems with big expansion coefficients
    #hd_dir += 'coeff3_n1/mod_n400_tail5_poly_n50156'
    #hd_dir += 'coeff3_n1/mod_n500_tail5_poly_n50096'
    #hd_dir += 'coeff3_n1/mod_n600_tail5_poly_n50036'
    #hd_dir += 'coeff3_n1/mod_n700_tail5_poly_n49976'
    #hd_dir += 'coeff3_n1/mod_n800_tail5_poly_n49916'

    # 'Modifier' has no tail, i.e. it is cation (like Na+)
    #hd_dir += 'coeff3_n1_tail0/mod_n400_tail0_poly_n50356'
    #hd_dir += 'coeff3_n1_tail0/mod_n500_tail0_poly_n50346'
    #hd_dir += 'coeff3_n1_tail0/mod_n600_tail0_poly_n50336'
    #hd_dir += 'coeff3_n1_tail0/mod_n700_tail0_poly_n50326'
    hd_dir += 'coeff3_n1_tail0/mod_n800_tail0_poly_n50316'

    out_fname = '800'

    hd_dir += '/datafiles'

    fnames = ['{0}/{1}'.format(hd_dir, fname)
        for fname in sorted(os.listdir(hd_dir))]

    distance_vs_time = {}  # distances between platelets
    for idx, fname in enumerate(fnames):
        try:
            assert(len(fname.split('/')[-1].split('.')) == 3)
        except AssertionError:
            continue
        fs = int(fname.split('.')[-2]) / 1000
        dfc = DatafileContent(fname)
        data = platelets_distance(dfc, mmt_atom_type, platelets_count)
        distance_vs_time[fs] = data[0][1]
        print(idx, '/', len(fnames), data[0][1], fname.split('/')[-1])

    with open('outputs/{0}'.format(out_fname), 'w') as f:
        for k in sorted(distance_vs_time.keys()):
            print(k, distance_vs_time[k], file=f)
*/
}


#endif  // MMT_DISTANCE_HPP
