/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto.cc
  * @author Francisco Marqués Armas alu0101438412@ull.es
  * @date 23 Jun 2020
  * @brief El programa le permite encriptar y desencriptar ficheros mediante el método xor o César.
  *        El método César consiste en cambiar cada caracter por uno desplazado un cierto número de posiciones ASCII 
  *        El método xor consiste en aplicar la operación xor a cada uno de los caracteres, con una clave dada.
  * @bug "Tipo incompleto", como si me faltase la librería, pero está incluida
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include <iostream>
#include <vector>
#include <string>
#include "cripto_header.h"
#include <fstream>//Para la entrada/salida de ficheros
#include <stdlib.h>
std::string Lectura(std::string ruta_entrada){
    //ifstream se usa para leer archivos. Retira ficheros del flujo.
    std::ifstream inFile;
    inFile.open(ruta_entrada);
    //Comprobar que el archivo se abrió correctamente
    if (!inFile){
        std::cout<<"No se pudo abrir "<<ruta_entrada<<"\n";
        exit(EXIT_SUCCESS);
    }
    //Pasar contenidos del archivo a una string
    std::string archivo_string;
    while(!inFile.eof()){
        std::getline (inFile, archivo_string);
        //Imprimir contenidos del archivo introducido
        std::cout<<archivo_string;

    }
    inFile.close();//Cerrar el archivo
    return (archivo_string);
}
void Escritura(std::string ruta_salida, std::string contenidos_archivo){
    //ofstream se usa para crear archivos, se crea un archivo con nombre "ejemplo.txt". Añade ficheros al flujo.
    std::ofstream outFile;
    outFile.open(ruta_salida);
    //Volvemos a comprobar si se ha abierto el archivo para su escritura
    if (!outFile){
        std::cout<<"No se pudo crear "<<ruta_salida<<"\n";
        exit(EXIT_SUCCESS);
    }
    outFile<<contenidos_archivo;
    outFile.close();//Cerrar el archivo
}   
void Usage (int argc, char *argv[]){
    if (argc==1){
        std::cout<< argv[0]<<"-- Cifrado de ficheros \n";
        std::cout<<"Modo de uso: "<<argv[0]<<" fichero_entrada fichero_salida método password operación \n";
        std::cout<<" Pruebe " << argv[0] <<" --help para más información \n";
            exit(EXIT_SUCCESS);
    }
    if (argc!=6){
        std::cout<< argv[0]<<"-- Cifrado de ficheros \n";
        std::cout<<"Modo de uso: "<<argv[0]<<"fichero_entrada fichero_salida método password operación \n";
        std::cout<<" Pruebe " << argv[0] <<"--help para más información \n";
        std::cout<<"Ha introducido un número de parámetros incorrecto \n";
            exit(EXIT_SUCCESS);
    }
    std::string parameter {argv[1]};
    if (parameter == "--help"){
        std::cout<< argv[0]<<"-- Cifrado de ficheros \n";
        std::cout<<"Modo de uso: "<<argv[0]<<"fichero_entrada fichero_salida método password operación \n";
        std::cout<<"fichero_entrada: Fichero a codificar (ruta completa)"<<"\n";
        std::cout<<"fichero_salida: Fichero codificado"<<"\n";
        std::cout<<"método: indica el método de encriptado"<<"\n";
        std::cout<<"    1: cifrado xor"<<"\n";
        std::cout<<"    2: cifrado de César"<<"\n";
        std::cout<<"password: Palabra secreta en el caso del método 1, valor de K en el método 2"<<"\n";
        std::cout<<"operación: Operación a realizar en el fichero"<<"\n";
        std::cout<<"    +: encriptar el fichero"<<"\n";
        std::cout<<"    -: desencriptar el fichero"<<"\n";
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv){
    Usage(argc, argv);
    std::string ruta_fichero_entrada{argv[1]};
    std::string ruta_fichero_salida{argv[2]};
    int metodo{std::stoi (argv[3])};
    std::string password {argv[4]};
    std::string operacion{argv[5]};
    switch (metodo)
    {
    case (1):
        Escritura(ruta_fichero_salida, CriptografiaCesar(Lectura(ruta_fichero_entrada), operacion, password));
        break;
    case (2):
        Escritura(ruta_fichero_salida, CriptografiaXor(Lectura(ruta_fichero_entrada), operacion, password));
    default:
        break;
    }
}