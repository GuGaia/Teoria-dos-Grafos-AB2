# Floydwarshall Algorithm

Este é um projeto que implementa o algoritmo de floydwarshall para encontrar a árvore geradora mínima em um grafo não direcionado e ponderado.

## Compilação

Certifique-se de ter o compilador GCC instalado em seu sistema. Em seguida, navegue até o diretório do algoritmo execute o seguinte comando para compilar o projeto:

make

Isso irá compilar o código-fonte e gerar o executável floydwarshall.

## Execução

Para executar o algoritmo de floydwarshall, use o seguinte comando:

.\floydwarshall

Seguida da opção escolhida a partir do menu abaixo

## Opções

	- `-f <arquivo>`: Especifica o arquivo de entrada contendo o grafo.
	- `-o <arquivo_saida>`: Redireciona a saída para o arquivo especificado.

Exemplo de uso:

.\floydwarshall -f input.txt -o output.txt

## Parametros

Para entradas com mais de 300 vertices acesse a pasta scr, abra o arquivo "floydwarshall.c" e altere o valor da variável MAX_VERTICES.
