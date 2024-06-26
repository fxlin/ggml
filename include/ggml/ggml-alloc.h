#pragma once

#include "ggml.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct ggml_backend_buffer_type * ggml_backend_buffer_type_t;
typedef struct ggml_backend_buffer * ggml_backend_buffer_t;
typedef struct ggml_backend * ggml_backend_t;

// Tensor allocator
typedef struct ggml_tallocr * ggml_tallocr_t;

GGML_API ggml_tallocr_t ggml_tallocr_new(ggml_backend_buffer_t buffer);
GGML_API void           ggml_tallocr_free(ggml_tallocr_t talloc);
GGML_API void           ggml_tallocr_alloc(ggml_tallocr_t talloc, struct ggml_tensor * tensor);

// Graph allocator
/*
  Example usage:
    ggml_gallocr_t galloc = ggml_gallocr_new(ggml_bacckend_cpu_buffer_type());

    // optional: create a worst-case graph and reserve the buffers to avoid reallocations
    // xzl: meaning trying to dry-build a graph with maximum input (hence maximum mem alloc situation)
    //      the graph is used for mem reserve only
    ggml_gallocr_reserve(galloc, build_graph(max_batch));

    // allocate the graph
    struct ggml_cgraph * graph = build_graph(batch);
    ggml_gallocr_alloc_graph(galloc, graph);

    printf("compute buffer size: %zu bytes\n", ggml_gallocr_get_buffer_size(galloc, 0));

    // evaluate the graph
    ggml_backend_graph_compute(backend, graph);
*/

// special tensor flags for use with the graph allocator:
//   ggml_set_input(): all input tensors are allocated at the beginning of the graph in non-overlapping addresses
//   ggml_set_output(): output tensors are never freed and never overwritten

typedef struct ggml_gallocr * ggml_gallocr_t;

GGML_API ggml_gallocr_t ggml_gallocr_new(ggml_backend_buffer_type_t buft);
GGML_API ggml_gallocr_t ggml_gallocr_new_n(ggml_backend_buffer_type_t * bufts, int n_bufs);
GGML_API void           ggml_gallocr_free(ggml_gallocr_t galloc);

// pre-allocate buffers from a measure graph - does not allocate or modify the graph 
// call with a worst-case graph to avoid buffer reallocations
// not strictly required for single buffer usage: ggml_gallocr_alloc_graph will reallocate the buffers automatically if needed
// returns false if the buffer allocation failed
// xzl: meaning this is the way to "preallocate" buffer before actual eval?? 
//      cf: whisper_allocr_graph_init()
GGML_API bool ggml_gallocr_reserve(ggml_gallocr_t galloc, struct ggml_cgraph * graph);
GGML_API bool ggml_gallocr_reserve_n(ggml_gallocr_t galloc, struct ggml_cgraph * graph, const int * node_buffer_ids);

// automatic reallocation if the topology changes when using a single buffer  (xzl: means what)
// returns false if using multiple buffers and a re-allocation is needed (call ggml_gallocr_reserve_n first to set the node buffers)
GGML_API bool ggml_gallocr_alloc_graph(ggml_gallocr_t galloc, struct ggml_cgraph * graph);

GGML_API size_t ggml_gallocr_get_buffer_size(ggml_gallocr_t galloc, int buffer_id);

// Utils
// Create a buffer and allocate all the tensors in a ggml_context
//    xzl:"create a buffer" means ... a ggml_backend_buffer obj (which wraps around 1+ actual backend bufs?)
GGML_API struct ggml_backend_buffer * ggml_backend_alloc_ctx_tensors_from_buft(struct ggml_context * ctx, ggml_backend_buffer_type_t buft);
GGML_API struct ggml_backend_buffer * ggml_backend_alloc_ctx_tensors(struct ggml_context * ctx, ggml_backend_t backend);


// xzl: there seem two ways to alloca tnesors...
// 1. simple one. use context. directly call backend method to alloc 1 buf. then alloc
//    tensors on the buf (e.g. for weights). cf test-conv1d.cpp
// 2. use graph alloc. does not need a contxt... all state is kept inside the graph allocator
//      mantain multiple backend bufs inside? 
//    used for graph eval??   also cf test-conv1d.cpp

#ifdef  __cplusplus
}
#endif
