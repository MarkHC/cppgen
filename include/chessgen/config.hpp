#pragma once

#include <type_traits>

#if !defined(MAKE_ENUM_OPERATOR)
#define MAKE_ENUM_OPERATOR(T, U, OP)                                           \
  inline T operator OP(T a, T b)                                               \
  {                                                                            \
    return static_cast<T>(static_cast<U>(a) OP static_cast<U>(b));             \
  }

#endif

#if !defined(CHESSGEN_ENUMOPS)
#define CHESSGEN_ENUMOPS(E)                                                    \
  MAKE_ENUM_OPERATOR(E, std::underlying_type_t<E>, |)                          \
  MAKE_ENUM_OPERATOR(E, std::underlying_type_t<E>, ^)                          \
  MAKE_ENUM_OPERATOR(E, std::underlying_type_t<E>, &)
#endif