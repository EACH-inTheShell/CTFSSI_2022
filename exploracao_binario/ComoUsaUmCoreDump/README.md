# Como Usa um Core Dump?

Responsável: Fukuda

Tags: `core_dump`, `gdb`

## Desafio

Disponibilizar um binário e um core dump para análise de memória.

## Resolução proposta

Rodar o *gdb* com o core dump e verificar a stack por uma variável com a flag.

## Como rodar

Rode `make` para gerar o executável `programa` e o arquivo `core.pid`. Eles serão disponibilizados para download.

Atenção: O arquivo `/proc/sys/kernel/core_pattern` tem que estar com esse conteúdo para gerar o `core.pid`:

```
core.%p
```
