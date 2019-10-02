
/*
Programa de desencriptación con algoritmo DES utilizando variables mutex.
Alumnos:
    Kevin Champney
    Elisa Monzón

Comando de compilación: g++ decrypt.cpp -o decrypt
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <bitset>

int main() {
   std::ifstream file("encrypted_message.txt");
   if(!file)return 0;
   std::string line;

   std::string ch;

   while (std::getline(file, line, '\0')){
      for(char ascii : line){
         ch += ascii;
      }
   }

   std::cout << ch << std::endl;
   return 0;
}
