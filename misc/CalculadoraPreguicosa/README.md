# Calculadora Preguiçosa

Responsável: Fukuda

Tags: `injeção`, `python`

## Desafio

Criar um programa que utilize um interpretador python (como um `eval("<user_input>")` no python ou um `popen("python3 -c 'print(<user_input>)'", "r")` no C) para resolver contas matemáticas passadas como entrada.

## Resolução proposta

Para explorar basta injetar comandos python para ler a flag como esse: `exec("import os;os.system(\"cat flag.txt\")")`.

## Como rodar

Suba o servidor com `make start`. Depois é só acessar o desafio pelo NetCat com `nc localhost 47002`
