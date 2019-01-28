#pragma once
#ifndef STRINGOPS_H
#define STRINGOPS_H

#include <base.hpp>
#include <cstdarg>

namespace ionizing {
  void    ltrim     (string&  str);
  void    rtrim     (string&  str);
  void    trim      (string&  str);
  string  ltrim_copy(string   str);
  string  rtrim_copy(string   str);
  string  trim_copy (string   str);

  VecStr  split     (string   str);
  string  join      (VecStr   str_vec);

  void    toupper       (string&  str);
  void    tolower       (string&  str);
  string  toupper_copy  (string   str);
  string  tolower_copy  (string   str);

  bool    start_with    (const string&  src, const string&  val);
  bool    end_with      (const string&  src, const string&  val);

  bool    is_empty_or_white_space (const string& str);

  string  string_printf (const char* format, ...);
}



#endif //STRINGOPS_H
