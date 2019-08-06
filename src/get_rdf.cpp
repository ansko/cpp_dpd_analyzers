#include "get_rdf.hpp"


std::map<float, float>
get_rdf(DatafileContent &dfc, std::vector<unsigned int> atom_types)
{
    std::map<float, float> result;

    const Atom *atoms = dfc.atoms();
    const unsigned int atoms_count = dfc.atoms_count();

    float lx(dfc.xhi() - dfc.xlo());
    float ly(dfc.yhi() - dfc.ylo());
    float lz(dfc.zhi() - dfc.zlo());

    for (unsigned int i = 1; i < atoms_count + 1; ++i)
      {
        if (std::find(atom_types.begin(), atom_types.end(), atoms[i].type())
            == atom_types.end())
          {
            continue;
          }
        for (unsigned int j = i + 1; j < atoms_count; ++j)
          {
            if (std::find(atom_types.begin(), atom_types.end(), atoms[j].type())
                == atom_types.end())
              {
                continue;
              }

            float dx(std::fabs(atoms[i].x() - atoms[j].x()));
            float dy(std::fabs(atoms[i].y() - atoms[j].y()));
            float dz(std::fabs(atoms[i].z() - atoms[j].z()));
            dx = std::min(dx, lx - dx);
            dy = std::min(dy, ly - dy);
            dz = std::min(dz, lz - dz);
            float dr(sqrt(dx*dx + dy*dy + dz*dz));

            dr = float(int(dr));
            if (result.find(dr) == result.end())
              {
                result[dr] = 1 / dr/dr;
              }
            else
              {
                result[dr] += 1/dr/dr;
              }
          }
      }

    return result;
}
