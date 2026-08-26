// ============================================================
// Div - División entera de naturales (recursiva)
// ============================================================
//
// Léxico (definición matemática):
//
//   Div : N x N+ -> N
//
//   Div(a, b) = 0                  , si a < b
//   Div(a, b) = 1 + Div(a - b, b)  , si a >= b
//
// Idea: la división entera cuenta cuántas veces se puede restar
// el divisor b al dividendo a, hasta que el resto sea menor a b.
// ============================================================

#include <cassert>

// Prototipo
unsigned Div(unsigned a, unsigned b);

int main() {
    // Pruebas
    assert( 0 == Div( 0, 5) );
    assert( 0 == Div( 3, 5) );
    assert( 1 == Div( 5, 5) );
    assert( 1 == Div( 7, 5) );
    assert( 2 == Div(10, 5) );
    assert( 4 == Div(21, 5) );
    assert( 0 == Div( 0, 1) );
    assert(10 == Div(10, 1) );
    assert( 1 == Div( 9, 9) );
    assert( 3 == Div( 9, 3) );
    assert( 6 == Div(100, 15) );
    assert( 0 == Div( 4, 10) );
}

// Definición
unsigned Div(unsigned a, unsigned b) { return
    a < b ? 0 :
    1 + Div(a - b, b);
}
