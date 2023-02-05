#include <iostream>
#include <utility>

class Swapper;
void swap(Swapper& lhs, Swapper& rhs);

    class Swapper {
    public:
        Swapper() = default;
        Swapper(int value)
            : m_value{ value } {}
        Swapper(Swapper&& other) noexcept;
        Swapper& operator=(Swapper&& other) noexcept;

        inline int& getValue() { return this->m_value; }
        void printValue() { std::cout << "Value: " << m_value << "\n"; }
    private:
        int m_value;
    };

    Swapper::Swapper(Swapper&& other) noexcept {
        this->m_value = other.m_value;
        other.m_value = 0;
    }

    Swapper& Swapper::operator=(Swapper&& other) noexcept {
        if (this != &other)
        {
            int temporaryBuffer = m_value;
            m_value = other.m_value;
            other.m_value = temporaryBuffer;
        }
        return *this;
    }

void swap(Swapper& lhs, Swapper& rhs){
    int temp = lhs.getValue();
    lhs.getValue() = rhs.getValue();
    rhs.getValue() = temp;
    std::cout << "swap written by anjk.\n";
}

int main() {
    Swapper swap1(99);
    Swapper swap2(990);

    using std::swap;    // ADL
    swap(swap1, swap2);
    swap1.printValue();
    swap2.printValue();
}