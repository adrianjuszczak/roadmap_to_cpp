#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <concepts>


/**
 *  since C++20
 *  requires g++ > 10
*/
template <typename T>
    requires std::is_copy_constructible<T>::value
T get_copy(T value)
{
    return value;
}

struct Base {
    Base() = default;
    Base(const Base &other) = delete;
    Base &operator=(const Base &other) = delete;
};

int main()
{
    Base base1;
    auto copy = get_copy(base1);
}