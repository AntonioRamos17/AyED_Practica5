/**
 * FICHERO: main_rpn_t.cc
 * AUTOR: Antonio Ramos Castilla (alu0101480367@ull.edu.es)
 * PRACTICA: PRÁCTICA Nº: 5
 * VERSION: 2.0
 * FECHA: 2022-05-01
 * ESTILO: Google C++ Style Guide
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * COMENTARIOS: Programa principal para probar la calculadora de expresiones 
 *              en notaión polaca inversa (RPN, Reverse Polish Notation)
 * COMPILACION: g++ main_rpn_t.cc -o main_rpn_t
 * EJECUCION: ./main_rpn_t < data_rpn_t_1.txt
 *            ./main_rpn_t < data_rpn_t_2.txt
 *            ./main_rpn_t < data_rpn_t_3.txt
 */

#include <iostream>

#include "stack_l_t.h"
#include "queue_l_t.h"
#include "rpn_t.h"

int main(void) {
  rpn_t<stack_l_t<int>> calculadora;
  queue_l_t<char> cola;
  while (!std::cin.eof()) 	{
    std::cin >> std::ws; // lee los espacios en blanco, que dan problemas
    if (!std::cin.eof()) {
      char c;
      std::cin >> c;
      cola.push(c);
    }
  }
  std::cout << "Expresión a evaluar: ";	
  cola.write();
  int r = calculadora.evaluate(cola);
  std::cout << "Resultado: " << r << std::endl;
  return 0;
}

