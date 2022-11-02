def xor(entrada: bytes, chave: list[int]) -> bytes:
    from itertools import cycle
    output: bytearray = bytearray()
    for c, k in zip(entrada, cycle(chave)):
        output.append(c ^ k)
    return output

if __name__ == '__main__':
    # A chave e secreta :):
    chave: list[int] = [0]*200

    mensagem: bytes = input('Coloque sua mensagem aqui: ').encode()

    assert mensagem == xor(xor(mensagem, chave[:len(mensagem)]), chave[:len(mensagem)])
    texto_criptografado = xor(mensagem, chave)
    print(texto_criptografado)
