#ifndef PLATELETS_DISTANCE_HPP
#define PLATELETS_DISTANCE_HPP


#include <cmath>
#include <iostream>
#include <map>
#include <vector>

#include "datafile_content.hpp"
#include "structures.hpp"


float platelets_distance(DatafileContent &dfc, size_t mmt_atom_type,
size_t platelets_count)
{
    const Atom *all_atoms = dfc.atoms();
    Atom *mmt_atoms = (Atom *)malloc(sizeof(Atom) * dfc.atoms_count());

    // Extract only MMT atoms from dfc.
    size_t mmt_atoms_found = 0;
    for (size_t idx = 0; idx < dfc.atoms_count(); idx++)
      {
        if (all_atoms[idx].type() == mmt_atom_type)
          {
            mmt_atoms[mmt_atoms_found] = all_atoms[idx];
            mmt_atoms_found++;
          }
      }

    // Map atoms onto platelets.
    if (mmt_atoms_found % platelets_count)
      {
        std::cerr << "Error: MMT platelets are not identical!\n";
        return -1;
      }
    std::map<unsigned int, std::vector<Atom> > atoms_onto_plats;
    size_t in_plat = mmt_atoms_found / platelets_count;
    {
        for (size_t plat_idx = 0; plat_idx < platelets_count; ++plat_idx)
          {
            atoms_onto_plats[plat_idx] = std::vector<Atom>();
          }
        for (size_t idx = 0; idx < mmt_atoms_found; ++idx)
          {
            size_t platelet_idx = (mmt_atoms[idx].id() - 1) / in_plat;
            atoms_onto_plats[platelet_idx].push_back(all_atoms[idx]);
          }
    }

    // Get result.
    float ave(0);
    {
        std::vector<std::vector<float> > results(platelets_count,
            std::vector<float>(platelets_count,0));
        float lx(dfc.xhi() - dfc.xlo());
        float ly(dfc.yhi() - dfc.ylo());
        float lz(dfc.zhi() - dfc.zlo());
        float big_distance(std::max(std::max(lx, ly), lz));
        for(size_t idx1 = 0; idx1 < platelets_count; ++idx1)
          {
            size_t n1(atoms_onto_plats[idx1].size());
            for(size_t idx2 = idx1 + 1; idx2 < platelets_count; ++idx2)
              {
                size_t n2(atoms_onto_plats[idx2].size());
                for (auto &atom1 : atoms_onto_plats[idx1])
                  {
                    float closest(big_distance);
                    for (auto &atom2 : atoms_onto_plats[idx2])
                      {
                        float dx(fabs(atom1.x() - atom2.x()));
                        dx = std::min(dx, lx - dx);
                        float dy(fabs(atom1.y() - atom2.y()));
                        dy = std::min(dy, ly - dy);
                        float dz(fabs(atom1.z() - atom2.z()));
                        dz = std::min(dz, lz - dz);
                        float dr(sqrt(dx*dx + dy*dy + dz*dz));
                        closest = std::min(closest, dr);
                      }
                    results[idx1][idx2] += closest / n1;
                  }
                results[idx2][idx1] = results[idx1][idx2];
              }
          }
        for(size_t idx1 = 0; idx1 < platelets_count; ++idx1)
          {
            ave += results[idx1][0];
          }
        ave /= platelets_count - 1;
    }
    return ave;
}


#endif  // PLATELETS_DISTANCE_HPP
