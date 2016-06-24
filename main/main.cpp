#include "../lib/good_object.h"
#include "../lib2/very_good_object.h"

int main() {
  auto const obj1 = make_good();
  obj1->release();

  auto const obj2 = make_very_good();
  obj2->talk();
  obj2->release();

  return 0;
}
