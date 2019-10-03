
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
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 16 //hilos
int in, out, cont, buffer[8]; 				//declaración de variables globales: buffer contiene 8"espacios/localidades"
pthread_cond_t lleno, vacio; 				//objetos condicionales
pthread_mutex_t lock; 						//objetos mutex

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

   //Creación de hilos 
    pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   
   for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, RondasDES, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
