#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "src/char_py_string.hpp"
#include "src/datafile_content.hpp"
#include "src/get_fnames.hpp"
#include "src/perform_seria.hpp"
#include "src/platelets_distance.hpp"


#define MMT_ATOM_TYPE 1
#define PLATELETS_COUNT 2


extern std::vector<std::string> AVAILABLE_REGIMES;


int main(int argc, char **argv)
{
    if (argc < 2)
      {
        std::cout << "Regime is not set in (empty argv[1])\n";
        return 0;
      }

    std::string regime(argv[1]);
    std::cout << "---" << regime << "---\n";
    if (std::find(AVAILABLE_REGIMES.begin(), AVAILABLE_REGIMES.end(), regime)
        == AVAILABLE_REGIMES.end())
      {
        std::cout << "Unknown regime: " << regime << "\ntry one of:\n";
        for (auto &r : AVAILABLE_REGIMES)
          {
            std::cout << r << std::endl;
          }
        return 0;
      }

    perform_seria(regime, MMT_ATOM_TYPE, PLATELETS_COUNT);
 
    return 0;
}
