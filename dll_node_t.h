/**
 * FICHERO: dll_node_t.h
 * AUTOR: Antonio Ramos Castilla (alu0101480367@ull.edu.es)
 * PRACTICA: PRÁCTICA Nº: 5
 * VERSION: 2.0
 * FECHA: 2022-05-01
 * ESTILO: Google C++ Style Guide
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * COMPILACION: g++ main_rpn_t.cc -o main_rpn_t
 * EJECUCION: ./main_rpn_t < data_rpn_t_1.txt
 *            ./main_rpn_t < data_rpn_t_2.txt
 *            ./main_rpn_t < data_rpn_t_3.txt
 */

#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

// Clase para nodos de listas doblemente enlazadas
template <class T> class dll_node_t {
 public:
  // constructores
  dll_node_t() : prev_(NULL), data_(), next_(NULL) {}  // por defecto
  dll_node_t(const T& data) : prev_(NULL), data_(data), next_(NULL) {}
  // destructor
  ~dll_node_t(void) {}
  // getters & setters
  dll_node_t<T>* get_next(void) const { return next_; }
  void set_next(dll_node_t<T>* next) { next_ = next; }
  dll_node_t<T>* get_prev(void) const { return prev_; }
  void set_prev(dll_node_t<T>* prev) { prev_ = prev; }
  const T& get_data(void) const { return data_; }
  void set_data(const T& data) { data_ = data; }
  // E/S
  std::ostream& write(std::ostream& = std::cout) const;
 private:
  dll_node_t<T>* prev_;
  T data_;
  dll_node_t<T>* next_;
};

/**
 * @brief : Método de escritura
 * @param os
 * @return : os
 */
template <class T> std::ostream& dll_node_t<T>::write(std::ostream& os) const {
  os << data_;
  return os;
}

#endif  // DLL_NODET_H_
