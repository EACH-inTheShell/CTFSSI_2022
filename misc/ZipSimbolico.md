# Zip simbólico

Responsável: Fukuda

Tags: `zip`

## Desafio

Criar um site que recebe um arquivo zip, descompacta e lê o conteúdo que esta nele. A flag esta em algum lugar dentro do servidor (talvez em `/flag.txt`).

## Resolução proposta

A ideia seria criar um arquivo com um link simbólico para, quando ler o arquivo, ler o conteúdo de `/flag.txt`.
