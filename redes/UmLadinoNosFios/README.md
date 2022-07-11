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

## Como construir

```bash
```
