//Subrutina que llama a la función Encrypt.
void * callEncryptDecrypt(void *str){
    
    std::string encrypted = *reinterpret_cast<std::string*>(str);

    

    Des d1, d2;
    char *str1=new char[1000];

    str1=d1.Encrypt((char *)&encrypted);

    cout<<"\nWritten text: "<<encrypted<<endl;
    cout<<"\nEncrypted text is: "<<str1<<endl;
    //  ofstream fout("out2_fil.txt"); fout<<str1; fout.close();
    cout<<"\nThe text after being decrypted: "<<d2.Decrypt((char *)&encrypted)<<endl;

}


//Llamado de la subrutina.
    err = pthread_create(&(tid[0]), NULL, &callEncryptDecrypt, (void *)&s);
    pthread_join(tid[0], NULL);


    int nchars = chPrompt(nchars);
    char str[nchars + 1];  // + 1
    strInput(str, nchars);


    std::string s = str;