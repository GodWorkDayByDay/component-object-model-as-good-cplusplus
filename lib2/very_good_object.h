#pragma once

#include "../lib/good_object.h"

#ifdef _WIN32
#ifdef VERY_GOOD_OBJECT_EXPORT
#define VERY_GOOD_API __declspec(dllexport)
#else
#define VERY_GOOD_API __declspec(dllimport)
#endif
#else
#define GOOD_API
#endif

struct VERY_GOOD_API very_good_object: public good_object {
  virtual void talk() = 0;
};

VERY_GOOD_API very_good_object* make_very_good();
