def xor(entrada: bytes, chave: int) -> bytes:
    output: bytearray = bytearray()
    for c in entrada:
        output.append(c ^ chave)
    return output

if __name__ == '__main__':
    entrada: bytes = b'UseAOperacaoXORAqui'
    chave: int = 32

    texto_criptografado = xor(entrada, chave)
    print(f'Flag: EITS{{{texto_criptografado.decode()}}}')
