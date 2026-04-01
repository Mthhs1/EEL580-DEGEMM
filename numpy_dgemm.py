import numpy as np
import time

n = 960

def degem(a, b):
    
    c = np.zeros((n, n))
    print("Starting matrix multiplication...")
    
    start_time,start_cpu = time.time(), time.process_time()
    
    #multiply a and b
    c = np.dot(a, b)
                
    end_time,end_cpu = time.time(), time.process_time()
    
    total_time = end_time - start_time
    total_cpu = end_cpu - start_cpu
    return c, total_time, total_cpu

#loop 5 times for benchmark
for i in range (5):
    
    #multiply matrix
    a = np.random.rand(n, n)
    b = np.random.rand(n, n)
    
    result, total_time, total_cpu = degem(a, b)

    print('tempo matriz', n, ":", total_time, "cpu:", total_cpu)
