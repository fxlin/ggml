XPS15, 6 cores

code test-mul-mat0.c

----------------
GPU, CUDA 

obs: ggml batch mm does not benefit from bs>1. 
likely realted to how ggml partition matmul (?) 
    at lowest level, 
        only use gpu for 2d matmul. 
        along dim3,4 --> issue multi gpu matmul calls sequentially

BATCHED MAtmul (bs=1) M=N=K=1024
~ 6ms 


BATCHED MAtmul (bs=4)
~24 ms (see below)

test-mul-mat0: iter:0/4 #threads 1
ggml_init_cublas: GGML_CUDA_FORCE_MMQ:   no
ggml_init_cublas: CUDA_USE_TENSOR_CORES: yes
ggml_init_cublas: found 1 CUDA devices:
  Device 0: NVIDIA GeForce GTX 1650 Ti, compute capability 7.5, VMM: yes
testing: mul_mat, [1024, 1024, 4, 1] = [1024, 1024, 4, 1] * [1024, 1024, 4, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     4]             NONE x (  1) wall =   0.002 /   0.002 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     4]          MUL_MAT g (  1) wall =  33.734 /  33.734 ms, wait =   0.000 /   0.000 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.002 ms
perf_total_per_op_us[         MUL_MAT] =  33.734 ms
========================================
--- xzl --- graph eval 34 ms
test-mul-mat0: iter:1/4 #threads 2
testing: mul_mat, [1024, 1024, 4, 1] = [1024, 1024, 4, 1] * [1024, 1024, 4, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     4]             NONE x (  1) wall =   0.001 /   0.001 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     4]          MUL_MAT g (  1) wall =  26.735 /  26.735 ms, wait =  26.727 /  26.727 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.001 ms
perf_total_per_op_us[         MUL_MAT] =  26.735 ms
========================================
--- xzl --- graph eval 29 ms
test-mul-mat0: iter:2/4 #threads 4
testing: mul_mat, [1024, 1024, 4, 1] = [1024, 1024, 4, 1] * [1024, 1024, 4, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     4]             NONE x (  1) wall =   0.001 /   0.001 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     4]          MUL_MAT g (  1) wall =  25.836 /  25.836 ms, wait =  25.834 /  25.834 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.001 ms
perf_total_per_op_us[         MUL_MAT] =  25.836 ms
========================================
--- xzl --- graph eval 28 ms
test-mul-mat0: iter:3/4 #threads 6
testing: mul_mat, [1024, 1024, 4, 1] = [1024, 1024, 4, 1] * [1024, 1024, 4, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     4]             NONE x (  1) wall =   0.001 /   0.001 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     4]          MUL_MAT g (  1) wall =  24.209 /  24.209 ms, wait =  24.207 /  24.207 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.001 ms
perf_total_per_op_us[         MUL_MAT] =  24.209 ms
========================================
--- xzl --- graph eval 27 ms






----------------
CPU 

#threads    lat/ms
1           120        (?? -- problematic?? too long)
2           40          
4           30      
6           20


test-mul-mat0: iter:0/4 #threads 1
testing: mul_mat, [1024, 1500, 1, 1] = [1024, 1024, 1, 1] * [1024, 1500, 1, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1500,     1]             NONE x (  1) wall =   0.002 /   0.002 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1500,     1]          MUL_MAT g (  1) wall = 119.525 / 119.525 ms, wait =   0.000 /   0.000 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.002 ms
perf_total_per_op_us[         MUL_MAT] = 119.525 ms
========================================
--- xzl --- graph eval 119 ms
test-mul-mat0: iter:1/4 #threads 2
testing: mul_mat, [1024, 1024, 1, 1] = [1024, 1024, 1, 1] * [1024, 1024, 1, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     1]             NONE x (  1) wall =   0.000 /   0.000 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     1]          MUL_MAT g (  1) wall =  39.666 /  39.666 ms, wait =   0.000 /   0.000 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.001 ms
perf_total_per_op_us[         MUL_MAT] =  39.666 ms
========================================
--- xzl --- graph eval 41 ms
test-mul-mat0: iter:2/4 #threads 4
testing: mul_mat, [1024, 1024, 1, 1] = [1024, 1024, 1, 1] * [1024, 1024, 1, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     1]             NONE x (  1) wall =   0.000 /   0.000 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     1]          MUL_MAT g (  1) wall =  30.337 /  30.337 ms, wait =   8.051 /   8.051 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.001 ms
perf_total_per_op_us[         MUL_MAT] =  30.337 ms
========================================
--- xzl --- graph eval 33 ms
test-mul-mat0: iter:3/4 #threads 6
testing: mul_mat, [1024, 1024, 1, 1] = [1024, 1024, 1, 1] * [1024, 1024, 1, 1]
=== GRAPH ===
n_nodes = 2
 -   0: [  1024,  1024,     1]             NONE x (  1) wall =   0.001 /   0.001 ms, wait =   0.000 /   0.000 ms
 -   1: [  1024,  1024,     1]          MUL_MAT g (  1) wall =  22.960 /  22.960 ms, wait =   8.933 /   8.933 ms
n_leafs = 1
 -   0: [  1024,  1024]     NONE           leaf_0
perf_total_per_op_us[            NONE] =   0.001 ms
perf_total_per_op_us[         MUL_MAT] =  22.960 ms
========================================
--- xzl --- graph eval 27 ms
Press any key to continue . . .