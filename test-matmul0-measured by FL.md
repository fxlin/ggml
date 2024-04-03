XPS15, 6 cores


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