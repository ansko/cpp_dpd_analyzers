#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/char_py_string.hpp"
#include "src/datafile_content.hpp"
#include "src/get_fnames.hpp"
#include "src/perform_seria.hpp"
#include "src/platelets_distance.hpp"

#include "src/get_rdf.hpp"


int main(int argc, char **argv)
{
    DatafileContent dfc("L_d.12500000.data");
    //std::vector<unsigned int> atom_types({9, 10, 11, 12, 13, 14, 15, 16, 17});
    std::vector<unsigned int> atom_types({9});

    std::map<float, float> rdf_result = get_rdf(dfc, atom_types);

    for (auto &it : rdf_result)
        std::cout << it.first << " " << it.second << std::endl;

    return 0;
}
