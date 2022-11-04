def xor(entrada: bytes, chave: list[int]) -> bytes:
    from itertools import cycle
    output: bytearray = bytearray()
    for c, k in zip(entrada, cycle(chave)):
        output.append(c ^ k)
    return output

if __name__ == '__main__':
    chave: list[int] = [245, 193, 179, 8, 181, 31, 36, 146, 237, 3, 133, 210, 17, 172, 105, 114, 246, 122, 110, 21, 192, 63, 145, 196, 163, 93, 207, 83, 128, 251, 22, 196, 65, 36, 150, 189, 66, 15, 27, 222, 167, 73, 184, 163, 221, 11, 45, 88, 57, 178, 239, 192, 163, 61, 163, 30, 224, 105, 203, 10, 18, 100, 253, 245, 64, 216, 128, 214, 111, 224, 218, 176, 116, 215, 245, 15, 233, 66, 133, 17, 230, 143, 235, 106, 56, 198, 157, 11, 245, 82, 199, 254, 151, 80, 79, 156, 68, 209, 83, 253, 169, 220, 199, 63, 76, 131, 72, 36, 128, 55, 212, 48, 168, 85, 137, 155, 83, 236, 196, 132, 31, 68, 185, 253, 228, 133, 213, 172, 199, 219, 50, 77, 90, 6, 120, 223, 37, 112, 53, 18, 186, 33, 103, 95, 86, 235, 11, 192, 99, 196, 196, 223, 128, 84, 100, 2, 52, 130, 56, 198, 49, 87, 194, 215, 211, 193, 86, 22, 135, 135, 158, 223, 6, 234, 220, 18, 25, 110, 50, 21, 45, 139, 134, 122, 172, 70, 45, 215, 74, 144, 167, 7, 182, 59, 82, 253, 6, 114, 173, 142]

    mensagem: bytes = input('Coloque sua mensagem aqui: ').encode()

    assert mensagem == xor(xor(mensagem, chave), chave)
    texto_criptografado = xor(mensagem, chave)
    print(texto_criptografado)