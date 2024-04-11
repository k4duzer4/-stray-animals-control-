#include <stdio.h>   //bibliotecas "basicas"
#include <stdlib.h>  //bibliotecas "basicas"
#include <locale.h>  //usar caracteres especiais
#include <string.h>  //manipulação de strings
#include <stdbool.h> //logica bool true e false para a adoção

#define MAX_ANIMAIS 100

struct Animal {
    char nome[50];
    char especie[50];
    int idade;
    char sexo;
    char cor[20];
    char endereco[100];
    char doencas[100];
    bool adotado;
    char tutor[50];
};

struct Projeto {
    struct Animal* animais;
    int numAnimais;
};

void adotar(struct Projeto* projeto);
void cadastrarAnimal(struct Projeto* projeto);
void imprimirAnimais(struct Projeto* projeto);
void mostrarAnimaisAdotados(struct Projeto* projeto);
void imprimirCabecalho();
void carregarDados(struct Projeto* projeto);
void salvarAnimais(struct Projeto* projeto);
void aguardar();

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    struct Projeto projeto;
    projeto.animais = NULL;
    projeto.numAnimais = 0;
    int opcao = 0;
    carregarDados(&projeto);

    while (opcao != 5) {
        imprimirCabecalho();
        printf("(1) Mostrar animais cadastrados\n");
        printf("(2) Cadastrar animais\n");
        printf("(3) Adotar animais\n");
        printf("(4) Mostrar animais adotados\n");
        printf("(5) Sair\n");
        printf("---------------------------\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                imprimirAnimais(&projeto);
                break;
            case 2:
                cadastrarAnimal(&projeto);
                break;
          
            case 3:
                adotar(&projeto);
                break;
            case 4:
                mostrarAnimaisAdotados(&projeto);
                break;
            case 5:
                printf("\nObrigado pela visita!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    free(projeto.animais);

    return 0;
}

void aguardar() {
    printf("Pressione qualquer tecla para continuar");
    getchar();
}

void imprimirCabecalho() {
    system("clear");
    printf("\n---------------------------\n");
    printf("CONTROLE DE ANIMAIS DE RUA \n");
    printf("---------------------------\n\n");
}

void cadastrarAnimal(struct Projeto* projeto) {
    imprimirCabecalho();

    int x = 1;

    while (x != 0) {
        projeto->animais = (struct Animal*)realloc(projeto->animais, sizeof(struct Animal) * (projeto->numAnimais + 1));
        if (projeto->animais == NULL) {
            printf("Erro ao redimensionar o array de animais.\n");
            return;
        }

        int i = projeto->numAnimais;

        printf("Digite o nome do animal: ");
        fgets(projeto->animais[i].nome, sizeof(projeto->animais[i].nome), stdin);
        projeto->animais[i].nome[strcspn(projeto->animais[i].nome, "\n")] = '\0';

        printf("Digite a espécie do animal: ");
        fgets(projeto->animais[i].especie, sizeof(projeto->animais[i].especie), stdin);
        projeto->animais[i].especie[strcspn(projeto->animais[i].especie, "\n")] = '\0';

        printf("Digite a idade do animal: ");
        scanf("%d", &projeto->animais[i].idade);
        getchar();

        printf("Digite o sexo do animal (M/F): ");
        scanf("%c", &projeto->animais[i].sexo);
        getchar();

        printf("Digite a cor do animal: ");
        fgets(projeto->animais[i].cor, sizeof(projeto->animais[i].cor), stdin);
        projeto->animais[i].cor[strcspn(projeto->animais[i].cor, "\n")] = '\0';

        printf("Digite o endereço do animal: ");
        fgets(projeto->animais[i].endereco, sizeof(projeto->animais[i].endereco), stdin);
        projeto->animais[i].endereco[strcspn(projeto->animais[i].endereco, "\n")] = '\0';

        printf("Digite as doenças do animal: ");
        fgets(projeto->animais[i].doencas, sizeof(projeto->animais[i].doencas), stdin);
        projeto->animais[i].doencas[strcspn(projeto->animais[i].doencas, "\n")] = '\0';

        projeto->animais[i].adotado = false;

        printf("\nAnimal cadastrado com sucesso!\n");

        printf("\nDeseja cadastrar outro animal? (1-Sim / 0-Não): ");
        scanf("%d", &x);
        getchar();

        projeto->numAnimais++;
    }

    salvarAnimais(projeto);

    aguardar();
}

void imprimirAnimais(struct Projeto* projeto) {
    imprimirCabecalho();

    printf("ANIMAIS CADASTRADOS\n");
    printf("---------------------------\n");

    if (projeto->numAnimais == 0) {
        printf("Nenhum animal cadastrado.\n");
        aguardar();
        return;
    }

    for (int i = 0; i < projeto->numAnimais; i++) {
        printf("Animal %d\n", i + 1);
        printf("Nome: %s\n", projeto->animais[i].nome);
        printf("Espécie: %s\n", projeto->animais[i].especie);
        printf("Idade: %d\n", projeto->animais[i].idade);
        printf("Sexo: %c\n", projeto->animais[i].sexo);
        printf("Cor: %s\n", projeto->animais[i].cor);
        printf("Endereço: %s\n", projeto->animais[i].endereco);
        printf("Doenças: %s\n", projeto->animais[i].doencas);

        if (projeto->animais[i].adotado) {
            printf("Situação: Adotado\n");
            printf("Tutor: %s\n", projeto->animais[i].tutor);
        } else {
            printf("Situação: Disponível para adoção\n");
        }

        printf("---------------------------\n");
    }

    aguardar();
}

void adotar(struct Projeto* projeto) {
    imprimirCabecalho();

    if (projeto->numAnimais == 0) {
        printf("Não há animais cadastrados.\n");
        aguardar();
        return;
    }

    printf("ANIMAIS DISPONÍVEIS PARA ADOÇÃO:\n\n");
    int count = 0;
    int indices[MAX_ANIMAIS];

    for (int i = 0; i < projeto->numAnimais; i++) {
        if (!projeto->animais[i].adotado) {
            indices[count] = i;
            count++;
            printf("(%d) Nome: %s\n", count, projeto->animais[i].nome);
            printf("    Espécie: %s\n", projeto->animais[i].especie);
            printf("    Idade: %d\n", projeto->animais[i].idade);
            printf("    Sexo: %c\n", projeto->animais[i].sexo);
            printf("    Cor: %s\n", projeto->animais[i].cor);
            printf("    Endereço: %s\n", projeto->animais[i].endereco);
            printf("    Doenças: %s\n", projeto->animais[i].doencas);
            printf("---------------------------\n");
        }
    }

    if (count == 0) {
        printf("Todos os animais já foram adotados.\n");
        aguardar();
        return;
    }

    int opcao;

    printf("Digite o número correspondente ao animal que deseja adotar (0 para cancelar): ");
    scanf("%d", &opcao);
    getchar();

    if (opcao >= 1 && opcao <= count) {
        int index = indices[opcao - 1];
        projeto->animais[index].adotado = true;

        printf("Digite o nome do tutor: ");
        fgets(projeto->animais[index].tutor, sizeof(projeto->animais[index].tutor), stdin);
        projeto->animais[index].tutor[strcspn(projeto->animais[index].tutor, "\n")] = '\0';

        printf("Animal adotado com sucesso!\n");
        salvarAnimais(projeto);
    } 
    else if (opcao != 0) {
        printf("Opção inválida.\n");
    }

    aguardar();
}

void mostrarAnimaisAdotados(struct Projeto* projeto) {
    imprimirCabecalho();

    if (projeto->numAnimais == 0) {
        printf("Não há animais cadastrados.\n");
    } else {
        printf("ANIMAIS ADOTADOS:\n\n");
        bool animaisAdotados = false;
        for (int i = 0; i < projeto->numAnimais; i++) {
            if (projeto->animais[i].adotado) {
                animaisAdotados = true;
                printf("Nome: %s\n", projeto->animais[i].nome);
                printf("Espécie: %s\n", projeto->animais[i].especie);
                printf("Idade: %d\n", projeto->animais[i].idade);
                printf("Sexo: %c\n", projeto->animais[i].sexo);
                printf("Cor: %s\n", projeto->animais[i].cor);
                printf("Endereço: %s\n", projeto->animais[i].endereco);
                printf("Doenças: %s\n", projeto->animais[i].doencas);
                printf("Tutor: %s\n", projeto->animais[i].tutor);
                printf("---------------------------\n");
            }
        }
        if (!animaisAdotados) {
            printf("Não há animais adotados.\n");
        }
    }

    aguardar();
}

void carregarDados(struct Projeto* projeto) {
    FILE* arquivo = fopen("animais.txt", "r");
    if (arquivo == NULL) {
        return;
    }

    while (!feof(arquivo)) {
        projeto->animais = (struct Animal*)realloc(projeto->animais, sizeof(struct Animal) * (projeto->numAnimais + 1));
        if (projeto->animais == NULL) {
            printf("Erro ao redimensionar o array de animais.\n");
            return;
        }

        int i = projeto->numAnimais;

        fgets(projeto->animais[i].nome, sizeof(projeto->animais[i].nome), arquivo);
        projeto->animais[i].nome[strcspn(projeto->animais[i].nome, "\n")] = '\0';

        fgets(projeto->animais[i].especie, sizeof(projeto->animais[i].especie), arquivo);
        projeto->animais[i].especie[strcspn(projeto->animais[i].especie, "\n")] = '\0';

        fscanf(arquivo, "%d\n", &projeto->animais[i].idade);

        fscanf(arquivo, "%c\n", &projeto->animais[i].sexo);

        fgets(projeto->animais[i].cor, sizeof(projeto->animais[i].cor), arquivo);
        projeto->animais[i].cor[strcspn(projeto->animais[i].cor, "\n")] = '\0';

        fgets(projeto->animais[i].endereco, sizeof(projeto->animais[i].endereco), arquivo);
        projeto->animais[i].endereco[strcspn(projeto->animais[i].endereco, "\n")] = '\0';

        fgets(projeto->animais[i].doencas, sizeof(projeto->animais[i].doencas), arquivo);
        projeto->animais[i].doencas[strcspn(projeto->animais[i].doencas, "\n")] = '\0';

        fscanf(arquivo, "%d\n", &projeto->animais[i].adotado);

        fgets(projeto->animais[i].tutor, sizeof(projeto->animais[i].tutor), arquivo);
        projeto->animais[i].tutor[strcspn(projeto->animais[i].tutor, "\n")] = '\0';

        projeto->numAnimais++;
    }

    fclose(arquivo);
}

void salvarAnimais(struct Projeto* projeto) {
    FILE* arquivo = fopen("animais.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar os dados.\n");
        return;
    }

    for (int i = 0; i < projeto->numAnimais; i++) {
        fprintf(arquivo, "%s\n", projeto->animais[i].nome);
        fprintf(arquivo, "%s\n", projeto->animais[i].especie);
        fprintf(arquivo, "%d\n", projeto->animais[i].idade);
        fprintf(arquivo, "%c\n", projeto->animais[i].sexo);
        fprintf(arquivo, "%s\n", projeto->animais[i].cor);
        fprintf(arquivo, "%s\n", projeto->animais[i].endereco);
        fprintf(arquivo, "%s\n", projeto->animais[i].doencas);
        fprintf(arquivo, "%d\n", projeto->animais[i].adotado);
        fprintf(arquivo, "%s\n", projeto->animais[i].tutor);
    }

    fclose(arquivo);
}