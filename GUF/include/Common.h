
#ifndef GUF_COMMON_H
#define GUF_COMMON_H

#pragma clang diagnostic ignored "-Wincompatible-ms-struct"

#include <functional>

#define interface class
#define abstract

typedef std::function<void()> ClickCallback;
template <typename R, typename ... Types>
constexpr size_t getArgumentCount( R(*f)(Types ...)) {
    return sizeof...(Types);
}


#endif //GUF_COMMON_H
