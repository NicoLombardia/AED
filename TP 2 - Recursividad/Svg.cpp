// ============================================================
// Svg - Crédito Extra: Fractal en SVG (recursivo)
// Triángulo de Sierpinski
// ============================================================
//
// Léxico (definición matemática):
//
//   NumTriangulos : N -> N
//
//   NumTriangulos(0) = 1
//   NumTriangulos(n) = 3 * NumTriangulos(n - 1)   , si n > 0
//
//   (Cada nivel de recursión reemplaza cada triángulo por 3
//    triángulos de la mitad del tamaño, quitando el triángulo
//    central)
//
//   Sierpinski : Punto x Punto x Punto x N -> String(SVG)
//
//   Sierpinski(p1, p2, p3, 0) = <polygon>(p1, p2, p3)
//   Sierpinski(p1, p2, p3, n) = Sierpinski(p1,   m12, m13, n-1) +
//                               Sierpinski(m12,  p2,  m23, n-1) +
//                               Sierpinski(m13, m23,  p3,  n-1) , si n > 0
//
//   donde mIJ es el punto medio entre pI y pJ.
// ============================================================

#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Punto { double x, y; };

// Prototipos
unsigned NumTriangulos(unsigned n);
Punto PuntoMedio(Punto a, Punto b);
string DibujarTriangulo(Punto p1, Punto p2, Punto p3);
string Sierpinski(Punto p1, Punto p2, Punto p3, unsigned n);
unsigned ContarPoligonos(const string &svg);

int main() {
    // Pruebas - NumTriangulos
    assert(  1 == NumTriangulos(0) );
    assert(  3 == NumTriangulos(1) );
    assert(  9 == NumTriangulos(2) );
    assert( 27 == NumTriangulos(3) );
    assert( 81 == NumTriangulos(4) );

    // Pruebas - PuntoMedio
    Punto a{0, 0}, b{10, 0};
    Punto m = PuntoMedio(a, b);
    assert(m.x == 5 && m.y == 0);

    // Pruebas - Sierpinski: la cantidad de <polygon> generados en el
    // SVG debe coincidir exactamente con NumTriangulos(n)
    Punto p1{0, 0}, p2{400, 0}, p3{200, 346};

    string svg0 = Sierpinski(p1, p2, p3, 0);
    assert( ContarPoligonos(svg0) == NumTriangulos(0) );

    string svg1 = Sierpinski(p1, p2, p3, 1);
    assert( ContarPoligonos(svg1) == NumTriangulos(1) );

    string svg3 = Sierpinski(p1, p2, p3, 3);
    assert( ContarPoligonos(svg3) == NumTriangulos(3) );

    string svg5 = Sierpinski(p1, p2, p3, 5);
    assert( ContarPoligonos(svg5) == NumTriangulos(5) );

    // Producto final: se escribe el fractal a un archivo SVG
    unsigned nivel = 5;
    ofstream out{"fractal.svg"};
    out << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
        << "viewBox=\"0 0 400 350\">\n"
        << "<!-- Triangulo de Sierpinski - nivel " << nivel << " -->\n"
        << Sierpinski(p1, p2, p3, nivel)
        << "</svg>\n";
}

// Definiciones

unsigned NumTriangulos(unsigned n) { return
    n == 0 ? 1 :
    3 * NumTriangulos(n - 1);
}

Punto PuntoMedio(Punto a, Punto b) { return
    Punto{ (a.x + b.x) / 2, (a.y + b.y) / 2 };
}

string DibujarTriangulo(Punto p1, Punto p2, Punto p3) {
    ostringstream svg;
    svg << "<polygon points=\""
        << p1.x << "," << p1.y << " "
        << p2.x << "," << p2.y << " "
        << p3.x << "," << p3.y
        << "\" fill=\"black\" />\n";
    return svg.str();
}

string Sierpinski(Punto p1, Punto p2, Punto p3, unsigned n) { return
    n == 0 ? DibujarTriangulo(p1, p2, p3) :
    Sierpinski(p1, PuntoMedio(p1, p2), PuntoMedio(p1, p3), n - 1) +
    Sierpinski(PuntoMedio(p1, p2), p2, PuntoMedio(p2, p3), n - 1) +
    Sierpinski(PuntoMedio(p1, p3), PuntoMedio(p2, p3), p3, n - 1);
}

unsigned ContarPoligonos(const string &svg) {
    unsigned contador = 0;
    string etiqueta = "<polygon";
    size_t pos = svg.find(etiqueta);
    while (pos != string::npos) {
        contador++;
        pos = svg.find(etiqueta, pos + etiqueta.size());
    }
    return contador;
}
