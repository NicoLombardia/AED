// ============================================================
// Mcd - Máximo Común Denominador / Divisor (recursivo)
// Algoritmo de Euclides [PINEIRO]
// ============================================================
//
// Léxico (definición matemática):
//
//   Mcd : N+ x N -> N+
//
//   Mcd(a, 0) = a
//   Mcd(a, b) = Mcd(b, a mod b)   , si b > 0
//
// Idea: el máximo común divisor de a y b es igual al máximo común
// divisor de b y el resto de dividir a por b; el caso base se
// alcanza cuando el resto llega a 0, y el resultado es el otro
// operando en ese momento.
// ============================================================

#include <cassert>

// Prototipo
unsigned Mcd(unsigned a, unsigned b);

int main() {
    // Pruebas
    assert( 6 == Mcd(54, 24) );
    assert( 6 == Mcd(24, 54) );
    assert( 1 == Mcd(17,  5) );
    assert( 5 == Mcd( 5,  0) );
    assert( 5 == Mcd( 0,  5) );
    assert( 4 == Mcd( 8, 12) );
    assert(12 == Mcd(36, 60) );
    assert( 1 == Mcd( 1,  1) );
    assert( 7 == Mcd(14, 21) );
    assert(27 == Mcd(81, 27) );
}

// Definición
unsigned Mcd(unsigned a, unsigned b) { return
    b == 0 ? a :
    Mcd(b, a % b);
}
