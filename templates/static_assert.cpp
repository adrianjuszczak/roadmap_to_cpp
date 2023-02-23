#include <iostream>
#include <type_traits>
#include <utility>

template <typename T>
T get_copy(T value)
{
    static_assert(std::is_copy_constructible<T>() && std::is_copy_assignable<T>(),
                  "Type must be copy constructible.");
    return value;
}

template <typename T>
T move_object(T &&other)
{
    static_assert(std::is_move_assignable<T>() && std::is_move_constructible<T>(),
                  "Type is not move operable. ");
    return std::move(other);
}

template <typename T>
class POC
{
public:
    POC() = default;
    POC(const POC &other) = delete;
    POC &operator=(const POC &other) = delete;

private:
    T value;
};

int main()
{
    POC<int> poc1;
}