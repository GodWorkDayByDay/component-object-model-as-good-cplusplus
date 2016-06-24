#define VERY_GOOD_OBJECT_EXPORT
#include "very_good_object.h"

#include <iostream>

struct my_very_good_object : public very_good_object {
  my_very_good_object() {
    std::cout << __FUNCTION__ << '\n';
  }

  ~my_very_good_object() {
    std::cout << __FUNCTION__ << '\n';
  }

  void talk() override {
    std::clog << __FUNCTION__ << '\n';
  }

  DECL_GOOD_OBJECT;
};

VERY_GOOD_API very_good_object* make_very_good() {
  return new my_very_good_object();
}
