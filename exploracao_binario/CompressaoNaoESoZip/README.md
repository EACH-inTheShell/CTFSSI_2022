# Compressão não é só Zip

Responsável: Fukuda

Tags: `packer`, `binary_compression`, `strings`

## Desafio

Dar um binário comprimido com *UPX*.

## Resolução proposta

Descomprimir o binário com `upx -d -o ./unpacked ./packed` e olhar o binário com `strings ./unpacked | grep eits` para pegar a flag.

## Como rodar

Rode `make` para gerar o executável `packed`. Ele é o que sera disponibilizado para download.

Atenção: você vai precisar ter o upx instalado na sua maquina para gerar (e resolver) esse desafio da maneira pretendida.
