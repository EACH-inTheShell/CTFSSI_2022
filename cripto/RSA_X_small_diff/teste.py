import re

def all_equal(list) -> bool:
    for e in list:
        if e != list[0]:
            print(f'{e}')
            print(f'{list[0]}')
            return False
    return True

if __name__ == '__main__':
    f1 = open('./challenge.py')
    f2 = open('./solution.py')
    f3 = open('./assets/solve_equation.sage')

    arquivos = [f1, f2, f3]
    q_values = []
    p_values = []
    n_values = []
    e_values = []
    d_values = []
    texto_cifrado_int_values = []

    for f in arquivos:
        for line in f.readlines():
            if re.match('.*q: int = .*', line):
                q_values.append(re.sub('\n', '', re.sub('#', '', line)))
            if re.match('.*p: int = .*', line):
                p_values.append(re.sub('\n', '', re.sub('#', '', line)))
            if re.match('.*n: int = .*', line):
                n_values.append(re.sub('\n', '', re.sub('#', '', line)))
            if re.match('.*e: int = .*', line):
                e_values.append(re.sub('\n', '', re.sub('#', '', line)))
            if re.match('.*d: int = .*', line):
                d_values.append(re.sub('\n', '', re.sub('#', '', line)))
            if re.match('.*texto_cifrado_int: int = .*', line):
                texto_cifrado_int_values.append(re.sub('\n', '', re.sub('#', '', line)))
        f.close()

    assert all_equal(q_values)
    assert all_equal(p_values)
    assert all_equal(n_values)
    assert all_equal(e_values)
    assert all_equal(d_values)
    assert all_equal(texto_cifrado_int_values)

    print(q_values)
    print(p_values)
    print(n_values)
    print(e_values)
    print(d_values)
    print(texto_cifrado_int_values)
