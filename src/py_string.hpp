#ifndef PY_STRING_HPP
#define PY_STRING_HPP


#include <string>


class PyString
{
public:
    PyString(const char *cs)
      {
        this->_str = std::string(cs);
      };

    PyString(const std::string str)
      {
        this->_str = std::string(str);
      };

    const std::string str() const
      {
        return this->_str;
      }

    bool endswith(const std::string str) const
      {
        return (this->_str.rfind(str) != std::string::npos
                && this->_str.rfind(str) == this->_str.size() - str.size());
      }

    bool slow_startswith(const std::string str) const
      {
        return (this->_str.find(str) == 0);
      }

    bool startswith(const std::string str) const
      {
        auto t = this->_str.c_str();
        auto o = str.c_str();
        auto len = str.size();

        for (size_t idx = 0; idx < len; ++idx)
            if (t[idx] != o[idx])
                return false;

        return true;
      }

    float world_as_float(size_t word_idx)
      {
        std::istringstream iss(this->_str);
        float result;
        std::string trash_holder;
        for (size_t idx = 0; idx < word_idx; ++idx)
            iss >> trash_holder;
        iss >> result;
        return result;
      }

private:
    std::string _str;
};


#endif  // PY_STRING_HPP
