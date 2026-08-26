# DD-Recur

Trabajo Práctico #10 — Funciones Recursivas con Operador Condicional

## Objetivo

Demostrar el manejo de funciones definidas recursivamente e implementadas
con el operador condicional (`?:`).

## Contenido

| Archivo         | Función        | Descripción                                              |
|-----------------|----------------|-----------------------------------------------------------|
| `Div.cpp`       | `Div`          | División entera de naturales                              |
| `Mcd.cpp`       | `Mcd`          | Máximo Común Divisor (algoritmo de Euclides)               |
| `Factorial.cpp` | `Fact`         | Factorial                                                  |
| `Fibonacci.cpp` | `Fib`          | Sucesión de Fibonacci (doblemente recursiva)               |
| `Frase.cpp`     | `RepetirFrase` | Repetición de una frase n veces                            |
| `Rec.cpp`       | `SumaDigitos`  | Función propia: suma de los dígitos de un natural          |
| `Svg.cpp`       | `Sierpinski`   | Crédito extra: fractal Triángulo de Sierpinski en SVG      |

## Restricciones cumplidas

- Todas las pruebas se realizan con `assert`.
- Todas las funciones aplican el operador condicional (`?:`) en su
  definición.

## Cómo compilar y correr cada programa

Cada archivo es independiente y contiene su propio `main` con las
pruebas:

```bash
g++ -std=c++17 -Wall -o Div Div.cpp && ./Div
g++ -std=c++17 -Wall -o Mcd Mcd.cpp && ./Mcd
g++ -std=c++17 -Wall -o Factorial Factorial.cpp && ./Factorial
g++ -std=c++17 -Wall -o Fibonacci Fibonacci.cpp && ./Fibonacci
g++ -std=c++17 -Wall -o Frase Frase.cpp && ./Frase
g++ -std=c++17 -Wall -o Rec Rec.cpp && ./Rec
g++ -std=c++17 -Wall -o Svg Svg.cpp && ./Svg
```

Si ningún `assert` falla, el programa termina sin imprimir nada
(comportamiento esperado de un `assert` exitoso).

`Svg.cpp` además genera un archivo `fractal.svg` con un Triángulo de
Sierpinski de 5 niveles de recursión.

## Notas de diseño

- **`Fact`** usa `unsigned long` porque el factorial crece muy rápido y
  desborda un `int`/`unsigned` a partir de valores relativamente chicos
  (ver Fact(13) en adelante).
- **`Fib`** es doblemente recursiva: dentro de su propia definición se
  invoca a sí misma dos veces (`Fib(n-1)` y `Fib(n-2)`).
- **`Mcd`** implementa el algoritmo de Euclides recursivo [PINEIRO].
- **`Sierpinski`** (crédito extra) genera el fractal como una cadena de
  elementos `<polygon>` SVG, dividiendo recursivamente cada triángulo en
  3 triángulos de la mitad del tamaño (se descarta el triángulo central).
  Se agrega una función auxiliar `NumTriangulos(n) = 3^n` para poder
  verificar con `assert` que la cantidad de triángulos generados en cada
  nivel de recursión es la esperada.
