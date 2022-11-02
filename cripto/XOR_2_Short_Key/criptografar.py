def xor(entrada: bytes, chave: list[int]) -> bytes:
    from itertools import cycle
    output: bytearray = bytearray()
    for c, k in zip(entrada, cycle(chave)):
        output.append(c ^ k)
    return output

if __name__ == '__main__':
    # A chave e secreta :):
    chave: list[int] = [238, 176, 200, 80, 229, 28, 207, 94, 185, 224]
    mensagem: bytes
    with open('./texto.txt', 'rb') as f:
        mensagem = f.read()

    assert mensagem == xor(xor(mensagem, chave), chave)
    texto_criptografado = xor(mensagem, chave)
    print(texto_criptografado)

    with open('./texto_criptografado.txt', 'wb') as f:
        f.write(texto_criptografado)

    with open('./texto_criptografado.txt', 'rb') as f:
        print(xor(f.read(),chave).decode())

