#include <iostream>
#include <string>

#include "src/char_py_string.hpp"

#include "src/datafile_content.hpp"
#include "src/platelets_distance.hpp"


#define MMT_ATOM_TYPE 1
#define PLATELETS_COUNT 2


std::array<std::vector<std::string>,4> get_fnames(std::string regime)
{
    std::string dpd_dir("/media/anton/Seagate Expansion Drive/dpd_calculations/");
    std::array<std::vector<std::string>,4> fnames;

    if (regime == "poly_mod_likeness")
      {
        std::string dir("poly_mod_likeness/");
        std::vector<std::string> subdirs = {
            "mmt_r10_n2_mod_n100_tail5_poly_p10_n50336/",
            "mmt_r10_n2_mod_n200_tail5_poly_p10_n50276/",
            "mmt_r10_n2_mod_n300_tail5_poly_p10_n50216/",
            "mmt_r10_n2_mod_n400_tail5_poly_p10_n50156/"
        };

        for (size_t in_seria_idx = 0; in_seria_idx < 4; ++in_seria_idx)
          {
            for (size_t fname_idx = 0; fname_idx < 162; ++fname_idx)
              {
                std::string fname(dpd_dir + dir + subdirs[in_seria_idx]);
                fname += "datafiles/dpd_d.";
                fname += std::to_string(fname_idx * 1000);
                fname += ".data";
                fnames[in_seria_idx].push_back(fname);
              }
          }
      }

    return fnames;
}


// Process folders for a seria of calculations
void perform_seria(std::string regime)
{
    std::array<std::vector<std::string>,4> fnames(get_fnames(regime));

    for (size_t in_seria_idx = 0; in_seria_idx < 4; ++in_seria_idx)
      {
        std::ofstream ofs("outs/" + regime + "_" + std::to_string(in_seria_idx));
        for (size_t file_idx = 0; file_idx < fnames[in_seria_idx].size();
            ++file_idx)
          {
            DatafileContent dfc(fnames[in_seria_idx][file_idx]);
            float d = platelets_distance(dfc, MMT_ATOM_TYPE, PLATELETS_COUNT);
            std::cout << in_seria_idx << " " << file_idx << " " << d << std::endl;
            ofs << file_idx << " " << d << std::endl;
          }
        ofs.close();
      }

    return;
}

int main(int argc, char **argv)
{
    std::string regime("poly_mod_likeness");
    perform_seria(regime);
    
    return 0;
}
