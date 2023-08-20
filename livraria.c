/*Exercício 2. Faça um programa em Linguagem C para controlar o cadastro e consulta aos livros de uma
livraria online. Cada livro possui: código, título, primeiro autor, editora, ano de publicação e preço.
Monte um menu com as opções:
1. Cadastro de livro;
2. Consulta do livro por código ou título;
3. Consulta de livros com preço inferior ao informado pelo usuário
4. Consultar o número de livros cadastrados de um autor escolhido pelo usuário;
5. Relatório de livros (mostrar todos os livros cadastrados);
6. Sair do programa.
Observação: O programa poderá armazenar até 100 livros.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct{
    int codigo;
    char titulo[MAX];
    char primeiroautor[MAX];
    char editora[MAX];
    int anopublicacao;
    double preco;
} Livraria;

void menu();
Livraria cadastrar();
int consultarCodTitulo(Livraria livros[], int contadorLivros);
void consultarPreco(Livraria livros[], int contadorLivros);
void consultarAutor(Livraria livros[], int contadorLivros);
void relatorioLivros(Livraria livros[], int contadorLivros);
int main(){

    Livraria livros[MAX];
    int opcao, contadorLivros = 0, consultaCodTitulo;

    do{
        menu();
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            livros[contadorLivros++] = cadastrar();
            break;
        case 2:
            consultaCodTitulo = consultarCodTitulo(livros, contadorLivros);
            if(consultaCodTitulo == -1){
                printf("A livraria NÃO possui o livro.\n");
                getchar();
                getchar();
            }
            break;
        case 3:
            consultarPreco(livros, contadorLivros);
            break;
        case 4:
            consultarAutor(livros, contadorLivros);
            break;
        case 5:
            relatorioLivros(livros, contadorLivros);
            break;
        case 6:
            printf("Encerrando o programa...\n");
            printf("Pressione ENTER para continuar...\n");
            getchar();
            getchar();
            break;
        default:
            printf("Opção inválida. Tente novamente...");
            printf("Pressione ENTER para encerrar...\n");
            getchar();
            getchar();
        }
    }while(opcao != 6);
}

void menu(){
    
    system("cls");
    printf("***** Livraria IFSP *****\n");
    printf("***************************\n");
    printf("1 - Cadastro de livro\n");
    printf("2 - Consulta do livro por código ou título\n");
    printf("3 - Consulta de livros com preço inferior ao informado pelo usuário\n");
    printf("4 - Consultar o número de livros cadastrados de um autor escolhido pelo usuário\n");
    printf("5 - Relatório de livros (mostrar todos os livros cadastrados)\n");
    printf("6 - Sair do programa\n");
    printf("***************************\n");
    printf("Escolha uma opção: ");
}

Livraria cadastrar(){
    Livraria livraria;

    livraria.anopublicacao = -1, livraria.codigo = -1, livraria.preco = -1;
    system("cls");
    printf("**** Dados do Livro ****\n");
    do{
        printf("Código: ");
        scanf("%d", &livraria.codigo);
        if(livraria.codigo < 0){
            printf("Código inválido, o código precisa ser um valor positivo. Tente novamente.\n");
        }
    }while(livraria.codigo < 0);
    getchar();
    printf("Título: ");
    gets(livraria.titulo);
    printf("Primeiro autor: ");
    gets(livraria.primeiroautor);
    printf("Editora: ");
    gets(livraria.editora);
    do{
        printf("Ano de publicação: ");
        scanf("%d", &livraria.anopublicacao);
        if(livraria.anopublicacao < 0){
            printf("Ano de publicação inválido, o ano de publicação precisa ser um valor positivo. Tente novamente.\n");
        }
    }while(livraria.anopublicacao < 0);
    do{
        printf("Preço: ");
        scanf("%lf", &livraria.preco);
        if(livraria.preco < 0){
            printf("Preço inválido, o preço precisa ser um valor positivo. Tente novamente.\n");
        }
    }while(livraria.preco < 0);
    printf("******************\n");
    printf("Livro cadastrado com sucesso!\n");
    printf("Pressione ENTER para continuar...\n");
    getchar();
    getchar();
    return livraria;
}

int consultarCodTitulo(Livraria livros[], int contadorLivros){
    int pesquisa, opcao = 1, i = 0;
    char pesquisaNome[MAX];

    system("cls");
    
    do{
        printf("Deseja consultar como?\n[1] Código\n[2] Título\n");
        scanf("%d", &opcao);
        if(opcao < 1 || opcao > 2){
            printf("Opção inválida. Tente novamente.\n");
        }
    }while(opcao < 1 || opcao > 2);

    if(opcao == 1){
        printf("Digite o código do livro: ");
        scanf("%d", &pesquisa);
    } else if(opcao == 2){
        printf("Digite o nome do livro: ");
        gets(pesquisaNome);
        gets(pesquisaNome);
    }

    while(i < contadorLivros){
        if(livros[i].codigo == pesquisa || strcmp(livros[i].titulo, pesquisaNome) == 0){
            printf("A livraria possui o livro.\n");
            printf("Pressione ENTER para continuar...\n");
            getchar();
            getchar();
            return i;
        } else{
            i++;
        }
    }

    return -1;
}

void consultarPreco(Livraria livros[], int contadorLivros){
    int i, qtdelivros = 0;
    double pesquisa;

    system("cls");

    printf("Insira o preço maximo do livro: R$");
    scanf("%lf", &pesquisa);

    for(i = 0; i < contadorLivros; i++){

        if(livros[i].preco < pesquisa){
            printf("%s\n", livros[i].titulo);
            qtdelivros++;
        }
    }

    if(qtdelivros > 0){
        printf("Estes são os livros com o preço abaixo de R$%.2lf\n", pesquisa);
        printf("Pressione ENTER para continuar...\n");
        getchar();
        getchar();
    } else{
        printf("Não foram encontrados livros com o preço abaixo de R$%.2lf\n", pesquisa);
        printf("Pressione ENTER para continuar...\n");
        getchar();
        getchar();
    }
}

void consultarAutor(Livraria livros[], int contadorLivros){

    int i, qtdelivros = 0;
    char pesquisa[MAX];

    system("cls");

    printf("Insira o nome do autor: ");
    gets(pesquisa);
    gets(pesquisa);

    
    for(i = 0; i < contadorLivros; i++){
        if(strcmp(pesquisa, livros[i].primeiroautor) == 0){
            printf("%s\n", livros[i].titulo);
            qtdelivros++;
        }
    }    

    if(qtdelivros == 0){
        printf("O autor %s não possui livros na livraria.\n", pesquisa);
    } else{
        printf("Estes são os livros do autor %s\n", pesquisa);
        printf("O autor %s possui %d livros na livraria.\n", pesquisa, qtdelivros);
    }
    printf("Pressione ENTER para continuar...\n");
    getchar();
    getchar();
}

void relatorioLivros(Livraria livros[], int contadorLivros){

    int i;

    system("cls");

    for(i = 0; i < contadorLivros; i++){
        printf("Livro %d:\n", i + 1);
        printf("Código: %d\n", livros[i].codigo);
        printf("Título: %s\n", livros[i].titulo);
        printf("Preço: R$%.2lf\n", livros[i].preco);
        printf("Autor: %s\n", livros[i].primeiroautor);
        printf("Editora: %s\n", livros[i].editora);
        printf("Ano de publicação: %d\n", livros[i].anopublicacao);
        printf("**********************\n");
    }

    printf("Pressione ENTER para continuar...\n");
    getchar();
    getchar();
}