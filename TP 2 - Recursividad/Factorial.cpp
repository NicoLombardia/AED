// ============================================================
// Fact - Factorial (recursivo)
// ============================================================
//
// Léxico (definición matemática):
//
//   Fact : N -> N
//
//   Fact(n) = 1               , si n < 2
//   Fact(n) = n * Fact(n - 1) , si n >= 2
//
// Nota: un número factorial puede ser muy grande, por eso se
// elige el tipo `unsigned long long` para poder representar
// valores como Fact(20) sin desbordar. Se usa `long long` y no
// simplemente `long` porque en Windows (MinGW/GCC) `unsigned long`
// es de 32 bits incluso en sistemas de 64 bits, mientras que
// `unsigned long long` garantiza 64 bits en cualquier plataforma.
// ============================================================

#include <cassert>

// Prototipo
unsigned long long Fact(unsigned n);

int main() {
    // Pruebas
    assert(              1 == Fact( 0) );
    assert(              1 == Fact( 1) );
    assert(              2 == Fact( 2) );
    assert(              6 == Fact( 3) );
    assert(             24 == Fact( 4) );
    assert(            120 == Fact( 5) );
    assert(            720 == Fact( 6) );
    assert(           5040 == Fact( 7) );
    assert(          40320 == Fact( 8) );
    assert(         362880 == Fact( 9) );
    assert(        3628800 == Fact(10) );
    assert(       39916800 == Fact(11) );
    assert(      479001600 == Fact(12) );
    assert(     6227020800 == Fact(13) );
    assert(    87178291200 == Fact(14) );
    assert(  1307674368000 == Fact(15) );
    assert(2432902008176640000 == Fact(20) );
}

// Definición
unsigned long long Fact(unsigned n) { return
    n < 2 ? 1 :
    n * Fact(n - 1);
}
