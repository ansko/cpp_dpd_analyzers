#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP


// Some immutable containers to store atomic structures data


class Atom
{
public:
    Atom(unsigned int id, unsigned int molecule_tag, unsigned int type,
        float q, float x, float y, float z, int nx, int ny, int nz)
    : _id(id), _molecule_tag(molecule_tag), _type(type), _q(q),
      _x(x), _y(y), _z(z), _nx(nx), _ny(ny), _nz(nz)
    {};

    const unsigned int id() const { return this->_id; }
    const unsigned int molecule_tag() const { return this->_molecule_tag; }
    const unsigned int type() const { return this->_type; }
    const float q() const { return this->_q; }
    const float x() const { return this->_x; }
    const float y() const { return this->_y; }
    const float z() const { return this->_z; }
    const int nx() const { return this->_nx; }
    const int ny() const { return this->_ny; }
    const int nz() const { return this->_nz; }

private:
    unsigned int _id;
    unsigned int _molecule_tag;
    unsigned int _type;
    float _q;
    float _x, _y, _z;
    int _nx, _ny, _nz;
};


class Bond
{
public:
    Bond(unsigned int id, unsigned int type, unsigned int atom_one_id,
        unsigned int atom_two_id)
    : _id(id), _type(type), _atom_one_id(atom_one_id), _atom_two_id(atom_two_id)
    {}

    const unsigned int id() const { return this->_id; }
    const unsigned int type() const { return this->_type; }
    const unsigned int atom_one_id() const { return this->_atom_one_id; }
    const unsigned int atom_two_id() const { return this->_atom_two_id; }

private:
    unsigned int _id;
    unsigned int _type;
    unsigned int _atom_one_id, _atom_two_id;
};


class Angle
{
public:
    Angle(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id)
    : _id(id), _type(type), _atom_one_id(atom_one_id), _atom_two_id(atom_two_id),
      _atom_three_id(atom_three_id)
    {}

    const unsigned int id() const { return this->_id; }
    const unsigned int type() const { return this->_type; }
    const unsigned int atom_one_id() const { return this->_atom_one_id; }
    const unsigned int atom_two_id() const { return this->_atom_two_id; }
    const unsigned int atom_tree_id() const { return this->_atom_three_id; }

private:
    unsigned int _id;
    unsigned int _type;
    unsigned int _atom_one_id, _atom_two_id, _atom_three_id;
};


// Since dihedrals and impropers are quite similar
class DihedralImproperBase
{
public:
    const unsigned int id() const { return this->_id; }
    const unsigned int type() const { return this->_type; }
    const unsigned int atom_one_id() const { return this->_atom_one_id; }
    const unsigned int atom_two_id() const { return this->_atom_two_id; }
    const unsigned int atom_tree_id() const { return this->_atom_three_id; }
    const unsigned int atom_four_id() const { return this->_atom_three_id; }

protected:
    DihedralImproperBase(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id, unsigned int atom_four_id)
    : _id(id), _type(type), _atom_one_id(atom_one_id), _atom_two_id(atom_two_id),
      _atom_three_id(atom_three_id), _atom_four_id(atom_four_id)
    {}

    unsigned int _id;
    unsigned int _type;
    unsigned int _atom_one_id, _atom_two_id, _atom_three_id, _atom_four_id;
};


class Dihedral : private DihedralImproperBase
{
public:
    Dihedral(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id, unsigned int atom_four_id)
    : DihedralImproperBase(id, type, atom_one_id, atom_two_id, atom_three_id,
        atom_four_id)
    {};
};


class Improper : private DihedralImproperBase
{
public:
    Improper(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id, unsigned int atom_four_id)
    : DihedralImproperBase(id, type, atom_one_id, atom_two_id, atom_three_id,
        atom_four_id)
    {};
};


#endif  //  STRUCTURES_HPP include guard
