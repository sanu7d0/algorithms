with open('../build/output.txt', 'w') as f:
    f.flush()
    for i in range(0, 1000):
        f.write(f'{1000000000} ')
