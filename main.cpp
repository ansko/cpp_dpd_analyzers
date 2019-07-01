#include <iostream>
#include <string>

#include "src/datafile_content.hpp"
#include "src/platelets_distance.hpp"


int main(int argc, char **argv)
{
    std::string dirname("/media/anton/Seagate Expansion Drive/dpd_calculations/"
        "poly_mod_likeness/mmt_r10_n2_mod_n400_tail5_poly_p10_n50156/datafiles/");

    //std::string data_fname("/home/anton/"
    //    "parallel_isolated_mmt_r10_n2_mod_n400_tail5_poly_p10_n50156.data");
        //"dpd_d.9000.data");

    // sec        cpp_old    py3    cpp_new
    // for  1:    10         8      2
    // for  5:    50         41     9

    size_t mmt_atom_type(1);
    size_t platelets_count(2);

    for (size_t idx = 0; idx < 10; idx++)
      {
        std::string fname = dirname + "dpd_d." + std::to_string(idx*1000) + ".data";
        DatafileContent dfc(fname);
        float aa = platelets_distance(dfc, mmt_atom_type, platelets_count);
        std::cout << idx << " " << aa << std::endl;
      }

    return 0;
}
