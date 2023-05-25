#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 300

typedef struct {
    int vertice_origem;
    int vertice_destino;
    int peso;
    int indice;
} Aresta;

typedef struct {
    int num_vertices;
    int num_arestas;
    int matriz_adjacencia[MAX_VERTICES][MAX_VERTICES];
} Grafo;

Grafo grafo;

void preencher_grafo(int num_vertices) {
    int i, j;
    grafo.num_vertices = num_vertices;

    for (i = 1; i <= num_vertices; i++) {
        for (j = 1; j <= num_vertices; j++) {
            grafo.matriz_adjacencia[i][j] = 0;
        }
    }
}

void add_aresta(int origem, int destino, int peso) {
    grafo.matriz_adjacencia[origem][destino] = peso;
    grafo.matriz_adjacencia[destino][origem] = peso;
}

int comparar_arestas(const void* a, const void* b) {
    Aresta* aresta1 = (Aresta*)a;
    Aresta* aresta2 = (Aresta*)b;

    return aresta1->peso - aresta2->peso;
}

void algoritmo_kruskal(int solucao_flag) {
    Aresta arestas[MAX_VERTICES * MAX_VERTICES];
    int arvore[MAX_VERTICES];
    int num_arestas_arvore = 0;
    int custo_total = 0;
    int i, j, u, v;

    for (i = 1; i <= grafo.num_vertices; i++) {
        arvore[i] = i;
    }

    for (i = 1; i <= grafo.num_vertices; i++) {
        for (j = i + 1; j <= grafo.num_vertices; j++) {
            if (grafo.matriz_adjacencia[i][j] != 0) {
                Aresta aresta;
                aresta.vertice_origem = i;
                aresta.vertice_destino = j;
                aresta.peso = grafo.matriz_adjacencia[i][j];
                aresta.indice = num_arestas_arvore++;
                arestas[aresta.indice] = aresta;
            }
        }
    }

    qsort(arestas, num_arestas_arvore, sizeof(Aresta), comparar_arestas);

    for (i = 0; i < num_arestas_arvore; i++) {
        u = arestas[i].vertice_origem;
        v = arestas[i].vertice_destino;

        while (arvore[u] != u) {
            u = arvore[u];
        }
        while (arvore[v] != v) {
            v = arvore[v];
        }

        if (u != v) {
            arvore[v] = u;
            custo_total += arestas[i].peso;
            if (solucao_flag) {
                printf("(%d,%d) ", arestas[i].vertice_origem, arestas[i].vertice_destino);
            }
        }
    }

    if (solucao_flag) {
        printf("\n");
    } else {
        printf("%d", custo_total);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    FILE* file;
    int saida_flag = 0;
    int solucao_flag =0;
    char* arquivo_saida;

    if (argc < 2) {
        printf("Formato esperado: %s -f <arquivo> -i <vertice_inicial> -s -o <arquivo_saida>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printf("Formato esperado: .\\kruskal -f <arquivo> -i <vertice_inicial> -s -o <arquivo_saida>\n");
            printf("Opcoes:\n");
            printf("  -f <arquivo>\tIndica o arquivo de entrada contendo o grafo\n");
            printf("  -s Mostra a solucao em ordem crescente\n");
            printf("  -o <arquivo_saida>\tRedireciona a saida para o arquivo\n");
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            file = fopen(argv[i + 1], "r");
            if (file == NULL) {
                printf("Erro ao ler o arquivo.\n");
                return 1;
            }
            i++;
        } else if (strcmp(argv[i], "-s") == 0) {
            solucao_flag = 1;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            saida_flag = 1;
            arquivo_saida = argv[i + 1];
            i++;
        }
    }

    int num_vertices, num_arestas, origem, destino, peso;
    fscanf(file, "%d%d", &num_vertices, &num_arestas);
    preencher_grafo(num_vertices);

    while (num_arestas > 0 && fscanf(file, "%d%d%d", &origem, &destino, &peso) != EOF) {
        add_aresta(origem, destino, peso);
        num_arestas--;
    }

    fclose(file);

    if (saida_flag) {
        freopen(arquivo_saida, "w", stdout);
    }

     algoritmo_kruskal(solucao_flag);

    return 0;
}
