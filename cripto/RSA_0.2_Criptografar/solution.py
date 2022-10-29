from Crypto.Util.number import bytes_to_long, long_to_bytes

def rsa(m: int, e: int, n: int) -> int:
    # Implemente o algoritmo RSA
    return pow(m, e, n)

if __name__ == '__main__':
    p: int = 1125259683658845115191229480253
    q: int = 1210340869750443986350933084433
    n: int = p * q
    e: int = 1259438572750942160138573070108318740982439258884182682359773
    d: int = pow(e, -1, (p - 1) * (q - 1))

    texto_plano: str = 'mensagem secreta'
    print(f'{texto_plano=}')

    texto_plano_int: int = bytes_to_long(texto_plano.encode('UTF-8'))
    print(f'{texto_plano_int=}')

    texto_cifrado_int: int = rsa(texto_plano_int, e, n)
    print(f'{texto_cifrado_int=}')

    texto_decriptografado: str = long_to_bytes(rsa(texto_cifrado_int, d, n)).decode('UTF-8')
    print(f'{texto_decriptografado=}')

    assert texto_decriptografado == texto_plano
