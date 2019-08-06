// Should be removed (correct but deprecated)


#ifndef PERFORM_SERIA_HPP
#define PERFORM_SERIA_HPP


#include <string>
#include <vector>

#include "platelets_distance.hpp"


// Process folders for a seria of calculations
void perform_seria(std::string regime, size_t mmt_atom_type, size_t platelets_count)
{
    std::vector<std::vector<std::string>> fnames(get_fnames(regime));

    for (size_t in_seria_idx = 0; in_seria_idx < fnames.size(); ++in_seria_idx)
      {
        std::cout << "~~~ " << in_seria_idx << " ~~~\n";
        if (fnames[in_seria_idx].size() == 0)
          {
            std::cout << "Empty file list!";
            return;
          }

        std::ofstream ofs("outs/" + regime + "_" + std::to_string(in_seria_idx));
        for (size_t file_idx = 0; file_idx < fnames[in_seria_idx].size();
            ++file_idx)
          {
            FILE *fp = fopen(fnames[in_seria_idx][file_idx].c_str(), "r");
            if (fp == NULL)
              {
                continue;
              }
            DatafileContent dfc(fnames[in_seria_idx][file_idx]);
            auto &d = platelets_distance(dfc, mmt_atom_type, platelets_count);
            std::cout << in_seria_idx << " " << file_idx << " "
                << d.first << " " << d.second << std::endl;
            ofs << file_idx << " " << d.first << " " << d.second << std::endl;
          }
        ofs.close();
      }

    return;
}


#endif  // PERFORM_SERIA_HPP include guard
