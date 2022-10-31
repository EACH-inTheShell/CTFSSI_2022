def xor(entrada: str, chave: list[int]) -> str:
    return ''.join(list(chr(c ^ ord(l)) for l, c in zip(entrada, chave)))

if __name__ == '__main__':
    entrada: str = 'UseAOperacaoXORAqui'
    chave: list[int] = 32

    texto_criptografado = xor(entrada, chave)
    print(f'Flag: EITS{{{texto_criptografado}}}')
