#ifndef PLATELETS_DISTANCE_HPP
#define PLATELETS_DISTANCE_HPP


#include <cmath>
#include <iostream>
#include <map>
#include <vector>

#include "datafile_content.hpp"
#include "structures.hpp"


const std::pair<float, float>
platelets_distance(DatafileContent &dfc, size_t mmt_atom_type,
    size_t platelets_count);


#endif  // PLATELETS_DISTANCE_HPP include guard
