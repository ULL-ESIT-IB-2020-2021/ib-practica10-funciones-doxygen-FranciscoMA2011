/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto_header.h
  * @author Francisco Marqués Armas alu0101438412@ull.es
  * @date 23 Jun 2020
  * @brief El programa le permite encriptar y desencriptar ficheros mediante el método xor o César.
  *        El método César consiste en cambiar cada caracter por un caracter desplazado un cierto número de posiciones ASCII 
  *        El método xor consiste en aplicar la operación xor a cada uno de los caracteres, con una clave dada.
  * @bug No hay bugs conocidos
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

std::string CriptografiaCesar (std::string texto, std::string operacion, std::string clave);
std::string CriptografiaXor (std::string texto, std::string operacion, std::string clave);
int NumeroPalabras (std::string texto);