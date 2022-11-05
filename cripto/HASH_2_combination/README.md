# Hash com regras?

Responsável: Tsu

Tags: `hash`, `hashcat`

## Desafio

Sabemos que Jiji usou uma combinação de 2 palavras dentro do arquivo `rockyou-10000.txt` para formar sua senha, mas não sabemos quais...

Qual a senha de Jiji?

**OBS**: O hash não é mais o MD5

## Resolução proposta

Usando o programa `hashcat` que foi recomendado, podemos rodar o seguinte comando:

```sh
hashcat -m 1410 -a 1 hash.txt rockyou-10000.txt rockyou-10000.txt
```

Obtendo o seguinte resultado:

![hash quebrado](./FLAG.png)

## Como rodar

O código fonte vai estar disponibilizado no site do `ctfd/ctfd`.
