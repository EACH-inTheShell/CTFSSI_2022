# Sabores de uma vulnerabilidade

Responsável: Fukuda

Tags: `stack overrun`

## Desafio

Dar o código fonte de um programa com vários tipos diferentes de exploração para uma vulnerabilidade específica: `stack overrun`.

Disponibilizar também um endpoint com esse mesmo código rodando no servidor (com a flag).

Algo tipo:

```c
void desafio1()
{
	volatile int valor = 0;
	char buffer[20];
	gets(buffer);

	if (valor == 0) {
		exit(0);
	}
}

void desafio2()
{
	// ...
}

int main() {
	desafio1();
	desafio2();

	printf(flag);
}
```

## Resolução proposta

Explore as vulnerabilidades.
