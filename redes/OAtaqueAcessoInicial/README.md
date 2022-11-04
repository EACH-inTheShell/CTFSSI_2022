# O Ataque - Acesso Inicial

Responsável: Fukuda

Tags: `pacotes`

## Desafio

Fui atacado, mas não sei como. Você consegue me ajudar a descobrir como que o atacante entrou e o que ele fez uma vez que estava la dentro?

Esse primeiro desafio eu gostaria de saber como o atacante teve o primeiro acesso a minha maquina.

Atenção: Esse desafio faz parte de uma série de desafios. Você vai precisar desse arquivos para todos os desafios.

## Resolução proposta

Utilizar o Wireshark, Tshark, TermShark, TcpFlow ou qualquer outra ferramenta de analise de pacotes para ler esse arquivo *.pcap*.

Esse primeiro desafio você tem que identificar uma pagina de login e pegar as credenciais que foram usadas para acessar o site. A senha sera a flag.

## Como rodar

```bash
wireshark -r captura.pcap.gz
```
