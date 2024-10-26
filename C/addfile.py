from sys import argv

if __name__ == '__main__':
    filename = argv[1]
    includes = argv[2:]
    print(f'Making {filename}.h and {filename}.cpp' + f' including libs: {", ".join(includes)}.' if includes else '.')

    with open(f'include/{filename}.h', 'w+') as file:
        file.write('#pragma once\n')
        file.write('\n')
        for i in includes:
            file.write(f'#include <{i}>\n')

    with open(f'src/{filename}.cpp', 'w+') as file:
        file.write(f'#include "{filename}.h"\n')
        file.write('\n')
        for i in includes:
            file.write(f'#include <{i}>\n')


