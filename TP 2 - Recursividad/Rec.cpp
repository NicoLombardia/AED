// ============================================================
// SumaDigitos - Suma de los dígitos de un natural (recursiva)
// Función recursiva propia (no vista en clase)
// ============================================================
//
// Léxico (definición matemática):
//
//   SumaDigitos : N -> N
//
//   SumaDigitos(n) = n                                  , si n < 10
//   SumaDigitos(n) = n mod 10 + SumaDigitos(n div 10)   , si n >= 10
//
// Idea: si el número tiene un solo dígito, la suma de sus dígitos
// es el propio número (caso base). Si tiene más de un dígito, se
// suma el último dígito (n mod 10) con la suma de dígitos del
// resto del número, obtenido al quitarle ese último dígito
// (n div 10).
// ============================================================

#include <cassert>

// Prototipo
unsigned SumaDigitos(unsigned n);

int main() {
    // Pruebas
    assert( 0 == SumaDigitos(0) );
    assert( 5 == SumaDigitos(5) );
    assert( 9 == SumaDigitos(9) );
    assert( 3 == SumaDigitos(12) );      // 1 + 2
    assert( 6 == SumaDigitos(123) );     // 1 + 2 + 3
    assert( 1 == SumaDigitos(100) );     // 1 + 0 + 0
    assert(45 == SumaDigitos(123456789)); // 1+2+...+9
    assert(27 == SumaDigitos(999));      // 9+9+9
    assert( 7 == SumaDigitos(70) );      // 7 + 0
}

// Definición
unsigned SumaDigitos(unsigned n) { return
    n < 10 ? n :
    n % 10 + SumaDigitos(n / 10);
}
