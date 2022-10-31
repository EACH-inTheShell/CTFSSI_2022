# XOR - 1 byte xor

Responsável: Tsu

Tags: `xor`, `python3`

## Desafio

Jiji estava brincando com a operação XOR e acabou criptografando uma de suas imagens! Jiji esqueceu qual chave usou para a criptografia... :(

## Resolução proposta

A primeira parte seria adaptar o programa da operação xor para funcionar em arquivos binários.

Então, poderia fazer um brute force testando todos os valores de 0 até 255.

Para não ter que usar a operação xor em todo arquivo, o participante poderia fazer a operação xor apenas no começo do arquivo. Já que foi revelado que o arquivo é um PNG, é possível saber qual é o número mágico do arquivo.


## Como rodar

O código fonte vai estar disponibilizado no site do `ctfd/ctfd`.
