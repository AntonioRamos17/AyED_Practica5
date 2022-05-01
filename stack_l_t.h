/**
 * FICHERO: stack_l_t.h
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

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}
  // destructor
  ~stack_l_t(void) {}
  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;
 private:
  dll_t<T> l_;
};


/**
 * @brief : Método para extraer de la pila
 * @param dato
 * @return : void
 */
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

/**
 * @brief : Método para insertar en la pila
 * @param void
 * @return : void
 */
template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

/**
 * @brief : Getter del top de la pila
 * @param void
 * @return : l_.get_head()->get_data()
 */
template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

/**
 * @brief : Comprueba si la pila está vacía
 * @param void
 * @return : l_.empty()
 */
template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

/**
 * @brief : Método de escritura de la pila
 * @param os
 * @return : os
 */
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}


#endif  // STACKL_H_
