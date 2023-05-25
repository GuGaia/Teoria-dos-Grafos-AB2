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
            grafo.matriz_adjacencia[i][j] = 0;
        }
    }
}

void add_aresta(int origem, int destino, int peso) {
    grafo.matriz_adjacencia[origem][destino] = peso;
    grafo.matriz_adjacencia[destino][origem] = peso;
}

int vertice_minimo(int* distancia, int* visitado, int num_vertices) {
    int min = INT_MAX;
    int min_indice, v;

    for (v = 1; v <= num_vertices; v++) {
        if (visitado[v] == 0 && distancia[v] < min) {
            min = distancia[v];
            min_indice = v;
        }
    }

    return min_indice;
}

void algoritmo_dijkstra(int vertice_inicial) {
    int distancia[MAX_VERTICES], visitado[MAX_VERTICES];
    int i, count, u, v;

    for (i = 1; i <= grafo.num_vertices; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = 0;
    }

    distancia[vertice_inicial] = 0;

    for (count = 1; count <= grafo.num_vertices - 1; count++) {
        u = vertice_minimo(distancia, visitado, grafo.num_vertices);
        visitado[u] = 1;

        for (v = 1; v <= grafo.num_vertices; v++) {
            if (grafo.matriz_adjacencia[u][v] && visitado[v] == 0 && distancia[u] != INT_MAX &&
                distancia[u] + grafo.matriz_adjacencia[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + grafo.matriz_adjacencia[u][v];
            }
        }
    }

    for (i = 1; i <= grafo.num_vertices; i++) {
        if (distancia[i] != INT_MAX) {
            printf("%d:%d ", i, distancia[i]);
        } 
        else {
            printf("%d:-1 ", i);
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    FILE* file;
    int vertice_inicial = 1;
    int saida_flag = 0;
    char* arquivo_saida;

    if (argc < 2) {
        printf("Formato esperado: %s -f <arquivo> -i <vertice_inicial> -o <arquivo_saida>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printf("Formato esperado: .\\Dijkstra -f <arquivo> -i <vertice_inicial> -o <arquivo_saida>\n");
            printf("Opcoes:\n");
            printf("  -f <arquivo>\tIndica o arquivo de entrada contendo o grafo\n");
            printf("  -i <vertice_inicial>\tIndica o vertice inicial (padrao: 1)\n");
            printf("  -o <arquivo_saida>\tRedireciona a saida para o arquivo\n");
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            file = fopen(argv[i + 1], "r");
            if (file == NULL) {
                printf("Erro ao ler o arquivo.\n");
                return 1;
            }
            i++;
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            vertice_inicial = atoi(argv[i + 1]);
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

    algoritmo_dijkstra(vertice_inicial);

    return 0;
}
