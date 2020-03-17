int compararTexto(char str1[], char str2[]);
int _buscaLetra = 0;

int fnc_CompararString(char str1[], char str2[]){
    String Nstr1, Nstr2; 

    sprintf(Nstr1,"%s",str1);
    strtok(Nstr1,"\n");

    sprintf(Nstr2,"%s",str2);
    strtok(Nstr2,"\n");
    
    // printf("%s --> %s \n", str1 ,Nstr1);
    // printf("---------------------------------- (1) \n");
    // printf("%s --> %s \n", str2 ,Nstr2);
    // printf("-------------------------------- (2) \n"); 

    return compararTexto(Nstr1, Nstr2);
}

int compararTexto(char str1[], char str2[]){
    // printf("(%i)str1>[%c] --- (%i)str1>[%c] ---> (%i) \n", strlen(str1), str1[_buscaLetra], strlen(str2), str2[_buscaLetra], _buscaLetra);
    if(str1[_buscaLetra] == str2[_buscaLetra]){
        _buscaLetra++;
        if( strlen(str1) == _buscaLetra && strlen(str2)  == _buscaLetra){
            _buscaLetra=0;
            return 1;
        }else
        {
            return compararTexto(str1, str2);
        }
    }else
    {
        _buscaLetra=0;
        return 0;
    }
}