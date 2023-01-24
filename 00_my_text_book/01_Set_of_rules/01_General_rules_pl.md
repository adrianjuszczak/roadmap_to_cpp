## Rozdział poświęcony ogólnym zasadadom programowania 


### General

1. ADL - Argument Dependent Lookup (Koenig lookup) - Wyszukiwanie zależne od argumentu.  
   Wersja wywołanej funckji zależy od przestrzeni nazw argumentów do niej przekazanych. 

   Przykład:
```
    namespace anjk {

        class Sample;
        void foo(Sample);
    }

    anjk::Sample sampel;

    int main {
        foo(sampel);        // zadziała poprawnie 
    }
```

Powyższy kod wykona się prawidłowo, ponieważ algorytm nie będzie szukał tylko w zakresie lokalnym,   
ale również w zakresie w którym zostały zadeklarowane typy parametrów funkcji.
###