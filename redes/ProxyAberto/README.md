# Proxy Aberto

Responsável: Fukuda

Tags: `proxy`

## Desafio

Tem uma maquina com um proxy aberto em uma porta. Ele não tem nem filtro de IP nem precisa de credenciais.

Dentro dessa maquina tem um servidor interno (`http`) com a flag.

## Resolução proposta

Utilizar o proxy para acessar a o servidor interno e ler a flag em `http://localhost:80/flag.txt`.

## Como rodar

Basta construir o docker e rodar ele. O proxy vai estar rodando localmente na porta padrão (3128).

```bash
make start
```
