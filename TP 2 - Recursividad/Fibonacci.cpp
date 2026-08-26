// ============================================================
// Fib - Sucesión de Fibonacci (recursiva)
// ============================================================
//
// Léxico (definición matemática):
//
//   Fib : N -> N
//
//   Fib(0) = 0
//   Fib(1) = 1
//   Fib(n) = Fib(n - 1) + Fib(n - 2)   , si n >= 2
//
// Nota: esta función es doblemente recursiva, ya que dentro de
// su propia definición se invoca a sí misma dos veces (una vez
// con n-1 y otra con n-2) para poder producir un único resultado.
// ============================================================

#include <cassert>

// Prototipo
unsigned long Fib(unsigned n);

int main() {
    // Pruebas
    assert(  0 == Fib( 0) );
    assert(  1 == Fib( 1) );
    assert(  1 == Fib( 2) );
    assert(  2 == Fib( 3) );
    assert(  3 == Fib( 4) );
    assert(  5 == Fib( 5) );
    assert(  8 == Fib( 6) );
    assert( 13 == Fib( 7) );
    assert( 21 == Fib( 8) );
    assert( 34 == Fib( 9) );
    assert( 55 == Fib(10) );
    assert(144 == Fib(12) );
    assert(6765 == Fib(20) );
}

// Definición
unsigned long Fib(unsigned n) { return
    n < 2 ? n :
    Fib(n - 1) + Fib(n - 2);
}
