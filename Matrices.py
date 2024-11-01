import numpy as np

def prodmtr(A, B):
    A = np.array(A)
    B = np.array(B)

    n = A.shape[0] # n renglones
    m = A.shape[1] # m columnas
    k = B.shape[0] # k renglones
    mb = B.shape[1] # mb columnas
    

    X = np.zeros((n, k), int)

    for i in range(n):
        for j in range(k):
            for l in range(m):
                X[i, j] += A[i, l] * B[l, j]
   
    if m != mb:
        print("ERROR")
    else:
        print(X)

def detinv(A):
    A = np.array(A)
    id = np.array([(1, 0, 0), (0, 1, 0), (0, 0, 1)])
    
    det =  A[0, 0]*(A[1, 1]*A[2, 2] - A[1, 2]*A[2, 1]) + A[0, 1]*(A[1, 2]*A[2, 0] - A[1, 0]*A[2, 2]) + A[0, 2]*(A[1, 0]*A[2, 1] - A[1, 1]*A[2, 0])
    print(det)
    adj = np.array([
    [A[1, 1]*A[2, 2] - A[1, 2]*A[2, 1],
A[0, 2]*A[2, 1] - A[0, 1]*A[2, 2],
A[0, 1]*A[1, 2] - A[0, 2]*A[1, 1]],
    [A[1, 2]*A[2, 0] - A[1, 0]*A[2, 2],
    A[0, 0]*A[2, 2] - A[0, 2]*A[2, 0],
    A[0, 2]*A[1, 0] - A[0, 0]*A[1, 2]],
    [A[1, 0]*A[2, 1] - A[1, 1]*A[2, 0],
    A[0, 1]*A[2, 0] - A[0, 0]*A[2, 1],
    A[0, 0]*A[1, 1] - A[0, 1]*A[1, 0]]
    ])

    if det == 0:
        print("ERROR la matriz tiene determinante 0")
    
    else:
        inv = adj*(1/det)
        print(inv, "\n")

B = np.array([(3, 4, 1), 
              (1, 6, 3), 
              (2, 4, 6)])
detinv(B)
print(np.linalg.inv(B))
    
    
    
    
    