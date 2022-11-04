# RSA - Expoente pequeno

Responsável: Tsu

Tags: `rsa`, `python3`

## Desafio

Agora que Jiji sabe um pouco mais sobre RSA. Jiji queria mais segurança e resolveu gerar primos `p` e `q` GIGANTES.

Isso pode trazer algum problema para Jiji? Tente descobrir a mensagem secreta de Jiji!

## Resolução proposta

Vendo que o valor do parâmetro `e` escolhido é muito pequeno, quando elevado o `texto_cifrado_int` pelo parâmetro `e` o seu resultado não é maior que `n`. Portanto, o participante pode apenas resolver a seguinte conta:

texto\_cifrado\_int $^{1/e}$

## Como rodar

O código fonte vai estar disponibilizado no site do `ctfd/ctfd`.
