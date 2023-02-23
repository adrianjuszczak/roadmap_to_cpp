#include <iostream>

template <typename T>
class unique_ptr
{
public:
    unique_ptr() = default;
    unique_ptr(T *pointer)
        : m_pointer{pointer} {}

    T& operator*() {
        return *m_pointer;
    }

    T* operator->() {
        return m_pointer;
    }
private:
    T *m_pointer;
};

int main()
{
    int *ptrToInt = new int(100);
    unique_ptr<int> uni1(ptrToInt);
    std::cout << *uni1 << std::endl;
}