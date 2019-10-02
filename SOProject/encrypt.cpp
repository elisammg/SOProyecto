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

int Iintial_Permutation [64] = {
	  58, 50, 42, 34, 26, 18, 10, 2,
	  60, 52, 44, 36, 28, 20, 12, 4,
	  62, 54, 46, 38, 30, 22, 14, 6,
	  64, 56, 48, 40, 32, 24, 16, 8,
	  57, 49, 41, 33, 25, 17,  9, 1,
	  59, 51, 43, 35, 27, 19, 11, 3,
	  61, 53, 45, 37, 29, 21, 13, 5,
	  63, 55, 47, 39, 31, 23, 15, 7
};

int Left32[17][32], Right32[17][32];

void round1 (int plain_bits [])
{
	int IP_result [64] , index=0;
	for (int i = 0; i < 64; i++) {
		IP_result [i] = plain_bits[ Iintial_Permutation[i] ];
	}
	for (int i = 0; i < 32; i++)
		Left32[0][i] = IP_result[i];
	for (int i = 32; i < 64; i++)
		Right32[0][i - 32] = IP_result[i];
 
	/*for (int k = 1; k < 17; k++) 
	{ // processing through all 16 rounds
		//cipher(k, 0);
 
		for (int i = 0; i < 32; i++)
			Left32[k][i] = Right32[k - 1][i]; // right part comes as it is to next round left part
	}*/
}

/*Conversión de texto a binario*/
void printBinary(char c, int nchars)
{
    string bin[20];
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

    for (int i = 0; i < s.size(); i++){
        printBinary(s[i], nchars);
        std::cout << " ";
    }

    //LLamado de la función writeFile. 
    writeFile(str);
    printf("\nEl archivo ha sido creado con éxito.\n");

    return 0;
}