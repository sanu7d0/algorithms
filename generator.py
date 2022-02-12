with open('./baekjoon/build/output.txt', 'w') as f:
    for i in range(1, 123456-1):
        f.write(f'S 1 {i+1}\n')
    f.write('S 1 1');
