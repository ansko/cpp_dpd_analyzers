#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP


class Atom
{
public:
    Atom(unsigned int id, unsigned int molecule_tag, unsigned int type,
        float q, float x, float y, float z, int nx, int ny, int nz)
    : _id(id), _molecule_tag(molecule_tag), _type(type), _q(q),
      _x(x), _y(y), _z(z), _nx(nx), _ny(ny), _nz(nz)
    {};

    void reset_id(const unsigned int new_id)
      {
        this->_id = new_id;
      }

    void reset_molecule_tag(const unsigned int new_molecule_tag)
      {
        this->_molecule_tag = new_molecule_tag;
      }

    void reset_type(const unsigned int new_type)
      {
        this->_type = new_type;
      }

    void reset_q(const float new_q)
      {
        this->_q = new_q;
      }

    void reset_x(const float new_x)
      {
        this->_x = new_x;
      }

    void reset_y(const float new_y)
      {
        this->_y = new_y;
      }

    void reset_z(const float new_z)
      {
        this->_z = new_z;
      }

    void reset_nx(const unsigned int new_nx)
      {
        this->_nx = new_nx;
      }

    void reset_ny(const unsigned int new_ny)
      {
        this->_ny = new_ny;
      }

    void reset_nz(const unsigned int new_nz)
      {
        this->_nz = new_nz;
      }

    const unsigned int id() const
      {
        return this->_id;
      }

    const unsigned int molecule_tag() const
      {
        return this->_molecule_tag;
      }

    const unsigned int type() const
      {
        return this->_type;
      }

    const float q() const
      {
        return this->_q;
      }

    const float x() const
      {
        return this->_x;
      }
    const float y() const
      {
        return this->_y;
      }
    const float z() const
      {
        return this->_z;
      }

    const int nx() const
      {
        return this->_nx;
      }

    const int ny() const
      {
        return this->_ny;
      }

    const int nz() const
      {
        return this->_nz;
      }

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

    void reset_id(const unsigned int new_id)
    {
      this->_id = new_id;
    }

    void reset_type(const unsigned int new_type)
    {
      this->_type = new_type;
    }

    void reset_atom_one_id(const unsigned int new_atom_one_id)
    {
      this->_atom_one_id = new_atom_one_id;
    }

    void reset_atom_two_id(const unsigned int new_atom_two_id)
    {
      this->_atom_two_id = new_atom_two_id;
    }

    const unsigned int id() const
      {
        return this->_id;
      }

    const unsigned int type() const
      {
        return this->_type;
      }

    const unsigned int atom_one_id() const
      {
        return this->_atom_one_id;
      }

    const unsigned int atom_two_id() const
      {
        return this->_atom_two_id;
      }

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

    void reset_id(const unsigned int new_id)
      {
        this->_id = new_id;
      }

    void reset_type(const unsigned int new_type)
      {
        this->_type = new_type;
      }

    void reset_atom_one_id(const unsigned int new_atom_one_id)
      {
        this->_atom_one_id = new_atom_one_id;
      }

    void reset_atom_two_id(const unsigned int new_atom_two_id)
      {
        this->_atom_two_id = new_atom_two_id;
      }

    void reset_atom_three_id(const unsigned int new_atom_three_id)
      {
        this->_atom_three_id = new_atom_three_id;
      }

    const unsigned int id() const
      {
        return this->_id;
      }

    const unsigned int type() const
      {
        return this->_type;
      }

    const unsigned int atom_one_id() const
      {
        return this->_atom_one_id;
      }

    const unsigned int atom_two_id() const
      {
        return this->_atom_two_id;
      }

    const unsigned int atom_tree_id() const
      {
        return this->_atom_three_id;
      }

private:
    unsigned int _id;
    unsigned int _type;
    unsigned int _atom_one_id, _atom_two_id, _atom_three_id;
};


class DihedralImproperBase
{
public:
    DihedralImproperBase(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id, unsigned int atom_four_id)
    : _id(id), _type(type), _atom_one_id(atom_one_id), _atom_two_id(atom_two_id),
      _atom_three_id(atom_three_id), _atom_four_id(atom_four_id)
    {}

    void reset_id(const unsigned int new_id)
      {
        this->_id = new_id;
      }

    void reset_type(const unsigned int new_type)
      {
        this->_type = new_type;
      }

    void reset_atom_one_id(const unsigned int new_atom_one_id)
      {
        this->_atom_one_id = new_atom_one_id;
      }

    void reset_atom_two_id(const unsigned int new_atom_two_id)
      {
        this->_atom_two_id = new_atom_two_id;
      }

    void reset_atom_three_id(const unsigned int new_atom_three_id)
      {
        this->_atom_three_id = new_atom_three_id;
      }

    void reset_atom_four_id(const unsigned int new_atom_four_id)
      {
        this->_atom_four_id = new_atom_four_id;
      }

    const unsigned int id() const
      {
        return this->_id;
      }

    const unsigned int type() const
      {
        return this->_type;
      }

    const unsigned int atom_one_id() const
      {
        return this->_atom_one_id;
      }

    const unsigned int atom_two_id() const
      {
        return this->_atom_two_id;
      }

    const unsigned int atom_tree_id() const
      {
        return this->_atom_three_id;
      }

    const unsigned int atom_four_id() const
      {
        return this->_atom_three_id;
      }

protected:
    unsigned int _id;
    unsigned int _type;
    unsigned int _atom_one_id, _atom_two_id, _atom_three_id, _atom_four_id;
};


class Dihedral : public DihedralImproperBase
{
public:
    Dihedral(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id, unsigned int atom_four_id)
    : DihedralImproperBase(id, type, atom_one_id, atom_two_id, atom_three_id,
        atom_four_id)
    {};
};


class Improper : public DihedralImproperBase
{
public:
    Improper(unsigned int id, unsigned int type,
        unsigned int atom_one_id, unsigned int atom_two_id,
        unsigned int atom_three_id, unsigned int atom_four_id)
    : DihedralImproperBase(id, type, atom_one_id, atom_two_id, atom_three_id,
        atom_four_id)
    {};
};


#endif  //  STRUCTURES_HPP
