#include <iostream>
#include <cstdio>


/*
    rzutowanie const (odrzucenie const)
    const_cast

    pozwala odrzucic rzutowanie implicit 
    static_cast

    rzutowanie roznego rodzaju pamieci
    reinterpretet_cast

    const_cast - odrzuca modyfikator const , pozwala na modyfikowanie 

*/

int& modyfikujStala(const int& stala) {
    return const_cast<int&>(stala);
}

/*  
    napisz funkcję, która przyjmuję jako argument zmienną typu v(wskaznik na void)
    zmień typ na wskażnik na short, inkrementuj zmienną i wyświetlj jej zawartość
*/

short zmienTyp(void* zmienna) {
    short* voidPoRzutowaniu =  static_cast<short*>(zmienna);
    *(voidPoRzutowaniu) = *(voidPoRzutowaniu) + 1;

    return *(voidPoRzutowaniu);
}


int main() {

    const int stala = 100;
    int& stalaBezConst = modyfikujStala(stala);
    stalaBezConst++;
    std::cout << "ref to stala: " << stalaBezConst << std::endl;

    short* wskaźnika na short 
    void* zmiennaTypuVoid = ::operator new(2);
    
    
}