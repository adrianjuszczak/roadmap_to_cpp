#include <iostream>

// const_cast - remove constness
template <typename T>
    requires std::is_integral<T>::value
void incrementConstValue(T const &variable)
{
    std::cout << "constInteger before cast: " << variable << "\n";
    T &nonConstVariable = const_cast<T &>(variable);
    nonConstVariable++;
    std::cout << "constInteger after cast and incrementing: " << nonConstVariable << "\n";
}

// reinterpretet_cast - raw memory
short castToShortAndIncrement(void *pointer)
{
    short *castedVoid = reinterpret_cast<short *>(pointer);
    *castedVoid = *castedVoid + 1;

    return *castedVoid;
}

// static_cast - for casting well-defined typec
template <typename DesiredType, typename T>
T &performStaticCast(T &value)
{
    return static_cast<DesiredType &>(value);
}

// dynamic_cast
struct Base {
    virtual void foo() {}
};

struct Derived : public Base {
    void foo() override {}
};

int main()
{
    // reinterpretet_cast
    short shortTypeValue{2};
    void *ptrToVoid = &shortTypeValue;
    std::cout << castToShortAndIncrement(ptrToVoid) << "\n";

    // const_cast
    const int constInteger{99};
    incrementConstValue(constInteger);

  
    Base base1;
    Derived derived1;

    Derived* ptrDer = dynamic_cast<Derived*>(&base1);

}