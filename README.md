# Teoria-dos-Grafos
AB2
Algoritmos de Grafos para a disciplina Teoria dos Grafos.
Curso: Ciência da Computação - UFAL
Linguagem: C

## SOBRE A BATERIA DE TESTE1 (IMPORTANTE)

A variável "VAL", do arquivo Bat1.sh estava recebendo os valores de saída dos algoritmos, entretanto não estava registrando eles como inteiros, o que impossibilitava a comparação com os valores do arquivo gabarito_agm. 
Como não consegui resolver esse problema dentro dos algoritmos, adicionei 2 linhas de código dentro de Bat1.sh para converter os valores recebidos por "VAL" para númericos. Estarei disponibilizando no repositório a pasta da bateria 1, com os binarios de cada algoritmo já adicionados e com o código de Bat1.sh com modificações sinalizadas dentro do código.

Código abaixo adicionado no teste de Kruskal e de Prim:

	if ! [[ $val =~ ^[0-9]+$ ]];
		val=$(printf "%.0f" "$val")
	fi

## Algoritmos implementados

1. Prim

2. Djikstra

3. Floyd Warshall

4. Kruskal

Aluno: Gustavo Ribeiro Franco Gaia

Cada pasta possui o makefile, example.txt, saida.txt, .bin, .c, .exe, .o e README de cada algoritmo gerado. O makefile gera os executáveis, bins, e objetos quando executado.


