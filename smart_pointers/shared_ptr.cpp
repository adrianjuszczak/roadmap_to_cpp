#include <memory>
#include <iostream>
#include <string>

struct Animals
{
    Animals() { std::cout << "CTOR() - Animals. \n"; }
    Animals(std::string name)
        : animalName{name}
    {
        {
            std::cout << "CTOR(name) - Animals. \n";
        }
    }
    ~Animals() { std::cout << "DTOR - Animals. \n"; }

private:
    std::string animalName;
};

class Base
{
public:
    virtual ~Base() = default;
};

int main()
{
    /* 1. Stwórz shared_pointera */
    std::shared_ptr<Animals> ptr_animals;
    /* 2. Przypisz coś do wskaźnika */
    ptr_animals = std::make_shared<Animals>("Dzik");
    /* mamy wskaźnik, stwórz kolejny wskaźnik */
    std::shared_ptr<Animals> ptr2_animals(ptr_animals);
    /* wyświetlk liczbę wskaźników */
    std::cout << ptr_animals.use_count() << std::endl;
}