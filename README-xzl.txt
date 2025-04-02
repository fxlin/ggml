many comments by fxl.  esp whipser.cpp
~~~~~~~~~~~~~
To build

e: 
cd workspace-ggml/ggml/


# config
# under ggml/
cmake -B build-cuda -DGGML_CUBLAS=ON -DCMAKE_CUDA_ARCHITECTURES="50;52;61;70" 

# windows: do it from x64 Native tools comamnd prompot. no vs launch needed
cmake --build build-cuda -j --config Release


##### run whisper.cpp 
# windows
cd e:\workspace-ggml\ggml

build-cuda\bin\Release\whisper.exe -f e:\workspace-ggml\whisper.cpp\samples\jfk.wav -m e:\workspace-ggml\whisper.cpp\models\ggml-base.en.bin

build-cuda\bin\Release\whisper.exe -f e:\workspace-ggml\whisper.cpp\samples\jfk.wav -m e:\workspace-ggml\whisper.cpp\models\ggml-medium.bin

build-cuda\bin\Release\whisper.exe -f e:\workspace-ggml\whisper.cpp\samples\hp0.wav -m e:\workspace-ggml\whisper.cpp\models\ggml-base.en.bin

##### run test
# windows 
cd e:\workspace-ggml\ggml

# use gpu, input 100x100, kernel 16x16
build-cuda\bin\Release\test-conv2d.exe 100 100 16 1
build-cuda\bin\Release\test-conv2d.exe 100 100 16 0

$ ./test-conv2d.exe 1024 1024 3 1
load_model: ggml tensor size    = 384 bytes
load_model: backend buffer size = 256.07 MB
load_model: >>>>>>>> using CUDA backend
ggml_init_cublas: GGML_CUDA_FORCE_MMQ:   no
ggml_init_cublas: CUDA_USE_TENSOR_CORES: yes
ggml_init_cublas: found 1 CUDA devices:
  Device 0: NVIDIA GeForce GTX 1660 SUPER, compute capability 7.5, VMM: yes
main: compute buffer size: 2560.00 MB

Main compute finished.main: Latency: 0.348514 s

Performing test:
ggml_im2col (603979776): FAILED
