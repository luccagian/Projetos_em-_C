/*
Calculadora de polinômios
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int mostra_poli(int coe[], int tp); // imprime o  polinomio formatado
    
int valor_x(int coe[], int tp, float x); // calcula o valor do polinomio

int * soma_poli(int vet1[], int vet2[], int ts1, int ts2,int *tp, int coe[]); // soma dois polinomios 

int * multi_poli(int vet1[], int vet2[], int ts1, int ts2, int *tp, int coe[]); // multiplica dois polinomios

int main(){
    
    int r = 0; // variavel que define opção do menu
    int tp = 0; // variavel que define o tamanho do polinomio
    int coef; // coeficientes dos expoentes  
    int *coe  = (int *)malloc(tp * sizeof(int)); // define o tamanho do vetor

    float x; // valor que ira substituir x no polinomio
    float res; // resultado do polinomio

//------------------//
//vetores para soma e multiplicacao

    int ts1 = 0; // armazena o tamanho do polinomio 1 
    int ts2 = 0; // armazena o tamanho do polinomio 2 
    int *vet1 = (int *)malloc(ts1 * sizeof(int)); // define o tamanho do polinomio a ser somado
    int *vet2 = (int *)malloc(ts2 * sizeof(int)); // define o tamanho do segundo polinomio a ser somado

    do{
        printf("\n----- Menu -----\n");
        printf("1 - Adicione um polinomio\n");
        printf("2 - Calcule a soma dos polinomios\n");
        printf("3 - Calcule a multiplicacao dos polinomios\n");
        printf("4 - Calcule o valor de x do polinomio\n");
        printf("5 - Imprime o polinomio\n");
        printf("6 - Zerar valor dos coeficientes\n");
        printf("7 - Sair\n\n");
        printf("Insira uma das opcoes acima: ");
        scanf("%d", &r);

        printf("\nVoce escolheu: %d\n\n", r);

        if (r == 1){ 
            printf("Determine o tamanho do polinomio: ");
            scanf("%d", &tp);
            tp++;

            coe  = (int *)malloc(tp * sizeof(int)); // define o tamanho do vetor

            for (int i = 0; i<tp; i++){ 
                printf("Insira o valor e seu sinal (+/-) para o coeficinete em x^%d: ", i);
                scanf("%d", &coef); // adiciona os valores dos coeficinetes do polinomio
                coe[i] = coef;
                }
            printf("\nPolinomio impresso:\n");
            mostra_poli(coe, tp);   
        }

        if (r == 2){

            printf("Primeiro polinomio:\n");
            printf("Determine o tamanho primeiro do polinomio: ");
            scanf("%d", &ts1);
            ts1++;

            vet1  = (int *)malloc(ts1 * sizeof(int)); // define o tamanho do vetor  1
            
            for (int i = 0; i<ts1; i++){ 
                printf("Insira o valor e seu sinal (+/-) para o coeficinete em x^%d: ", i);
                scanf("%d", &coef); // adiciona os valores dos coeficinetes do polinomio
                vet1[i] = coef;
                }
            
            printf("Segundo polinomio:\n");
            printf("Determine o tamanho do segundo polinomio: ");
            scanf("%d", &ts2);
            ts2++;
            
            vet2  = (int *)malloc(ts2 * sizeof(int)); // define o tamanho do vetor 2

            for (int i = 0; i<ts2; i++){ 
                printf("Insira o valor e seu sinal (+/-) para o coeficinete em x^%d: ", i);
                scanf("%d", &coef); // adiciona os valores dos coeficinetes do polinomio
                vet2[i] = coef;
                }

            coe = soma_poli(vet1, vet2, ts1, ts2, &tp, coe);
            printf("\nSoma dos polinomios efetuada com sucesso!!!\n\n");
            printf("Polinomio impresso:\n");
            mostra_poli(coe, tp);
        }

        if (r == 3){

            printf("Primeiro polinomio:\n");
            printf("Determine o tamanho primeiro do polinomio: ");
            scanf("%d", &ts1);
            ts1++;

            vet1  = (int *)malloc(ts1 * sizeof(int)); // define o tamanho do vetor 1
            
            for (int i = 0; i<ts1; i++){ 
                printf("Insira o valor e seu sinal (+/-) para o coeficinete em x^%d: ", i);
                scanf("%d", &coef); // adiciona os valores dos coeficinetes do polinomio
                vet1[i] = coef;
                }
            
            printf("Segundo polinomio:\n");
            printf("Determine o tamanho do segundo polinomio: ");
            scanf("%d", &ts2);
            ts2++;
            
            vet2  = (int *)malloc(ts2 * sizeof(int)); // define o tamanho do vetor 2

            for (int i = 0; i<ts2; i++){ 
                printf("Insira o valor e seu sinal (+/-) para o coeficinete em x^%d: ", i);
                scanf("%d", &coef); // adiciona os valores dos coeficinetes do polinomio
                vet2[i] = coef;
                }

            coe = multi_poli(vet1, vet2, ts1, ts2, &tp, coe);
            printf("\nMultiplicacao dos polinomios efetuada com sucesso!!!\n\n");
            printf("Polinomio impresso:\n");
            mostra_poli(coe, tp);
        }

        if (r == 4){
            printf("Insira o valor do coeficiente x para calcular o polinomio: ");
            scanf("%f", &x);
            res = valor_x(coe, tp, x);
            printf("\nO resultado do polinomio para x igual a: %.1f\neh igual a: %.1f\n",x, res);
            coe = 0;
        } 

        if (r == 5){
            printf("Polinomio impresso:\n");
            mostra_poli(coe, tp);
        }

        if (r == 6){
            coe = 0;
            printf("Voce zerou todos os coeficientes\n");
        }

        if (r == 7){
            printf("Voce saiu da calculadora\n");
        }

    } while(r != 7);

    free(vet1);
    free(vet2);
    free(coe);

    return 0;
}

int mostra_poli(int coe[], int tp){ //Funçao para exibir um polinomio no formato legiel
    
    int *aux  = (int *)malloc(tp * sizeof(int)); // cria um vetor auxiliar
    for (int i = 0; i < tp ; i++)
    {   
        aux[i] = coe[tp - (i+1)]; // inverte o vetor dos coeficietes

        if (i == 0){ // nao mostra o + do primeiro termo
        } else if (aux[i]>0){ // adiciona o simbolo de soma 
            printf("+");
            }
        if (aux[i] == 0){ // oculta o coeficiente zero
        } else if (((tp - i)-1) != 0){
            printf("%dx^%d", aux[i], ((tp - i)-1));
            } else {
                printf("%d\n", aux[i]); // aculta o x elevado a zero
                }
    }

    free(aux);
    return 0;
}

int valor_x(int coe[], int tp, float x){ //substitui x no polinomio e calcula seu valor 

    float res = 0;
    for (int i = 0; i < tp; i++){
        res += coe[i] * (pow(x, i));  // calcula coeficiente * x elevado a grau
    }
    return res;
}

int * soma_poli(int vet1[], int vet2[], int ts1, int ts2, int *tp, int coe[]){

    *tp = (ts1 > ts2) ? ts1 : ts2; // atribui o  maior vetor para o vetor resultante

    coe  = (int *)malloc(*tp * sizeof(int));

    for (int i = 0; i < *tp; i++)
    {
        int coef1 = 0;
        int coef2 = 0;
        if(i < ts1){
            coef1 = vet1[i]; // adiciona zero se o vetor 1 for menor que o resoltante 
        }
        if(i < ts2){
            coef2 = vet2[i]; // adiciona zero se o vetor 2 for menor que o resoltante 
        }
        coe[i] = coef1 + coef2; // soma os coeficietes 
    }
    return coe;
}

int * multi_poli(int vet1[], int vet2[], int ts1, int ts2, int *tp, int coe[]){
    
    *tp = (ts1 + ts2) + 1; // tp eh igual a soma o tamanho dos vetores

    coe  = (int *)malloc(*tp * sizeof(int)); // define o tamanho do vetor

    for (int i = 0; i < *tp; i++){   // zera o vetor resultante
        coe[i] = 0;
    }

    for (int i = 0; i < ts1; i++){  
        for (int j = 0; j < ts2; j++){
            coe[i+j] += vet1[i] * vet2[j]; // realiza a multiplicacao dos polinomios indice por indice
        }
    }
    return coe;    
}
