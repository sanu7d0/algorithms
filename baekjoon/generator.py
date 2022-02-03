with open('./baekjoon/output.txt', 'w') as f:
    data = str(pow(10, 10000) - 1)
    f.write(f'{data} {data}')
