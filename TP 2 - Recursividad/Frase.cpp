// ============================================================
// RepetirFrase - Repetir frase (recursiva)
// ============================================================
//
// Léxico (definición matemática):
//
//   RepetirFrase : String x N -> String
//
//   RepetirFrase(s, 0) = ""
//   RepetirFrase(s, n) = s + RepetirFrase(s, n - 1)   , si n > 0
//
// Idea: concatenar la frase s consigo misma n veces, reduciendo
// en cada invocación recursiva la cantidad de repeticiones
// pendientes, hasta llegar al caso base (0 repeticiones = "").
// ============================================================

#include <cassert>
#include <string>

using namespace std;

// Prototipo
string RepetirFrase(string s, unsigned n);

int main() {
    // Pruebas
    assert( ""                    == RepetirFrase("Hola", 0) );
    assert( "Hola"                == RepetirFrase("Hola", 1) );
    assert( "HolaHola"            == RepetirFrase("Hola", 2) );
    assert( "HolaHolaHola"        == RepetirFrase("Hola", 3) );
    assert( "AED"                 == RepetirFrase("AED", 1) );
    assert( "AEDAEDAEDAED"        == RepetirFrase("AED", 4) );
    assert( ""                    == RepetirFrase("", 5) );
    assert( "!!!!!"                == RepetirFrase("!", 5) );
}

// Definición
string RepetirFrase(string s, unsigned n) { return
    n == 0 ? "" :
    s + RepetirFrase(s, n - 1);
}
