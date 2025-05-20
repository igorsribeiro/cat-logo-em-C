#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    char titulo[100];
    char diretor[100];
    int ano;
    char genero[50];
} Filme;

Filme catalogo[MAX] = {
    {"Branca de Neve e os Sete Anões", "David Hand", 1937, "Animação"},
    {"Os Vingadores", "Joss Whedon", 2012, "Ação"},
    {"Onde Estou Aqui", "Walter Salles", 2023, "Drama"},
    {"O Jogo da Imitação", "Morten Tyldum", 2014, "Biografia"}
};
int total = 4;

void adicionarFilme() {
    if (total < MAX) {
        printf("\n--- Adicionar Filme ---\n");
        printf("Título: ");
        scanf(" %[^\n]", catalogo[total].titulo);
        
        printf("Diretor: ");
        scanf(" %[^\n]", catalogo[total].diretor);
        
        printf("Ano: ");
        scanf("%d", &catalogo[total].ano);
        
        printf("Gênero: ");
        scanf(" %[^\n]", catalogo[total].genero);
        
        total++;
        printf("\nFilme adicionado com sucesso!\n");
    } else {
        printf("\nCatálogo cheio! Não é possível adicionar mais filmes.\n");
    }
}

void listarFilmes() {
    if (total == 0) {
        printf("\nNenhum filme cadastrado no catálogo.\n");
    } else {
        printf("\n--- Catálogo de Filmes (%d/%d) ---\n", total, MAX);
        for (int i = 0; i < total; i++) {
            printf("\nFilme #%d\n", i+1);
            printf("Título: %s\n", catalogo[i].titulo);
            printf("Diretor: %s\n", catalogo[i].diretor);
            printf("Ano: %d\n", catalogo[i].ano);
            printf("Gênero: %s\n", catalogo[i].genero);
        }
    }
}

void removerFilme() {
    if (total == 0) {
        printf("\nNenhum filme para remover.\n");
        return;
    }
    
    listarFilmes();
    int num;
    printf("\nDigite o número do filme a remover (1-%d): ", total);
    scanf("%d", &num);
    
    if (num < 1 || num > total) {
        printf("\nNúmero inválido!\n");
        return;
    }
    
    num--;
    for (int i = num; i < total-1; i++) {
        catalogo[i] = catalogo[i+1];
    }
    total--;
    printf("\nFilme removido com sucesso!\n");
}

