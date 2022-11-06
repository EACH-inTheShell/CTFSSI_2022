# RSA - Small difference attack

Responsável: Tsu

Tags: `rsa`, `python3`

## Desafio

Jiji gerou seus números secretos **p** e **q** e escondeu eles! Consegue descobrir a mensagem secreta de Jiji?

## Resolução proposta

Descobrindo que a diferença entre os valores p e q é pequena, é possível usar a equação $n = pq$.

Desenvolvendo a equação:

$$n = pq$$

$$n = \(\frac{p+q}{2} + \frac{p-q}{2}\)\(\frac{p+q}{2} - \frac{p-q}{2}\)$$

$$n = \(\frac{p+q}{2}\)^{2} - \(\frac{p-q}{2}\)^{2}$$

$$n + \(\frac{p-q}{2}\)^{2} = \(\frac{p+q}{2}\)^{2}$$

Dada a equação acima é possível ver que a soma do valor $n$ com um quadrado perfeito resulta em outro quadrado perfeito. Sabendo que a diferença entre $p$ e $q$ é pequena, nós sabemos que $\(\frac{p-q}{2}\)^{2}$ é pequeno também!

Portanto conseguimos fazer um ataque de força bruta para descobrir qual é o valor de $p - q$.

Descobrindo esse valor a equação se torna uma equação de segundo grau. Encontrando o valor de $p$ é fácil encontrar o valor de $q$.

Então o valor $d$ é calculado e a mensagem decriptografada com o algoritmo RSA.

Um exemplo da resolução pode ser encontrada dentro do arquivo `./assets/solve_equation.sage`

## Como rodar

O código fonte vai estar disponibilizado no site do `ctfd/ctfd`.
