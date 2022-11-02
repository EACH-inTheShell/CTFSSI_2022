def xor(entrada: bytes, chave: int) -> bytes:
    # Faca a implementacao do algoritmo
    return b'texto_criptografado'

if __name__ == '__main__':
    entrada: bytes = b'UseAOperacaoXORAqui'
    chave: int = 32

    texto_criptografado = xor(entrada, chave)
    print(f'Flag: EITS{{{texto_criptografado.decode()}}}')
