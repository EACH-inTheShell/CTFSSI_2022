def xor(entrada: bytes, chave: int) -> bytes:
    output: bytearray = bytearray()
    for c in entrada:
        output.append(c ^ chave)
    return output

if __name__ == '__main__':
    f = open('./hecker_da_jiji.png', 'rb')
    plain_text = f.read()
    f.close()
    chave: int = 171

    assert plain_text[:5] == xor(xor(plain_text[:5], chave), chave)

    f_criptografado = open('./hecker_da_jiji_criptografado.png', 'wb')
    f_criptografado.write(xor(plain_text, chave))
    f_criptografado.close()

    f_criptografado = open('./hecker_da_jiji_criptografado.png', 'rb')
    f_decriptografado = open('./hecker_da_jiji_decriptografado.png', 'wb')
    f_decriptografado.write(xor(f_criptografado.read(), chave))
    f_decriptografado.close()
    f_criptografado.close()
