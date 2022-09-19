# Uma Cabeça Cheia de Informações

Responsável: Fukuda

Tags: `git`, `devops`

## Desafio

Descobrir e baixar um repositório git que esta exposto na internet, depois olhar pelos commits por uma senha.

## Resolução proposta

Identificar o diretório `.git` (`/.git/HEAD`) e depois utilizar alguma ferramenta (que extraia com o histórico de commits) para automatizar o processo de extrair o repositório, como o [git-dumper](https://github.com/arthaud/git-dumper), depois buscar no `git log` por mudanças que possam ser interessantes e olhar elas com `git diff` ou `git checkout`.

## Como rodar

Suba o servidor com `make start`. Depois é só acessar o desafio pelo browser em `http://localhost:47100/`
