# Dump - Flag #4

Responsável: Tsu

Tags: `volatility`

## Desafio

O dump de memória pode ser encontrado no desafio `Dump - Arquivo`

Jiji estava escondendo um segredo na sua anotação de computação forense...

## Dicas

Já tentou executar? - 5 pontos

## Resolução proposta

A segunda flag é a flag que está no processo aberto do `notepad.exe`

Para abrir o dump de memória é necessário usar o volatility.

Esse [site](https://book.hacktricks.xyz/generic-methodologies-and-resources/basic-forensic-methodology/memory-dump-analysis/volatility-cheatsheet) é um bom lugar para referências.

Para ver o dump dos processos abertos usando o volatility 3:

```sh
python3 volatility3-1.0.0/vol.py -f jiji_mem.raw windows.pslist.PsList
```

Para ver o dump dos processos abertos usando o volatility 2:

```sh
volatility -f mem.raw --profile Win81U1x64 pslist
```

Então, é preciso extrair o processo `notepad.exe`:

```sh
python3 volatility3-1.0.0/vol.py -f jiji_mem.raw windows.dumpfiles.DumpFiles --pid <pid>

# OU

volatility -f mem.raw --profile Win81U1x64 memdump --dump-dir=./ -p <pid>
```

![imagem](AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA)

## Como rodar

O código fonte vai estar disponibilizado no site do `ctfd/ctfd`.
