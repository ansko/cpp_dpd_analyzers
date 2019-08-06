#ifndef GET_RDF_HPP
#define GET_RDF_HPP


#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

#include "datafile_content.hpp"
#include "structures.hpp"


std::map<float, float>
get_rdf(DatafileContent &dfc, std::vector<unsigned int> atom_types);


#endif  // GET_RDF_HPP include guard
