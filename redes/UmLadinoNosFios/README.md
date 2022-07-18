# Um Ladino nos Fios

Responsável: Fukuda

Tags: `jogo`, `proxy`

## Desafio

Um jogo rogue-like com cliente e servidor onde o objetivo é pegar a flag, mas a flag esta fora do alcance do jogador.

Ex.:

```
#####
#   #
# @ #  F
#   #
#####
```

## Resolução proposta

Interceptar pacotes de rede para modificar (no lado do servidor) a posicao do usuario e forcar o server a retornar a flag.

Ou modificar a posição do jogador (localmente) manipulando a memoria do processo.

## Como rodar

Tem o servidor e o cliente. O servidor roda em um docker (pelos organizadores do CTF) ou localmente (pelos participantes, durante o desafio), mas o cliente roda localmente.

Fazendo o servidor:
```bash
make # Faz a imagem `umladinonosfios:latest`
make start # roda o servidor em localhost:47000
```

Fazendo o cliente:
```bash
make local # faz o cliente e o servidor em `build/client` e `build/server` respectivamente
./build/client localhost 47000 # roda o cliente, se conectando com o servidor local
```
