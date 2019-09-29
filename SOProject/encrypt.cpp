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
#include<cmath>
#include <bitset>

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
int writeFile (char str[]) 
{
  ofstream myfile;
  myfile.open ("encrypted_message.txt", ios :: out | ios :: binary);
  myfile << str;
  myfile.close();
  return 0;
}
/* Fin de segmento de código para creación de archivo .txt */

//Initial permutation
int initial_perm[64]=  
    {    58,50,42,34,26,18,10,2, 
        60,52,44,36,28,20,12,4, 
        62,54,46,38,30,22,14,6, 
        64,56,48,40,32,24,16,8, 
        57,49,41,33,25,17,9,1, 
        59,51,43,35,27,19,11,3, 
        61,53,45,37,29,21,13,5, 
        63,55,47,39,31,23,15,7 
    }; 

int text_to_bits[99999], bits_size=0;

void Dec_to_Binary(int n) 
{ 
    int binaryNum[1000]; 
    int i = 0; 
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    for (int j = i - 1; j >= 0; j--) {
			text_to_bits[bits_size++] = binaryNum[j]; 
	}
} 

void convert_Text_to_bits(char *plain_text){
	for(int i=0;plain_text[i];i++){
		int asci = plain_text[i];
		Dec_to_Binary(asci);
	}
}

int main(void) {
    int nchars = chPrompt(nchars);
    char str[nchars + 1];  // + 1
    strInput(str, nchars);

    //convert_Text_to_bits(str);

    //Troubleshooting
    printf("El mensaje escrito tiene %d caracteres\n", (int) strlen(str));

    //LLamado de la función writeFile. 
    writeFile(str);
    printf("El archivo ha sido creado con éxito.\n");

    return 0;
}