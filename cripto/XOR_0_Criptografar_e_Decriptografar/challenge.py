def xor(entrada: str, chave: int) -> str:
    # Use a chave para criptografar a entrada usando a operacao XOR
    return 'texto_criptografado'

if __name__ == '__main__':
    entrada: str = 'UseAOperacaoXORAqui'
    chave: int = 32

    texto_criptografado = xor(entrada, chave)
    print(f'Flag: EITS{{{texto_criptografado}}}')
