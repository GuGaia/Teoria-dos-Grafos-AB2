# Prim Algorithm

Este é um projeto que implementa o algoritmo de prim para encontrar a árvore geradora mínima em um grafo não direcionado e ponderado.

## Compilação

Certifique-se de ter o compilador GCC instalado em seu sistema. Em seguida, navegue até o diretório do algoritmo execute o seguinte comando para compilar o projeto:

make

Isso irá compilar o código-fonte e gerar o executável prim.

## Execução

Para executar o algoritmo de prim, use o seguinte comando:

.\prim

Seguida da opção escolhida a partir do menu abaixo

## Opções

	- `-f <arquivo>`: Especifica o arquivo de entrada contendo o grafo.
	- `-i <vertice_inicial>\tIndica o vertice inicial (padrao: 1).
	- `-s`: Mostra a solução em ordem crescente.
	- `-o <arquivo_saida>`: Redireciona a saída para o arquivo especificado.

Exemplo de uso:

.\prim -f input.txt -s -o output.txt

## Parametros

Para entradas com mais de 300 vertices acesse a pasta scr, abra o arquivo "Prim.c" e altere o valor da variável MAX_VERTICES.
