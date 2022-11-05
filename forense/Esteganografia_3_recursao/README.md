# Esteganografia - Recursao

Responsável: Tsu

Tags: `esteganografia`, `steghide`

## Desafio

Jiji começou a mexer com o `steghide` e acabou perdendo o roberto.

Como podemos encontrar o roberto?

## Resolução proposta

Primeiro precisamos extrair o arquivo `frog.jpeg`

```sh
steghide extract -sf frog.jpeg  -p caio
```

Então vamos encontrar o arquivo `0_roberto.jpeg`, ao extrair novamente:

```sh
steghide extract -sf 0_roberto.jpeg  -p roberto
```

Encontramos a `flag.txt`

## Como rodar

O código fonte vai estar disponibilizado no site do `ctfd/ctfd`.
