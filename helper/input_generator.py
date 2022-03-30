with open('./build/output.txt', 'w') as f:
    f.flush()
    for i in range(0, 40):
        f.write(f'{i}\n')
