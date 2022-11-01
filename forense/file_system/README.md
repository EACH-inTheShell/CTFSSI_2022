# File! System?

Responsável: Fukuda

Tags: `mount`

## Desafio

Alguém me disse que tem arquivos dentro desse arquivo. O que isso quer dizer?

## Resolução proposta

Rodando `file ./arquivo` da para ver que o arquivo é um FAT32.

Monte com `mkdir mnt && sudo mount arquivo ./mnt`.

Dentro tem uma série de diretórios. Utilizando tab complete, o nome dos diretórios montam a flag.

Depois, desmonte o arquivo com `sudo umount ./mnt`.
