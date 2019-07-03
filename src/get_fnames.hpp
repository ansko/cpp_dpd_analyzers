#ifndef GET_FNAMES_HPP
#define GET_FNAMES_HPP


#include <string>
#include <vector>


std::vector<std::vector<std::string>> get_fnames(std::string regime)
{
    std::string dpd_dir("/media/anton/Seagate Expansion Drive/dpd_calculations/");
    std::vector<std::vector<std::string>> fnames;

    // Some a_ij are small.
    // Both modifier head and taill attract polymer.
    if (regime == "poly_mod_likeness")
      {
        std::string dir("NOT_SO_GOOD/0_poly_mod_likeness/");
        std::vector<std::string> subdirs = {
            "mmt_r10_n2_mod_n100_tail5_poly_p10_n50336/",
            "mmt_r10_n2_mod_n200_tail5_poly_p10_n50276/",
            "mmt_r10_n2_mod_n300_tail5_poly_p10_n50216/",
            "mmt_r10_n2_mod_n400_tail5_poly_p10_n50156/"
        };

        for (size_t in_seria_idx = 0; in_seria_idx < 4; ++in_seria_idx)
          {
            fnames.push_back(std::vector<std::string>());
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

    // Some a_ij are ok and taken in accordance with Trieste.
    else if (regime == "article_params")
      {
        std::string dir("SOME_OTHER_THINGS/ARTICLE_PARAMS/");
        std::vector<std::string> subdirs = {
            "13_mmt_r10_n2_mod_n100_tail5_poly_p10_n50336/",
            "14_mmt_r10_n2_mod_n200_tail5_poly_p10_n50276/",
            "15_mmt_r10_n2_mod_n300_tail5_poly_p10_n50216/",
            "16_mmt_r10_n2_mod_n400_tail5_poly_p10_n50156/"
        };

        for (size_t in_seria_idx = 0; in_seria_idx < 4; ++in_seria_idx)
          {
            fnames.push_back(std::vector<std::string>());
            for (size_t fname_idx = 0; fname_idx < 82; ++fname_idx)
              {
                std::string fname(dpd_dir + dir + subdirs[in_seria_idx]);
                fname += "datafiles/dpd_d.";
                fname += std::to_string(fname_idx * 1000);
                fname += ".data";
                fnames[in_seria_idx].push_back(fname);
              }
          }
      }

    // NPT + weak repulsion (==attraction) between polymer and modifier's tail
    else if (regime == "npt_attraction")
      {
        std::string dir("SOME_OTHER_THINGS/npt_attraction/");
        std::vector<std::string> subdirs = {
            "9_mmt_r10_n2_mod_n100_tail5_poly_p10_n50336/",
            "10_mmt_r10_n2_mod_n200_tail5_poly_p10_n50276/",
            "11_mmt_r10_n2_mod_n300_tail5_poly_p10_n50216/",
            "12_mmt_r10_n2_mod_n400_tail5_poly_p10_n50156/"
        };

        for (size_t in_seria_idx = 0; in_seria_idx < 4; ++in_seria_idx)
          {
            fnames.push_back(std::vector<std::string>());
            for (size_t fname_idx = 0; fname_idx < 82; ++fname_idx)
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


#endif  // GET_FNAMES_HPP
