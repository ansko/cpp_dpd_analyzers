#include <iostream>
#include <string>

#include "src/char_py_string.hpp"
#include "src/datafile_content.hpp"
#include "src/platelets_distance.hpp"
#include "src/get_fnames.hpp"


#define MMT_ATOM_TYPE 1
#define PLATELETS_COUNT 2


// Process folders for a seria of calculations
void perform_seria(std::string regime)
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
            close(fp);

            DatafileContent dfc(fnames[in_seria_idx][file_idx]);
            auto &d = platelets_distance(dfc, MMT_ATOM_TYPE, PLATELETS_COUNT);
            std::cout << in_seria_idx << " " << file_idx << " "
                << d.first << " " << d.second << std::endl;
            ofs << file_idx << " " << d.first << " " << d.second << std::endl;
          }
        ofs.close();
      }

    return;
}


int main(int argc, char **argv)
{
    //std::string regime("poly_mod_likeness");
    //std::string regime("article_params");
    //std::string regime("npt_attraction");

    std::string regime(argv[1]);

    std::cout << "---" << regime << "---\n";

    perform_seria(regime);
    
    return 0;
}
