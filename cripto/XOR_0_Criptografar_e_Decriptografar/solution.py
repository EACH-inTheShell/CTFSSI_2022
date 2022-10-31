def xor(entrada: str, chave: int) -> str:
    # Use a chave para criptografar a entrada usando a operacao XOR
    return ''.join(list(chr(chave ^ ord(letra)) for letra in entrada))

if __name__ == '__main__':
    entrada: str = 'UseAOperacaoXORAqui'
    chave: int = 32

    texto_criptografado = xor(entrada, chave)
    print(f'Flag: EITS{{{texto_criptografado}}}')
