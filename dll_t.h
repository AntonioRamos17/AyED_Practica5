/**
 * FICHERO: dll_t.h
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

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}
  // destructor
  ~dll_t(void); 
  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }
  bool empty(void) const;
  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);
  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);
  dll_node_t<T>* erase(dll_node_t<T>*);
  // E/S
  std::ostream& write(std::ostream& = std::cout) const;
 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


/**
 * @brief : Destructor de la clase
 * @param void
 * @return : void
 */
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

/**
 * @brief : Comprueba que la lista esté vacía
 * @param void
 * @return : true/false
 */
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

/**
 * @brief : Insertar delante de un nodo
 * @param nodo
 * @return : void
 */
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);
  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

/**
 * @brief : Insertar por detrás 
 * @param nodo
 * @return : void
 */
template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);
  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

/**
 * @brief : Extraer por detrás
 * @param void
 * @return : aux
 */
template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());
  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

/**
 * @brief : Insertar por delante
 * @param void
 * @return : aux
 */
template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());
  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

/**
 * @brief : Borrar un nodo
 * @param nodo
 * @return : nodo
 */
template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
  assert(nodo != NULL);
  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

/**
 * @brief : Método de escritura
 * @param os
 * @return : os
 */
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;
  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // DLLT_H_
