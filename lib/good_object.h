#pragma once

#ifdef _WIN32
#ifdef GOOD_OBJECT_EXPORT
#define GOOD_API __declspec(dllexport)
#else
#define GOOD_API __declspec(dllimport)
#endif
#else
#define GOOD_API
#endif

struct GOOD_API good_object {
  virtual void add_ref() = 0;
  virtual void release() = 0;
};

#define DECL_GOOD_OBJECT               \
public:                                \
  void add_ref() override {            \
    std::cout << __FUNCTION__ << '\n'; \
    internal_add_ref();                \
  }                                    \
                                       \
  void release() override {            \
    std::cout << __FUNCTION__ << '\n'; \
    internal_release();                \
  }                                    \
                                       \
private:                               \
  void internal_add_ref() {            \
    std::cout << __FUNCTION__ << '\n'; \
    ++ref_count_;                      \
  }                                    \
                                       \
  void internal_release() {            \
    std::cout << __FUNCTION__ << '\n'; \
    if (--ref_count_ == 0) {           \
      delete this;                     \
    }                                  \
  }                                    \
                                       \
private:                               \
  int ref_count_ = 1

GOOD_API good_object* make_good();
