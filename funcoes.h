int entradaIngressos_teste(int tam){
    FILE *file;
    file = fopen("idades.txt","r");
    int valor[tam];

    for(int i=0;i<tam;i++){
        if (fscanf(file, "%d", &valor[i]) == 1) {
        }else{
            printf("\nErro ao ler o número [%d]",i);
            return 1; // falso
        }
    }
    fclose(file);
    return 0; //verdadeiro
}

void criaArquivoEntradaIngressos(int tam, int vetor[tam]){
    FILE *file;
    file = fopen("idades.txt","w");
    fprintf(file,"7\n14\n30\n60");
    //10+30+30+15 =85
    fclose(file);

    file = fopen("idades.txt","a");
    for(int i=0;i<tam;i++){
        fprintf(file,"%d\n",vetor[i]);
    }
}
void criaArquivoEntrada(int tam){
    FILE *file;
    file = fopen("entrada.txt","w");
    fprintf(file,"%d\n",tam);
    fclose(file);
}

int entrada(){
    int qtdBi;
    printf("\nInforme a quantidade de bilhetes a serem comprados: ");
    scanf("%d",&qtdBi);
    if(qtdBi>5){
        printf("\nQuantidade superior a 5, que é quantidade máxima permitida.\n");
        entrada();
    }
    return qtdBi;
}
int entrada_teste(){
    int qtdBi;
    FILE *file;
    file = fopen("entrada.txt","r");

    if (!file) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    if (fscanf(file, "%d", &qtdBi) != 1) {
        fclose(file);
        printf("\nErro ao ler número do arquivo.\n");
        return 1;
    }
    fclose(file);
    if(qtdBi>5){
        printf("\n%d",qtdBi);
        printf("\nQuantidade superior a 5, que é quantidade máxima permitida.\n");
        return 1;
    }
    return qtdBi;
}

int *entradaIngressos(int ingressos[],int tam){
    setlocale(LC_ALL, "Portuguese");
    for(int i=0;i<tam;i++){
        do{
        printf("\nInforme a idade do ingresso Nº %d: ",i+1);
        scanf("%d", &ingressos[i]);
        }while(ingressos[i]>100 || ingressos[i]<0);
        //Duvida01: do while pode se configurar com teste unitário, no caso dos scanf? Mesmo que sem ser automtizado
    }
    return ingressos;
}

int calculaIngressos(int ingressos[], int tam){
    int soma=0;
    for(int i=0;i<tam;i++){
        if(ingressos[i]<=12){
            soma+=10;
        }
        else if(ingressos[i]>12 && ingressos[i] <60 ){
            soma+=30;
        }else{
            soma+=15;
        }
    }
    return soma;
}


