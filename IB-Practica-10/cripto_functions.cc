/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto_functions.cc
  * @author Francisco Marqués Armas alu0101438412@ull.es
  * @date 23 Jun 2020
  * @brief El programa le permite encriptar y desencriptar ficheros mediante el método xor o César.
  *        El método César consiste en cambiar cada caracter por un caracter desplazado un cierto número de posiciones ASCII 
  *        El método xor consiste en aplicar la operación xor a cada uno de los caracteres, con una clave dada.
  * @bug No hay bugs conocidos
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  * @see https://es.wikipedia.org/wiki/Cifrado_XOR
  * @see https://es.wikipedia.org/wiki/Cifrado_C%C3%A9sar
  */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Si se usa este tipo de criptografía desplazando cada letra tres caracteres, se usa el mismo cifrado que en el Imperio Romano
std::string CriptografiaCesar (std::string texto, std::string operacion, std::string clave){
    int operacion_entero;
            //cambiar operacion a entero para poder usar un switch
            if (operacion=="+"){
                operacion_entero=1;
            }
            else{
                operacion_entero=2;
            }
    //Cambiar clave a entero
    int clave_entero{stoi(clave)};

    size_t longitud_texto{texto.size()};
    char caracter;

    switch (operacion_entero)
    {
    case (1):
        for (size_t i=0; i<longitud_texto; i++){
           caracter= texto.at(i);
            //encriptar para letras minúsculas
            if (caracter>='a'&&caracter<='z'){
                caracter+=clave_entero;
                if(caracter>'z'){
                    //Ubicar caracteres fuera del rango
                    caracter=caracter-'z'+'a'-1;
                }
                texto.at(i)=caracter;
            }
            //ENCRIPTAR PARA LETRAS MAYÚSCULAS
            if (caracter>='A'&&caracter<='Z'){
                caracter+=clave_entero;
                if(caracter>'Z'){
                    //Ubicar caracteres fuera del rango
                    caracter=caracter-'Z'+'A'-1;
                }
                texto.at(i)=caracter;
            }
        }
        return(texto);
        break;
    case (2):
        for (size_t i=0; i<longitud_texto; i++){
           caracter= texto.at(i);
            //desencriptar para letras minúsculas
            if (caracter>='a'&&caracter<='z'){
                //Esta vez se resta la clave, en vez de sumarla
                caracter=caracter-clave_entero;
                if(caracter>'z'){
                    //Ubicar caracteres fuera del rango
                    caracter=caracter-'z'+'a'-1;
                }
                texto.at(i)=caracter;
            }
            //DESENCRIPTAR PARA LETRAS MAYÚSCULAS
            if (caracter>='A'&&caracter<='Z'){
                //Resta de de la clave
                caracter=caracter-clave_entero;
                if(caracter>'Z'){
                    //Ubicar caracteres fuera del rango
                    caracter=caracter-'Z'+'A'-1;
                }
                texto.at(i)=caracter;
            }
        }
        return(texto);
        break;
    default:
        std::cout<<"Los valores del método deben ser + o -\n";
        exit(EXIT_SUCCESS);
        break;
    }
}
std::string CriptografiaXor (std::string texto, std::string operacion, std::string clave){
    int operacion_entero;
            //cambiar operacion a entero para poder usar un switch
            if (operacion=="+"){
                operacion_entero=1;
            }
            else{
                operacion_entero=2;
            }
    size_t longitud_texto{texto.size()};

    switch (operacion_entero)
    {
    case (1):
        for (size_t i=0; i<=longitud_texto; i++){
            texto[i]=texto[i]^clave[i];
        }
        return(texto);
        break;
    case (2):
        //Para un correcto funcionamiento, no debe diferenciarse el procedimiento del encriptado con respecto al desencriptado
        for (size_t i=0; i<=longitud_texto; i++){
            texto[i]=texto[i]^clave[i];
        }
        return(texto);
        break;
    default:
        std::cout<<"Los valores del método deben ser + o -\n";
        exit(EXIT_SUCCESS);
        break;
    }
}

int NumeroPalabras (std::string texto){
   std::string palabra;
 
   bool inSpaces = true;
   int numWords = 0;
 
  for ( char const &caracter: texto)
  {
     if (std::isspace(caracter))
     {
        inSpaces = true;
     }
     else if (inSpaces)
     {
        numWords++;
        inSpaces = false;
     }
  }
 
  return numWords;
}
