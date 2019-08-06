#ifndef DATAFILE_CONTENT_HPP
#define DATAFILE_CONTENT_HPP


#include <cstdlib>
#include <cstdio>

#include <array>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>

#include "structures.hpp"
#include "char_py_string.hpp"


// Container for datafile reading
class DatafileContent
{
public:
    DatafileContent(std::string fname)
    : _fname(fname), _atoms(nullptr), _velocities(nullptr), _bonds(nullptr),
      _angles(nullptr), _dihedrals(nullptr), _impropers(nullptr), _masses(nullptr),
      _pair_coeffs(nullptr), _bond_coeffs(nullptr), _angle_coeffs(nullptr),
      _dihedral_coeffs(nullptr), _improper_coeffs(nullptr)
      {
        this->read_datafile();
      }

    ~DatafileContent()
      {
        if (this->_atoms != nullptr)
            free(this->_atoms);
        if (this->_velocities != nullptr)
            free(this->_velocities);
        if (this->_bonds != nullptr)
            free(this->_bonds);
        if (this->_angles != nullptr)
            free(this->_angles);
        if (this->_dihedrals != nullptr)
            free(this->_dihedrals);
        if (this->_impropers != nullptr)
            free(this->_impropers);
        if (this->_masses != nullptr)
            free(this->_masses);
        if (this->_pair_coeffs != nullptr)
            free(this->_pair_coeffs);
        if (this->_bond_coeffs != nullptr)
            free(this->_bond_coeffs);
        if (this->_angle_coeffs != nullptr)
            free(this->_angle_coeffs);
        if (this->_dihedral_coeffs != nullptr)
            free(this->_dihedral_coeffs);
        if (this->_improper_coeffs != nullptr)
            free(this->_improper_coeffs);
      }

    const Atom *atoms() const { return this->_atoms; }
    const Bond *bonds() const { return this->_bonds; }
    const Angle *angles() const { return this->_angles; }
    const Dihedral *dihedrals() const { return this->_dihedrals; }
    const Improper *impropers() const { return this->_impropers; }

    const std::string fname() const { return this->_fname; }
    const std::string comment() const { return this->_comment; }
    const unsigned int atoms_count() const { return this->_atoms_count; }
    const unsigned int atom_types() const { return this->_atom_types; }
    const std::tuple<float, float, float>* velocities() const
        { return this->_velocities; }
    const unsigned int bonds_count() const { return this->_bonds_count; }
    const unsigned int bond_types() const { return this->_bond_types; }
    const unsigned int angles_count() const { return this->_angles_count; }
    const unsigned int angle_types() const { return this->_angle_types; }
    const unsigned int dihedrals_count() const { return this->_dihedrals_count; }
    const unsigned int dihedral_types() const { return this->_dihedral_types; }
    const unsigned int impropers_count() const { return this->_impropers_count; }
    const unsigned int improper_types() const { return this->_improper_types; }
    const float xlo() const { return this->_xlo; }
    const float xhi() const { return this->_xhi; }
    const float ylo() const { return this->_ylo; }
    const float yhi() const { return this->_yhi; }
    const float zlo() const { return this->_zlo; }
    const float zhi() const { return this->_zhi; }
    const float xy() const { return this->_xy; }
    const float xz() const { return this->_xz; }
    const float yz() const { return this->_yz; }
    const float *masses() const { return this->_masses; }
    const std::tuple<float, float>* pair_coeffs() const
        { return this->_pair_coeffs; }
    const std::tuple<float, float>* bond_coeffs() const
        { return this->_bond_coeffs; }
    const std::tuple<float, float>* angle_coeffs() const
        { return this->_angle_coeffs; }
    const std::tuple<float, int, int>* dihedral_coeffs() const
        { return this->_dihedral_coeffs; }
    const std::tuple<float, int, int>* improper_coeffs() const
        { return this->_improper_coeffs; }