// Funções de ordenação
void ordenarPorTitulo() {
    for (int i = 0; i < total-1; i++) {
        for (int j = i+1; j < total; j++) {
            if (strcmp(catalogo[i].titulo, catalogo[j].titulo) > 0) {
                Filme temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
    }
    printf("\nCatálogo ordenado por título!\n");
}

void ordenarPorDiretor() {
    for (int i = 0; i < total-1; i++) {
        for (int j = i+1; j < total; j++) {
            if (strcmp(catalogo[i].diretor, catalogo[j].diretor) > 0) {
                Filme temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
    }
    printf("\nCatálogo ordenado por diretor!\n");
}

void ordenarPorAno() {
    for (int i = 0; i < total-1; i++) {
        for (int j = i+1; j < total; j++) {
            if (catalogo[i].ano > catalogo[j].ano) {
                Filme temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
    }
    printf("\nCatálogo ordenado por ano!\n");
}

void ordenarPorGenero() {
    for (int i = 0; i < total-1; i++) {
        for (int j = i+1; j < total; j++) {
            if (strcmp(catalogo[i].genero, catalogo[j].genero) > 0) {
                Filme temp = catalogo[i];
                catalogo[i] = catalogo[j];
                catalogo[j] = temp;
            }
        }
    }
    printf("\nCatálogo ordenado por gênero!\n");
}

// Funções de busca
void buscarPorTitulo() {
    char termo[100];
    printf("\nDigite o título ou parte dele: ");
    scanf(" %[^\n]", termo);
    
    printf("\nResultados da busca por '%s':\n", termo);
    int encontrados = 0;
    
    for (int i = 0; i < total; i++) {
        if (strstr(catalogo[i].titulo, termo) != NULL) {
            printf("\nFilme #%d\n", i+1);
            printf("Título: %s\n", catalogo[i].titulo);
            printf("Diretor: %s\n", catalogo[i].diretor);
            printf("Ano: %d\n", catalogo[i].ano);
            printf("Gênero: %s\n", catalogo[i].genero);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("\nNenhum filme encontrado com esse termo.\n");
    }
}

void buscarPorDiretor() {
    char termo[100];
    printf("\nDigite o nome do diretor ou parte dele: ");
    scanf(" %[^\n]", termo);
    
    printf("\nResultados da busca por '%s':\n", termo);
    int encontrados = 0;
    
    for (int i = 0; i < total; i++) {
        if (strstr(catalogo[i].diretor, termo) != NULL) {
            printf("\nFilme #%d\n", i+1);
            printf("Título: %s\n", catalogo[i].titulo);
            printf("Diretor: %s\n", catalogo[i].diretor);
            printf("Ano: %d\n", catalogo[i].ano);
            printf("Gênero: %s\n", catalogo[i].genero);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("\nNenhum filme encontrado com esse diretor.\n");
    }
}

void buscarPorAno() {
    int ano;
    printf("\nDigite o ano de lançamento: ");
    scanf("%d", &ano);
    
    printf("\nResultados da busca por ano %d:\n", ano);
    int encontrados = 0;
    
    for (int i = 0; i < total; i++) {
        if (catalogo[i].ano == ano) {
            printf("\nFilme #%d\n", i+1);
            printf("Título: %s\n", catalogo[i].titulo);
            printf("Diretor: %s\n", catalogo[i].diretor);
            printf("Ano: %d\n", catalogo[i].ano);
            printf("Gênero: %s\n", catalogo[i].genero);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("\nNenhum filme encontrado lançado neste ano.\n");
    }
}

void buscarPorGenero() {
    char termo[50];
    printf("\nDigite o gênero ou parte dele: ");
    scanf(" %[^\n]", termo);
    
    printf("\nResultados da busca por '%s':\n", termo);
    int encontrados = 0;
    
    for (int i = 0; i < total; i++) {
        if (strstr(catalogo[i].genero, termo) != NULL) {
            printf("\nFilme #%d\n", i+1);
            printf("Título: %s\n", catalogo[i].titulo);
            printf("Diretor: %s\n", catalogo[i].diretor);
            printf("Ano: %d\n", catalogo[i].ano);
            printf("Gênero: %s\n", catalogo[i].genero);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("\nNenhum filme encontrado deste gênero.\n");
    }
}

void menuOrdenacao() {
    int opcao;
    do {
        printf("\n--- Ordenar Catálogo ---\n");
        printf("1. Por Título\n");
        printf("2. Por Diretor\n");
        printf("3. Por Ano\n");
        printf("4. Por Gênero\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: ordenarPorTitulo(); break;
            case 2: ordenarPorDiretor(); break;
            case 3: ordenarPorAno(); break;
            case 4: ordenarPorGenero(); break;
            case 0: break;
            default: printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);
}

void menuBusca() {
    int opcao;
    do {
        printf("\n--- Buscar no Catálogo ---\n");
        printf("1. Por Título\n");
        printf("2. Por Diretor\n");
        printf("3. Por Ano\n");
        printf("4. Por Gênero\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: buscarPorTitulo(); break;
            case 2: buscarPorDiretor(); break;
            case 3: buscarPorAno(); break;
            case 4: buscarPorGenero(); break;
            case 0: break;
            default: printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu do Catálogo de Filmes ---\n");
        printf("1. Adicionar Filme\n");
        printf("2. Listar Todos os Filmes\n");
        printf("3. Remover Filme\n");
        printf("4. Ordenar Catálogo\n");
        printf("5. Buscar Filmes\n");
        printf("0. Sair do Programa\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: adicionarFilme(); break;
            case 2: listarFilmes(); break;
            case 3: removerFilme(); break;
            case 4: menuOrdenacao(); break;
            case 5: menuBusca(); break;
            case 0: printf("\nEncerrando o catálogo...\n"); break;
            default: printf("\nOpção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

int main() {
    printf("Bem-vindo ao Catálogo de Filmes!\n");
    menu();
    return 0;
}