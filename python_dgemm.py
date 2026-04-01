import time 
import random

n = 960

a = [[random.random() for _ in range(n)] for _ in range(n)]
b = [[random.random() for _ in range(n)] for _ in range(n)]

def degeem(a, b):
    
    print("Starting matrix multiplication...")

    rows = len(a)
    cols = len(b[0])
    common = len(b)
    c = [[0.0 for _ in range(cols)] for _ in range(rows)]
    
    start_time,start_cpu = time.time(), time.process_time()
    
    #multiply a and b
    for i in range(rows):
        for j in range(cols):
            for k in range(common):
                c[i][j] += a[i][k] * b[k][j]
                
    end_time,end_cpu = time.time(), time.process_time()
    total_time = end_time - start_time
    total_cpu = end_cpu - start_cpu
    return c, total_time, total_cpu

result, total_time, total_cpu = degeem(a, b)
print(f"Total time taken: {total_time} seconds")
print(f"Total CPU time taken: {total_cpu} seconds")
