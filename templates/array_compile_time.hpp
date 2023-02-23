#include <iostream>

/**
 *  using non-type template parameter, allows you to inject value at compile time.
 *
 *  template <typename T> - template type parameter
 *  template <size_t V>   - non-type template parameter
 */

template<size_t Index, typename T, size_t Length>
T& get(T (&array)[Length]) {
    static_assert(Index < Length, "Out of array boundaries.");
    return array[Index];
}
