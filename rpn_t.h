/**
 * FICHERO: stack_l_t.h
 * AUTOR: Antonio Ramos Castilla (alu0101480367@ull.edu.es)
 * PRACTICA: PRÁCTICA Nº: 5
 * VERSION: 2.0
 * FECHA: 2022-05-01
 * ESTILO: Google C++ Style Guide
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * COMENTARIOS: Clase RPN (Reverse Polish Notation)
 * COMPILACION: g++ main_rpn_t.cc -o main_rpn_t
 * EJECUCION: ./main_rpn_t < data_rpn_t_1.txt
 *            ./main_rpn_t < data_rpn_t_2.txt
 *            ./main_rpn_t < data_rpn_t_3.txt
 */

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}
  // destructor
  ~rpn_t() {}
  // operaciones
  const int evaluate(queue_l_t<char>&);
 private: 
  T stack_;
  void operate_(const char operador);
};


/**
 * @brief : Metodo para evaluar la pila
 * @param q
 * @return : stack_.top()
 */
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;
    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);  
    }
  }
  return stack_.top();
}

/**
 * @brief : Metodo de operaciones en la pila
 * @param c
 * @return : void
 */
template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == '1' || c == 'c');
  int primer_op;
  int segundo_op;
  primer_op = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << primer_op << std::endl;
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ) {
    segundo_op = stack_.top();
    stack_.pop();
  }
  std::cout << "   Sacamos de la pila otro operando: " << segundo_op << std::endl;
  int resultado;
  switch (c) {
    case '+':
      resultado = segundo_op + primer_op;
      break;
    case '-':
      resultado = segundo_op - primer_op;
      break;
    case '*':
      resultado = segundo_op * primer_op;
      break;
    case '/':
      resultado = segundo_op / primer_op;
      break;
    case '^':
      resultado = pow(segundo_op, primer_op);
      break;
    case 'r':
      resultado = sqrt(primer_op);
      break;
    case '1':
      resultado = log2(primer_op);
      break;
    case 'c':
      resultado = pow(primer_op, 2);
      break;
  }
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
  stack_.push(resultado);
}


#endif  // RPNT_H_
