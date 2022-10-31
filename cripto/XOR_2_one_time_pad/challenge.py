def xor(entrada: str, chave: list[int]) -> str:
    from itertools import cycle
    return ''.join(list(chr(c ^ ord(l)) for l, c in zip(entrada, cycle(chave))))

if __name__ == '__main__':
    # A chave e secreta :):
    chave: list[int] = [0]*200

    mensagem: str = input('Coloque sua mensagem aqui: ')

    assert mensagem == xor(xor(mensagem, chave[:len(mensagem)]), chave[:len(mensagem)])
    texto_criptografado = xor(mensagem, chave)
    print(texto_criptografado)