    void read_datafile()
      {
        std::vector<CharPyString> lines;
        std::string buffer_line;
        unsigned int masses_idx = 0;
        unsigned int pair_coeffs_idx = 0;
        unsigned int bond_coeffs_idx = 0;
        unsigned int angle_coeffs_idx = 0;
        unsigned int dihedral_coeffs_idx = 0;
        unsigned int improper_coeffs_idx = 0;
        unsigned int atoms_idx = 0;
        unsigned int velocities_idx = 0;
        unsigned int bonds_idx = 0;
        unsigned int angles_idx = 0;
        unsigned int dihedrals_idx = 0;
        unsigned int impropers_idx = 0;

        // Reading lines in c-style is not faster as i think;
        // also, C getline produces lines with '\n'
        std::ifstream ifs(this->_fname);
        while (std::getline(ifs, buffer_line))
          {
            lines.push_back(buffer_line.c_str());
          }

        for (size_t idx = 0; idx < lines.size(); ++idx)
          {
            if (lines[idx].endswith("atoms"))
                this->_atoms_count = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("bonds"))
                this->_bonds_count = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("angles"))
                this->_angles_count = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("dihedrals"))
                this->_dihedrals_count = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("impropers"))
                this->_impropers_count = lines[idx].word_as_float(0);

            else if (lines[idx].endswith("atom types"))
                this->_atom_types = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("bond types"))
                this->_bond_types = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("angle types"))
                this->_angle_types = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("dihedral types"))
                this->_dihedral_types = lines[idx].word_as_float(0);
            else if (lines[idx].endswith("improper types"))
                this->_improper_types = lines[idx].word_as_float(0);

            else if (lines[idx].endswith("xlo xhi"))
              {
                this->_xlo = lines[idx].word_as_float(0);
                this->_xhi = lines[idx].word_as_float(1);
              }
            else if (lines[idx].endswith("ylo yhi"))
              {
                this->_ylo = lines[idx].word_as_float(0);
                this->_yhi = lines[idx].word_as_float(1);
              }
            else if (lines[idx].endswith("zlo zhi"))
              {
                this->_zlo = lines[idx].word_as_float(0);
                this->_zhi = lines[idx].word_as_float(1);
              }
            else if (lines[idx].endswith("xy xz yz"))
              {
                this->_xy = lines[idx].word_as_float(0);
                this->_xz = lines[idx].word_as_float(1);
                this->_yz = lines[idx].word_as_float(2);
              }

            else if (lines[idx].endswith("Masses"))
                masses_idx = idx;
            else if (lines[idx].startswith("Pair Coeffs"))
                pair_coeffs_idx = idx;
            else if (lines[idx].startswith("Bond Coeffs"))
                bond_coeffs_idx = idx;
            else if (lines[idx].startswith("Angle Coeffs"))
                angle_coeffs_idx = idx;
            else if (lines[idx].startswith("Dihedral Coeffs"))
                dihedral_coeffs_idx = idx;
            else if (lines[idx].startswith("Improper Coeffs"))
                improper_coeffs_idx = idx;
            else if (lines[idx].startswith("Atoms"))
                atoms_idx = idx;
            else if (lines[idx].startswith("Velocities"))
                velocities_idx = idx;
            else if (lines[idx].startswith("Bonds"))
                bonds_idx = idx;
            else if (lines[idx].startswith("Angles"))
                angles_idx = idx;
            else if (lines[idx].startswith("Dihedrals"))
                dihedrals_idx = idx;
            else if (lines[idx].startswith("Impropers"))
                impropers_idx = idx;
          }

        if (masses_idx)
          {
            this->_masses = (float *)malloc(
                sizeof(float) * (this->_atom_types + 1));

            auto first = lines.begin() + masses_idx + 2;
            auto last = lines.begin() + masses_idx + 2 + this->_atom_types;
            for (auto &it = first; it != last; ++it)
              {
                const unsigned int key(it->word_as_float(0));
                const float mass = it->word_as_float(1);
                this->_masses[key] = mass;
              }
          }

        if (pair_coeffs_idx)
          {
            typedef std::tuple<float, float> T;
            this->_pair_coeffs = (T *)malloc(
                sizeof(T) * (this->_atom_types + 1));
            auto first = lines.begin() + pair_coeffs_idx + 2;
            auto last = lines.begin() + pair_coeffs_idx + 2 + this->_atom_types;
            for (auto &it = first; it != last; ++it)
              {
                const unsigned int key(it->word_as_float(0));
                const float eps = it->word_as_float(1);
                const float sig = it->word_as_float(2);
                this->_pair_coeffs[key] = {eps, sig};
              }
          }

        if (bond_coeffs_idx)
          {
            typedef std::tuple<float, float> T;
            this->_bond_coeffs = (T *)malloc(
                sizeof(T) * (this->_bond_types + 1));
            auto first = lines.begin() + bond_coeffs_idx + 2;
            auto last = lines.begin() + bond_coeffs_idx + 2 + this->_bond_types;
            for (auto &it = first; it != last; ++it)
              {
                const unsigned int key(it->word_as_float(0));
                const float k = it->word_as_float(1);
                const float l = it->word_as_float(2);
                this->_bond_coeffs[key] = {k, l};
              }
          }

        if (angle_coeffs_idx)
          {
            typedef std::tuple<float, float> T;
            this->_angle_coeffs = (T *)malloc(
                sizeof(T) * (this->_angle_types + 1));
            auto first = lines.begin() + angle_coeffs_idx + 2;
            auto last = lines.begin() + angle_coeffs_idx + 2 + this->_angle_types;
            for (auto &it = first; it != last; ++it)
              {
                const unsigned int key(it->word_as_float(0));
                const float k = it->word_as_float(1);
                const float theta = it->word_as_float(2);
                this->_angle_coeffs[key] = {k, theta};
              }
          }

        if (dihedral_coeffs_idx)
          {
            typedef std::tuple<float, int, int> T;
            this->_dihedral_coeffs = (T *)malloc(
                sizeof(T) * (this->_dihedral_types + 1));
            auto first = lines.begin() + dihedral_coeffs_idx + 2;
            auto last = lines.begin() + dihedral_coeffs_idx + 2
                        + this->_dihedral_types;
            for (auto &it = first; it != last; ++it)
              {
                const unsigned int key(it->word_as_float(0));
                const float k = it->word_as_float(1);
                const int d(it->word_as_float(2));
                const int n(it->word_as_float(3));
                this->_dihedral_coeffs[key] = {k, d, n};
              }
          }

        if (improper_coeffs_idx)
          {
            typedef std::tuple<float, int, int> T;
            this->_improper_coeffs = (T *)malloc(
                sizeof(T) * (this->_improper_types + 1));
            auto first = lines.begin() + improper_coeffs_idx + 2;
            auto last = lines.begin() + improper_coeffs_idx + 2
                        + this->_improper_types;
            for (auto &it = first; it != last; ++it)
              {
                const unsigned int key(it->word_as_float(0));
                const float k = it->word_as_float(1);
                const int d(it->word_as_float(2));
                const int n(it->word_as_float(3));
                this->_improper_coeffs[key] = {k, d, n};
              }
          }

        {
            this->_atoms = (Atom *)malloc(sizeof(Atom) * (this->_atoms_count + 1));
            auto first = lines.begin() + atoms_idx + 2;
            auto last = lines.begin() + atoms_idx + 2 + this->_atoms_count;
            for (auto &it = first; it != last; ++it)
              {
                const int atom_id(it->word_as_float(0));
                const int molecule_tag(it->word_as_float(1));
                const int atom_type_id (it->word_as_float(2));
                const float q = (it->word_as_float(3));
                const float x = (it->word_as_float(4));
                const float y = (it->word_as_float(5));
                const float z = (it->word_as_float(6));
                const int nx(it->word_as_float(7));
                const int ny(it->word_as_float(8));
                const int nz(it->word_as_float(9));
                this->_atoms[atom_id] = Atom(atom_id, molecule_tag, atom_type_id,
                    q, x, y, z, nx, ny, nz);
            }
        }

        if (velocities_idx)
          {
            typedef std::tuple<float, float, float> T;
            this->_velocities = (T *)malloc(sizeof(T) * (this->_atoms_count + 1));
            auto first = lines.begin() + velocities_idx + 2;
            auto last = lines.begin() + velocities_idx + 2 + this->_atoms_count;
            for (auto &it = first; it != last; ++it)
              {
                const size_t atom_id(it->word_as_float(0));
                const float vx = (it->word_as_float(1));
                const float vy = (it->word_as_float(2));
                const float vz = (it->word_as_float(3));
                std::array<float, 3> v{{vx, vy, vz}};
              }
          }

        if (bonds_idx)
          {
            this->_bonds = (Bond *)malloc(sizeof(Bond) * (this->_bonds_count + 1));
            auto first = lines.begin() + bonds_idx + 2;
            auto last = lines.begin() + bonds_idx + 2 + this->_bonds_count;
            for (auto &it = first; it != last; ++it)
              {
            
                const int bond_id(it->word_as_float(0));
                const int bond_type_id(it->word_as_float(1));
                const int atom_one_id(it->word_as_float(2));
                const int atom_two_id(it->word_as_float(3));
                this->_bonds[bond_id] = Bond(bond_id, bond_type_id,
                    atom_one_id, atom_two_id);
              }
          }

        if (angles_idx)
          {
            this->_angles = (Angle *)malloc(sizeof(Angle)
                * (this->_angles_count + 1));
            auto first = lines.begin() + angles_idx + 2;
            auto last = lines.begin() + angles_idx + 2 + this->_angles_count;
            for (auto &it = first; it != last; ++it)
              {
                const int angle_id(it->word_as_float(0));
                const int angle_type_id(it->word_as_float(1));
                const int atom_one_id(it->word_as_float(2));
                const int atom_two_id(it->word_as_float(3));
                const int atom_three_id(it->word_as_float(4));
                this->_angles[angle_id] = Angle(angle_id, angle_type_id,
                    atom_one_id, atom_two_id, atom_three_id);
              }
          }

        if (dihedrals_idx)
          {
            this->_dihedrals = (Dihedral *)malloc(sizeof(Dihedral)
                * (this->_dihedrals_count + 1));
            auto first = lines.begin() + dihedrals_idx + 2;
            auto last = lines.begin() + dihedrals_idx + 2 + this->_dihedrals_count;
            for (auto &it = first; it != last; ++it)
              {
                const int dihedral_id(it->word_as_float(0));
                const int dihedral_type_id(it->word_as_float(1));
                const int atom_one_id(it->word_as_float(2));
                const int atom_two_id(it->word_as_float(3));
                const int atom_three_id(it->word_as_float(4));
                const int atom_four_id(it->word_as_float(5));
                this->_dihedrals[dihedral_id] = Dihedral(
                    dihedral_id, dihedral_type_id,
                    atom_one_id, atom_two_id, atom_three_id, atom_four_id);
              }
          }

        if (impropers_idx)
          {
            this->_impropers = (Improper *)malloc(sizeof(Improper)
                * (this->_impropers_count + 1));
            auto first = lines.begin() + impropers_idx + 2;
            auto last = lines.begin() + impropers_idx + 2 + this->_impropers_count;
            for (auto &it = first; it != last; ++it)
              {
                const int improper_id(it->word_as_float(0));
                const int improper_type_id(it->word_as_float(1));
                const int atom_one_id(it->word_as_float(2));
                const int atom_two_id(it->word_as_float(3));
                const int atom_three_id(it->word_as_float(4));
                const int atom_four_id(it->word_as_float(5));
                this->_impropers[improper_id] = Improper(
                    improper_id, improper_type_id,
                    atom_one_id, atom_two_id, atom_three_id, atom_four_id);
              }
          }
      }

private:
    std::string _fname;
    std::string _comment;
    Atom* _atoms;
    unsigned int _atoms_count;
    unsigned int _atom_types;
    std::tuple<float, float, float>* _velocities;
    Bond* _bonds;
    unsigned int _bonds_count;
    unsigned int _bond_types;
    Angle* _angles;
    unsigned int _angles_count;
    unsigned int _angle_types;
    Dihedral* _dihedrals;
    unsigned int _dihedrals_count;
    unsigned int _dihedral_types;
    Improper* _impropers;
    unsigned int _impropers_count;
    unsigned int _improper_types;
    float _xlo = 0, _xhi = 0, _ylo = 0, _yhi = 0, _zlo = 0, _zhi = 0;
    float _xy = 0, _xz = 0, _yz = 0;
    float *_masses;
    std::tuple<float, float>* _pair_coeffs;
    std::tuple<float, float>* _bond_coeffs;
    std::tuple<float, float>* _angle_coeffs;
    std::tuple<float, int, int>* _dihedral_coeffs;
    std::tuple<float, int, int>* _improper_coeffs;
};


#endif  //  DATAFILE_CONTENT_HPP include guard
