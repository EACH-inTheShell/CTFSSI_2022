def xor(entrada: bytes, chave: int) -> bytes:
    output: bytearray = bytearray()
    for c in entrada:
        output.append(c ^ chave)
    return output

if __name__ == '__main__':
    f_criptografado = open('./hecker_da_jiji_criptografado.png', 'rb')
    msg_criptografada = f_criptografado.read()
    f_criptografado.close()

    for i in range(0,256):
        tentativa = xor(msg_criptografada, i)
        if b'PNG' in tentativa:
            f_decriptografado = open(f'./hecker_da_jiji_decriptografado_{i}.png', 'wb')
            f_decriptografado.write(tentativa)
            f_decriptografado.close()

