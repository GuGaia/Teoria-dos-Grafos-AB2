#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 300

typedef struct {
    int vertice;
    int peso;
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
            grafo.matriz_adjacencia[i][j] = INT_MAX;
        }
    }
}

void add_aresta(int origem, int destino, int peso) {
    grafo.matriz_adjacencia[origem][destino] = peso;
    grafo.matriz_adjacencia[destino][origem] = peso;
}

void algoritmo_floyd_warshall() {
    int distancia[MAX_VERTICES][MAX_VERTICES];
    int i, j, k;

    for (i = 1; i <= grafo.num_vertices; i++) {
        for (j = 1; j <= grafo.num_vertices; j++) {
            distancia[i][j] = grafo.matriz_adjacencia[i][j];
        }
    }

    for (k = 1; k <= grafo.num_vertices; k++) {
        for (i = 1; i <= grafo.num_vertices; i++) {
            for (j = 1; j <= grafo.num_vertices; j++) {
                if (distancia[i][k] != INT_MAX && distancia[k][j] != INT_MAX &&
                    distancia[i][k] + distancia[k][j] < distancia[i][j]) {
                    distancia[i][j] = distancia[i][k] + distancia[k][j];
                }
            }
        }
    }

    for (i = 1; i <= grafo.num_vertices; i++) {
        for (j = 1; j <= grafo.num_vertices; j++) {
            if (distancia[i][j] != INT_MAX) {
                printf("%d:%d ", j, distancia[i][j]);
            } else {
                printf("%d:-1 ", j);
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    FILE* file;
    int saida_flag = 0;
    char* arquivo_saida;

    if (argc < 2) {
        printf("Formato esperado: %s -f <arquivo> -o <arquivo_saida>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printf("Formato esperado: .\\FloydWarshall -f <arquivo> -o <arquivo_saida>\n");
            printf("Opcoes:\n");
            printf("  -f <arquivo>\tIndica o arquivo de entrada contendo o grafo\n");
            printf("  -o <arquivo_saida>\tRedireciona a saida para o arquivo\n");
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            file = fopen(argv[i + 1], "r");
            if (file == NULL) {
                printf("Erro ao ler o arquivo.\n");
                return 1;
            }
            i++;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            saida_flag = 1;
            arquivo_saida = argv[i + 1];
            i++;
        }
    }

    int num_vertices, num_arestas, origem, destino, peso;
    fscanf(file, "%d %d", &num_vertices, &num_arestas);
    preencher_grafo(num_vertices);

    while (num_arestas > 0 && fscanf(file, "%d %d %d", &origem, &destino, &peso) != EOF) {
        add_aresta(origem, destino, peso);
        num_arestas--;
    }

    fclose(file);

    if (saida_flag) {
        freopen(arquivo_saida, "w", stdout);
    }

    algoritmo_floyd_warshall();

    return 0;
}
