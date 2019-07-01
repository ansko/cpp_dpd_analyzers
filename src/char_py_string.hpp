#ifndef CHAR_PY_STRING_HPP
#define CHAR_PY_STRING_HPP


//#include <iostream>
#include <cstring>
//#include <string>


//double custom_strtod(const std::string& input)
double custom_strtod(const char *p)
{
    // https://stackoverflow.com/a/5832396/7927226
    if (!*p || *p == '?')
        return -1;
    int s = 1;
    while (*p == ' ') p++;

    if (*p == '-') {
        s = -1; p++;
    }

    double acc = 0;
    while (*p >= '0' && *p <= '9')
        acc = acc * 10 + *p++ - '0';

    if (*p == '.') {
        double k = 0.1;
        p++;
        while (*p >= '0' && *p <= '9') {
            acc += (*p++ - '0') * k;
            k *= 0.1;
        }
    }
    return s * acc;
}


// Wrapper above char *
class CharPyString
{
public:
    CharPyString(const char *cs)
    : _len(strlen(cs))
      {
        this->_content = (char *)malloc(sizeof(char) * (strlen(cs) + 1));
        memcpy(this->_content, cs, strlen(cs)+1);
      };

    CharPyString(const std::string str)
      {
        memcpy(this->_content, str.c_str(), str.size()+1);
      };

    char *content() const
      {
        return this->_content;
      }

    size_t len() const
      {
        return this->_len;
      }

    bool startswith(const char * str) const
      {
        size_t len = strlen(str);
        if (len > this->_len)
            return false;
        for (size_t idx = 0; idx < len; idx++)
            if (str[idx] != this->_content[idx])
                return false;
        return true;
      }

    bool endswith(const char * str) const
      {
        size_t len = strlen(str);
        if (len > this->_len)
            return false;

        for (size_t idx = 0; idx < len; idx++)
            if (str[len - 1 - idx] != this->_content[this->_len - 1 - idx])
                return false;
        return true;
      }

    float word_as_float(size_t word_idx)
      {
        char *result = (char *)malloc(sizeof(char) * 25);  // why 25
        size_t current_word = 0;
        size_t letter_idx = 0;

        for (size_t idx = 0; idx < this->_len; ++idx)
          {
            if (this->_content[idx] == ' ')
                current_word++;
            if (current_word == word_idx)
              {
                result[letter_idx] = this->_content[idx];
                letter_idx++;
              }
          }

        return custom_strtod(result);
      }

private:
    size_t _len;
    char *_content;
};


#endif  // CHAR_PY_STRING_HPP
