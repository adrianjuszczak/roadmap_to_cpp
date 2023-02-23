#include <iostream>
#include <vector>

#include "type_name.hpp"

template<typename ComparedType, typename T>
void countObjects(const std::vector<T>& objects) {
    size_t counter {0};

    for (auto& iter : objects) {
        if (dynamic_cast<ComparedType*>(iter)){
            counter++;
        }
    }
    
    std::cout << "There are " << counter << " objects of type - \"" << type_name<ComparedType>() << "\" \n";
}