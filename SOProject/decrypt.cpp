/*
g++ decrypt.cpp -o decrypt
*/

#include <iostream>
#include <fstream>

int main() {
   std::ifstream file("encrypted_message.txt");
   if(!file)return 0;
   std::string line;

   while (std::getline(file, line, '\0')){
      for(char ascii : line){
         std::cout<<ascii;
      }
   }
   printf("\n");
   return 0;
}
