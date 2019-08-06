#include "platelets_distance.hpp"


const std::pair<float,float>
platelets_distance(DatafileContent &dfc, size_t mmt_atom_type,
size_t platelets_count)
{
    const Atom *all_atoms = dfc.atoms();

    // Extract only MMT atoms
    size_t mmt_atoms_count(0);
    // ids start from 1, so dfc.atoms()[0] is trash since it was set by key==id
    for (size_t idx = 1; idx < dfc.atoms_count(); idx++)
      {
        if (all_atoms[idx].type() == mmt_atom_type)
          {
            mmt_atoms_count++;
          }
      }
    Atom *mmt_atoms = (Atom *)malloc(sizeof(Atom) * (mmt_atoms_count + 1));
    size_t mmt_atoms_found = 0;
    // ids start from 1, so dfc.atoms()[0] is trash since it was set by key==id
    for (size_t idx = 1; idx < dfc.atoms_count(); idx++)
      {
        if (all_atoms[idx].type() == mmt_atom_type)
          {
            mmt_atoms[mmt_atoms_found + 1] = all_atoms[idx];  // trash in 0
            mmt_atoms_found++;
          }
      }

    // Map atoms onto platelets.
    if (mmt_atoms_found % platelets_count)
      {
        std::cerr << "Error: MMT platelets are not identical!\n";
        return std::make_pair<float, float>(-1, -1);
      }
    std::map<unsigned int, std::vector<Atom> > atoms_onto_plats;
    const size_t in_plat = mmt_atoms_found / platelets_count;
    {
        for (size_t plat_idx = 0; plat_idx < platelets_count; ++plat_idx)
          {
            atoms_onto_plats[plat_idx] = std::vector<Atom>();
          }
        for (size_t idx = 1; idx < mmt_atoms_found + 1; ++idx)  // trash in 0
          {
            size_t platelet_idx = (idx - 1) / in_plat;
            atoms_onto_plats[platelet_idx].push_back(all_atoms[idx]);
          }
    }

    // Get result
    float ave_closest_plat_plat(0);
    float ave_average_plat_plat(0);
    {
        // Global minimum between all distances between
        // atom of platelet i and atom of platelet j
        std::vector<std::vector<float> > closest_plat_plat(platelets_count,
            std::vector<float>(platelets_count,0));
        // Avearage of distances from atom of platelet i and 
        // closest atom of platelet j
        std::vector<std::vector<float> > average_plat_plat(platelets_count,
            std::vector<float>(platelets_count,0));

        const float lx(dfc.xhi() - dfc.xlo());
        const float ly(dfc.yhi() - dfc.ylo());
        const float lz(dfc.zhi() - dfc.zlo());
        const float big_distance(std::max(std::max(lx, ly), lz));
        for(size_t idx1 = 0; idx1 < platelets_count; ++idx1)
          {
            const size_t n1(atoms_onto_plats[idx1].size());
            for(size_t idx2 = idx1 + 1; idx2 < platelets_count; ++idx2)
              {
                const size_t n2(atoms_onto_plats[idx2].size());

                float global_min(big_distance);
                float ave_local_min(0);

                for (auto &atom1 : atoms_onto_plats[idx1])
                  {
                    float local_min(big_distance);

                    for (auto &atom2 : atoms_onto_plats[idx2])
                      {
                        float dx(fabs(atom1.x() - atom2.x()
                                      + (atom1.nx() - atom2.nx()) * lx));
                        float dy(fabs(atom1.y() - atom2.y()
                                      + (atom1.ny() - atom2.ny()) * ly));
                        float dz(fabs(atom1.z() - atom2.z()
                                      + (atom1.nz() - atom2.nz()) * lz));
                        float dr(sqrt(dx*dx + dy*dy + dz*dz));

                        global_min = std::min(global_min, dr);
                        local_min = std::min(local_min, dr);
                      }

                    ave_local_min += local_min / n1;
                  }
                closest_plat_plat[idx1][idx2] = global_min;
                closest_plat_plat[idx2][idx1] = global_min;
                average_plat_plat[idx1][idx2] = ave_local_min;
                average_plat_plat[idx2][idx1] = ave_local_min;
              }
          }
        for(size_t idx1 = 0; idx1 < platelets_count; ++idx1)
          {
            ave_closest_plat_plat += closest_plat_plat[idx1][0];
          }
        ave_closest_plat_plat /= platelets_count - 1;

        for(size_t idx1 = 0; idx1 < platelets_count; ++idx1)
          {
            ave_average_plat_plat += average_plat_plat[idx1][0];
          }
        ave_average_plat_plat /= platelets_count - 1;
    }

    free(mmt_atoms);

    return std::make_pair<float&, float&>(
        ave_average_plat_plat, ave_closest_plat_plat);
}
