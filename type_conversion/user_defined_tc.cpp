#include <iostream>


class UserDefinedTypeConverter {
public:
    UserDefinedTypeConverter()
        : m_value{ 10 } {}
    operator double() const {
        return 10.0;
    }

private:
    int m_value;
};

int
main() {

    UserDefinedTypeConverter tc1;
    auto floating = tc1 * 1.23;

    std::cout << "User defined type-conversion: " << floating << "\n";
}