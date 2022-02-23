with open('./build/output.txt', 'w') as f:
    f.flush()
    for i in range(1, 65):
        f.write(f'{i}\n')
