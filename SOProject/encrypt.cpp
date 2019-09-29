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
#include <bits/stdc++.h> 

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

 
/*Conversión de texto a binario*/
int text_to_bits[99999];
int bits_size=0;

 
int Dec_to_Binary(int n) 
{ 
    int binaryNum[1000]; 
    int i = 0; 
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 

    char ch;

    for (int j = i - 1; j >= 0; j--) {
		text_to_bits[bits_size++] = binaryNum[j]; 
        //cout << text_to_bits[j];
	}
    return ch;
}
 
void convert_Text_to_ascii(char *plain_text){
	for(int i=0;plain_text[i];i++){
		int ascii = plain_text[i];
        cout << ascii;
		int bin = Dec_to_Binary(ascii);
        //cout << bin;
	}
}
/*finaliza conversión de texto a binario */

int main(void) {
    int nchars = chPrompt(nchars);
    char str[nchars + 1];  // + 1
    strInput(str, nchars);
    printf("El mensaje escrito tiene %d caracteres\n", (int) strlen(str));

    convert_Text_to_ascii(str);

    //LLamado de la función writeFile. 
    //writeFile(str);
    //printf("El archivo ha sido creado con éxito.\n");

    return 0;
}