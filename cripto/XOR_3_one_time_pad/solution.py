def xor(entrada: bytes, chave: list[int]) -> bytes:
    from itertools import cycle
    output: bytearray = bytearray()
    for c, k in zip(entrada, cycle(chave)):
        output.append(c ^ k)
    return output

if __name__ == '__main__':
    # 200 caracteres 'a' criptografados
    output = bytearray(b"\x94\xa0\xd2i\xd4~E\xf3\x8cb\xe4\xb3p\xcd\x08\x13\x97\x1b\x0ft\xa1^\xf0\xa5\xc2<\xae2\xe1\x9aw\xa5 E\xf7\xdc#nz\xbf\xc6(\xd9\xc2\xbcjL9X\xd3\x8e\xa1\xc2\\\xc2\x7f\x81\x08\xaaks\x05\x9c\x94!\xb9\xe1\xb7\x0e\x81\xbb\xd1\x15\xb6\x94n\x88#\xe4p\x87\xee\x8a\x0bY\xa7\xfcj\x943\xa6\x9f\xf61.\xfd%\xb02\x9c\xc8\xbd\xa6^-\xe2)E\xe1V\xb5Q\xc94\xe8\xfa2\x8d\xa5\xe5~%\xd8\x9c\x85\xe4\xb4\xcd\xa6\xbaS,;g\x19\xbeD\x11Ts\xdb@\x06>7\x8aj\xa1\x02\xa5\xa5\xbe\xe15\x05cU\xe3Y\xa7P6\xa3\xb6\xb2\xa07w\xe6\xe6\xff\xbeg\x8b\xbdsx\x0fStL\xea\xe7\x1b\xcd\'L\xb6+\xf1\xc6f\xd7Z3\x9cg\x13\xcc\xef")

    # Para recuperar a chave precisamos usar a operacao XOR novamente
    chave: list[int] = []
    for k in output:
        chave.append(k ^ ord('a'))

    # Criamos uma lista com todas as tentativas de brute force
    brute_force = []
    # Abrimos o arquivo flag.txt
    with open('./flag.txt', 'rb') as f:
        msg = f.read()
        # Tentamos fazer a decriptografia
        for i in range(0, 200 - len(msg)):
            # Criamos uma lista com todas as tentativas de brute force
            brute_force.append(xor(msg, chave[i:]))

    # Imprimimos todas as tentativas
    print('-' * 100)
    for tentativa in brute_force:
        print(tentativa)
        print('-' * 100)
