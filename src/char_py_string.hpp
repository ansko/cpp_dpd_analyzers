#ifndef CHAR_PY_STRING_HPP
#define CHAR_PY_STRING_HPP


// For the better performance, CharPyString stores lines
// as char[LINESIZE], i.e. LINESIZE is a maximal length of the line
#define LINESIZE 250


#include <cstring>


// Container for string that also has
// .startswith() and .endswith() from Python's str
class CharPyString
{
public:
    CharPyString(const char *cs)
    : _len(strlen(cs))
      {
        memcpy(this->_content, cs, strlen(cs) + 1);
      };

    const size_t len() const
      {
        return this->_len;
      }

    const bool startswith(const char *str) const
      {
        size_t len = strlen(str);
        if (len > this->_len)
            return false;
        for (size_t idx = 0; idx < len; idx++)
            if (str[idx] != this->_content[idx])
                return false;
        return true;
      }

    const bool endswith(const char *str) const
      {
        // When reading file in c-style in datafile_content.hpp,
        // this->_content[this->_len - 1] is a terminating character, so
        // this->_content[this->_len - 2] is a last valuable character.
        // When reading via std::getline(ifstream), -1 is correct.
        // delta should take care about this problem
        size_t delta = 1;
        if (this->_content[this->_len - 1] == '\0')
          {
            delta +=1;
          } 

        const size_t len = strlen(str);
        if (len > this->_len)
            return false;

        for (size_t idx = 0; idx < len; idx++)
          {
            if (str[len - 1 - idx] != this->_content[this->_len - 1 - idx])
              {
                return false;
              }
          }
        return true;
      }

    const float word_as_float(const size_t required_word_idx) const
      {
        char result[LINESIZE];
        size_t current_word_idx = 0;
        size_t letter_in_chosen_word_idx = 0;
        size_t chosen_word_length = 0;
        for (size_t letter_idx = 0; letter_idx < this->_len; ++letter_idx)
          {
            if (this->_content[letter_idx] == ' ')
              {
                current_word_idx++;
                continue;
              }
            if (current_word_idx == required_word_idx)
              {
                result[letter_in_chosen_word_idx] = this->_content[letter_idx];
                letter_in_chosen_word_idx++;
                chosen_word_length++;
              }
          }
        result[chosen_word_length] = '\0';  // custom_strtod works with c-strings
        //return custom_strtod(result);
        char *p; // ???
        return strtod(result, &p);
      }

private:
    size_t _len;
    char _content[LINESIZE];
};


#endif  // CHAR_PY_STRING_HPP
