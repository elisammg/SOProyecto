/*
Programa de encripción con algoritmo DES utilizando variables mutex.
Alumnos:
    Kevin Champney
    Elisa Monzón

Comando de compilación: g++ encrypt.cpp -o encrypt
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <bitset>
#include <atomic>

using namespace std;

/* Segmento de código para obtener mensaje por teclado con getchar() */
/* Código tomado de Stack Overflow */
void strInput(char str[], int nchars) {
    int i = 0;
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF ) {
        if (i < nchars) {
        str[i++] = ch;
        }
    }
    str[i] = '\0';
}

int chPrompt(int nchars) {
    printf("How many chars do you need to input? > ");
    if (scanf("%i", &nchars) != 1) {
        printf("Unable to read #\n"); 
        exit(-1);
    }

    // Consume remaining text in the line
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF );
        
    return nchars;
}
/* Fin de segmento de código para obtener mensaje por teclado con getchar() */

/* Segmento de código para crear un archivo .txt con el mensaje encriptado para ser decriptado más adelante. */
int writeFile (string str) 
{
  ofstream myfile;
  myfile.open ("encrypted_message.txt", ios :: out | ios :: binary);
  myfile << str;
  myfile.close();
  return 0;
}
/* Fin de segmento de código para creación de archivo .txt */

 
/*Conversión de texto a binario*/
void printBinary(char c)
{
    for (int i = 7; i >= 0; --i) 
    {
        std::cout << ((c & (1 << i))? '1' : '0');
    }
    
}

int main(void) {
    int nchars = chPrompt(nchars);
    char str[nchars + 1];  // + 1
    strInput(str, nchars);
    printf("El mensaje escrito tiene %d caracteres\n", (int) strlen(str));
	    
    std::string s(str);
	std::cout << s; 
	std::cout << std::endl;
    std::string temp;

    for (int i = 0; i < s.size(); i += 2){
        printBinary(s[i]);
        std::cout << " ";
        printBinary(s[i + 1]);
        std::cout << " ";
    }

    //LLamado de la función writeFile. 
    writeFile(temp);
    printf("\nEl archivo ha sido creado con éxito.\n");

    return 0;
}