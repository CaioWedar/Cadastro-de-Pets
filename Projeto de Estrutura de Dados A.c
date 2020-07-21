/*
Nome: Caio Alves Fagundes 					RA:19668771
Nome: Paulo Ballardini Souza Campos			RA:19245307
Opcionais funcionando:Opicinal 1(data e hora do cadastro e alt) e Opcional 2(interface grafica)
Valor do Projeto:  _______ pontos
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include "tela.h"

struct pets
{

    int id;
    
    time_t cad;
    time_t alt;

    int idade;
    char nome[20];
    char especie[20];
    char raca[20];
    char carac[30];
    char sexo;

    struct pets *prox;
};

typedef struct pets pets;

void cadastro(pets (**raiz), int cont);

void alterar(pets (**raiz));

void busca(pets *raiz);

void listar(pets *raiz);

void deletar(pets (**raiz));

void adotados(pets (**raiz));

int main()
{

    setlocale(LC_ALL, "portuguese");

    int menu, qnt, i; 
	int cont = 0;
    pets *raiz = NULL;
	
    
    textbackground(CIANO);
    clrscr();
    textcolor(VERMELHO);

    do
    {
   
        printf("1. Cadastrar Novo Animal.\n");
        printf("2. Atualizar Cadastro.\n");
        printf("3. Buscar Animal.\n");
        printf("4. Listagem e Contagem dos Cadastratros.\n");
        printf("5. Remover Cadastros.\n");
        printf("0. Sair\n");
        printf("->: ");
        scanf("%d", &menu);

        system("cls");

        switch(menu)
        {
        case 1:

            printf("Quantos animais deseja cadastrar?: \n");
            printf("->: ");
            scanf("%d", &qnt);

            system("cls");

            for(i=0; i<qnt; i++)
            {
				cont++;
                cadastro(&raiz, cont);
                system("cls");

            }
			printf("Cadastros Efetuados\n");
			system("pause");
			system("cls");
            break;

        case 2:
        	
        	alterar(&raiz);
        	system("cls");
        	break;

        case 3:

            busca(raiz);
            system("cls");
            break;

        case 4:

            listar(raiz);
            system("cls");
            break;

		case 5:
			deletar(&raiz);
			system("cls");
			break;
			
        case 0:
            exit(1);

        default:
            printf("Número Inválido\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(menu!=0);



}

void cadastro(pets (**raiz), int cont)
{
    pets *novo=(pets*)malloc(sizeof(pets));
    if(novo==NULL)
        return;

    pets *aux;

    novo->prox=NULL;

    printf("Dígite o nome do animal: \n");
    fflush(stdin);
    scanf("%s", novo->nome);

    printf("Dígite a especíe do animal: \n");
    fflush(stdin);
    scanf("%s", novo->especie);

    printf("Dígite a raça do animal: \n");
    fflush(stdin);
    scanf("%s", novo->raca);

    printf("Dígite o sexo do animal: \n");
    fflush(stdin);
    scanf("%c", &novo->sexo);

    printf("Dígite a idade do animal: \n");
    scanf("%d", &novo->idade);

    printf("Informe caracteristicas do animal: \n");
    fflush(stdin);
    scanf("%[^\n]", novo->carac); 
	
	novo->id=cont;
	
	time(&novo->cad);
	novo->cad = time(NULL);

    aux=(*raiz);

    if(aux == NULL)
    {
        (*raiz)= novo;
        return;

    }

    while(aux->prox != NULL)
    {
        aux=aux->prox;
        
    }

    aux->prox=novo;

}

void busca(pets *raiz)
{
    system("cls");

    if(raiz==NULL)
	{
    	printf("Não foram feitos cadastros\n");
    	system("pause");
    	
    	return;
	}
    int opcao;
    int flag = 0;
    pets *novo=(pets*)malloc(sizeof(pets));
    pets *aux;

	aux = raiz;

    do
	{
        printf("1. Busca por nome.\n");
        printf("2. Busca por especie.\n");
        printf("3. Busca por especie e raça.\n");
        printf("4. Busca por especie, raça e sexo.\n");
        printf("0. Sair do menu\n");
        printf("->: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            printf("Dígite o nome do animal: \n");
            fflush(stdin);
            scanf("%s", novo->nome);

            while(raiz != NULL)
            {
                if(strcmp(raiz->nome,novo->nome) == 0 )
                {
                	printf("---------ID %d---------\n", raiz->id);
                    printf("Nome: %s\n", raiz->nome);
                    printf("Espécie: %s\n", raiz->especie);
                    printf("Raça: %s\n", raiz->raca);                  
                    printf("Sexo: %c\n", raiz->sexo);
                    printf("Idade: %d\n", raiz->idade);
                    printf("Características: %s\n", raiz->carac);
                    printf("O cadastro foi feito em %s\n", ctime(&raiz->cad));
                    if(ctime(&raiz->alt)==NULL)
                    {
                    	printf("Não houve alteração\n");
					}else{
						printf("A sua ultima alteração foi feita em %s\n", ctime(&raiz->alt));	
					}
                    printf("______________________________________\n");
                    
              	}
              raiz=raiz->prox;  
            }
            if(flag == 0)
            {
            	printf("\nCadastro não encontrado\n");
			}
            raiz = aux;
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            printf("Dígite a espécie do animal: \n");
            fflush(stdin);
            scanf("%s", novo->especie);
            
            while(raiz != NULL)
            {
                if(strcmp(raiz->especie,novo->especie) == 0 )
                {
					printf("---------iD %d---------\n", raiz->id);
                    printf("Nome: %s\n", raiz->nome);
                    printf("Espécie: %s\n", raiz->especie);
                    printf("Raça: %s\n", raiz->raca);                  
                    printf("Sexo: %c\n", raiz->sexo);
                    printf("Idade: %d\n", raiz->idade);
                    printf("Características: %s", raiz->carac);
                    printf("O cadastro foi feito em %s\n", ctime(&raiz->cad));
                    if(ctime(&raiz->alt)==NULL)
                    {
                    	printf("Não houve alteração\n");
					}else{
						printf("A sua ultima alteração foi feita em %s\n", ctime(&raiz->alt));	
					}
                    printf("______________________________________\n");
					flag = 1;                 
                }
                raiz=raiz->prox;
            }
            if(flag == 0)
            {
            	printf("Cadastro não encontrado\n");
			}
            raiz = aux;
            system("pause");
            system("cls");
            break;


        case 3:
            system("cls");
            printf("Dígite a espécie do animal: \n");
            fflush(stdin);
            scanf("%s", novo->especie);
            printf("Dígite a raça do animal: \n");
            fflush(stdin);
            scanf("%s", novo->raca);

            while(raiz!=NULL)
            {
                if(strcmp(raiz->especie,novo->especie) == 0)
                {
                    if(strcmp(raiz->raca,novo->raca)==0)
                    {
						printf("---------iD %d---------\n", raiz->id);
                    	printf("Nome: %s\n", raiz->nome);
                    	printf("Espécie: %s\n", raiz->especie);
                    	printf("Raça: %s\n", raiz->raca);                  
                		printf("Sexo: %c\n", raiz->sexo);
                		printf("Idade: %d\n", raiz->idade);
                    	printf("Características: %s\n", raiz->carac);
                    	printf("O cadastro foi feito em %s\n", ctime(&raiz->cad));
                    	if(ctime(&raiz->alt)==NULL)
                    		{
                    			printf("Não houve alteração\n");
							}else{
								printf("A sua ultima alteração foi feita em %s\n", ctime(&raiz->alt));	
							}
                    	printf("______________________________________\n");                     
                    }					
					raiz=raiz->prox;
                }
            }
            if(flag == 0)
            {
            	printf("\nCadastro não encontrado\n");
			}
            raiz = aux;
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            printf("Dígite a espécie do animal: \n");
            fflush(stdin);
            scanf("%s", novo->especie);
            printf("Dígite a raça do animal: \n");
            fflush(stdin);
            scanf("%s", novo->raca);
            printf("Dígite o sexo do animal: \n");
            fflush(stdin);
            scanf("%c", &novo->sexo);

            while(raiz!=NULL)
            {
                if(strcmp(raiz->especie,novo->especie) == 0)
                {
                    if(strcmp(raiz->raca,novo->raca)==0)
                    {
                        if(raiz->sexo == novo->sexo)
                        {
							printf("---------iD %d---------\n", raiz->id);
                    		printf("Nome: %s\n", raiz->nome);
                   			printf("Espécie: %s\n", raiz->especie);
                    		printf("Raça: %s\n", raiz->raca);                  
                   			printf("Sexo: %c\n", raiz->sexo);
                   			printf("Idade: %d\n", raiz->idade);
                    		printf("Características: %s", raiz->carac);
                    		printf("O cadastro foi feito em %s\n", ctime(&raiz->cad));
                    		if(ctime(&raiz->alt)==NULL)
                    			{
                    				printf("Não houve alteração\n");
								}else{
									printf("A sua ultima alteração foi feita em %s\n", ctime(&raiz->alt));	
								}
                    		printf("______________________________________\n");                          	
                        }
						raiz=raiz->prox;
                    }

                }
            }
            if(flag == 0)
            {
            	printf("Cadastro não encontrado\n");
			}
            raiz = aux;
            system("pause");
            system("cls");
            break;

        }
    }
    while(opcao!=0);

}

void listar(pets *raiz)
{
    int cont=0;
    int cont2=0;
    int menu;
    
    if(raiz==NULL)
    {
    	printf("Não foram feitos cadastros\n");
    	system("pause");
    	return;
	}

    pets *novo=(pets*)malloc(sizeof(pets*));
    if(novo==NULL) return;

    printf("1. Listagem e contagem de cadastros\n");
    printf("2. Contagem por espécie\n");
    printf("0. Sair\n");
    printf("->: ");
    scanf("%d", &menu);
    
    system("cls");

    do{
    switch(menu)
    {
    case 1:
        while(raiz != NULL)
        {
            printf("---------iD %d---------\n", raiz->id);
            printf("Nome: %s\n", raiz->nome);
            printf("Espécie: %s\n", raiz->especie);
            printf("Raça: %s\n", raiz->raca);                  
            printf("Sexo: %c\n", raiz->sexo);
            printf("Idade: %d\n", raiz->idade);
            printf("Características: %s\n", raiz->carac);
            printf("O cadastro foi feito em %s\n", ctime(&raiz->cad));
            if(ctime(&raiz->alt)==NULL)
                {
                    printf("Não houve alteração\n");
				}else{
					printf("A sua ultima alteração foi feita em %s\n", ctime(&raiz->alt));	
				}
            printf("______________________________________\n");
            raiz=raiz->prox;
            cont++;
        }
        printf("O total de animais cadastrados é: %d.\n", cont);
        system("pause");
        return;

    case 2:
        printf("Dígite a espécie do animal: \n");
        fflush(stdin);
        scanf("%s", novo->especie);
        while(raiz != NULL)
        {
            if(strcmp(raiz->especie,novo->especie)==0)
            {
                cont2++; 
            }
            raiz=raiz->prox;
        }
        if(cont2==0)
        {
        printf("Esta espécie não está cadastrada\n");
        system("pause");
        system("cls");
		break;
        }else{
        printf("O total de %s cadastrados é: %d.\n", novo->especie,cont2);
        system("pause");
        return;
		}
        
    }
    }
    while(menu!=0);

}

void alterar (pets (**raiz))
{
	if((*raiz)==NULL)
	{
		printf("Não foram feitos cadastros\n");
    	system("pause");
    	
    	return;
	}
	
	int idt;
	pets *aux;
	
	aux=(*raiz);
	
	printf("Escolha o id do cadastro para alteração: \n");
	printf("->: ");
	scanf("%d", &idt);
	
	system("cls");
	
	while(aux!=NULL)
	{
		if(aux->id==idt)
		{
   			printf("Dígite o nome do animal: \n");
    		fflush(stdin);
	    	scanf("%s", aux->nome);

    		printf("Dígite a especíe do animal: \n");
    		fflush(stdin);
    		scanf("%s", aux->especie);

    		printf("Dígite a raça do animal: \n");
    		fflush(stdin);
    		scanf("%s", aux->raca);

    		printf("Dígite o sexo do animal: \n");
    		fflush(stdin);
    		scanf("%c", &aux->sexo);

    		printf("Dígite a idade do animal: \n");
    		scanf("%d", &aux->idade);

    		printf("Informe caracteristicas do animal: \n");
    		fflush(stdin);
    		scanf("%[^\n]", aux->carac); 
				
        	aux->id = idt;
			aux->alt = time(NULL);     	
        
			system("pause");
			return;	
		}else{
			aux=aux->prox;
		}
	}
}

void deletar(pets (**raiz))
{
	if((*raiz)==NULL)
	{
		printf("Não foram feitos cadastros\n");
    	system("pause");
    	
    	return;
	}
	
	int idt;
	pets *aux;

	aux=(*raiz);	
	
	printf("Escolha o id do cadastro para remover: \n");
	printf("->: ");
	scanf("%d", &idt);
	
	if(idt==(*raiz)->id)
	{
		(*raiz)=(*raiz)->prox;
		free(aux);
		printf("O cadastro foi removido\n");
		system("pause");
		return;
	}
		
	while(aux!=NULL)
	{
		if((aux->prox->id==idt)&&(aux->prox->id!=(*raiz)->id))
		{
			if(aux->prox->prox==NULL)
			{	
				free(aux->prox->prox);
				aux->prox=NULL;
				printf("O cadastro foi removido\n");
				system("pause");
				return;
			}else{
				free(aux->prox);
				aux->prox=aux->prox->prox;
				printf("O cadastro foi removido\n");
				system("pause");
				return;	
			}
		}else{
			aux=aux->prox;
		}
	}
}


	



