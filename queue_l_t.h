/**
 * FICHERO: queue_l_t.h
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

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;
 public:
  // constructor
  queue_l_t(void) : l_() {}
  // destructor
  ~queue_l_t(void) {}
  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;
  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


/**
 * @brief : Comprueba si está vacío
 * @param void
 * @return : l_.empty
 */
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

/**
 * @brief : Devuelve el tamaño de la cola
 * @param void
 * @return : l_.get_size()
 */
template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

/**
 * @brief : Extrae un dato en la cola
 * @param dato
 * @return : l_.push_front(node)
 */
template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

/**
 * @brief : Inserta un dato en la cola
 * @param void
 * @return : l_.pop_back()
 */
template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

/**
 * @brief : Getter del dato de la cola
 * @param void
 * @return : l_.get_tail()->get_data()
 */
template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

/**
 * @brief : Getter del dato de la cabeza
 * @param void
 * @return : l_.get_head()->get_data()
 */
template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

/**
 * @brief : Método de escritura de la cola
 * @param os
 * @return : os
 */
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

/**
 * @brief : Sobrecarga del operador << 
 * @param os
 * @param q
 * @return : os
 */
template<class T> std::ostream& operator<<(std::ostream& os, const queue_l_t<T>& q) {
  q.write(os);
  return os;
}


#endif  // QUEUE_H_
