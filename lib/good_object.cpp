#define GOOD_OBJECT_EXPORT
#include "good_object.h"

#include <iostream>

struct my_good_object : public good_object {
  my_good_object() {
    std::cout << __FUNCTION__ << '\n';
  }

  ~my_good_object() {
    std::cout << __FUNCTION__ << '\n';
  }

  DECL_GOOD_OBJECT;
};

GOOD_API good_object* make_good() {
  return new my_good_object();
}
