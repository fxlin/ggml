# wsl
WHISPER=`readlink -f build-wsl/bin/whisper`
cd /mnt/d/workspace-ggml/whisper.cpp/
${WHISPER} -t 6 -f samples/jfk.wav




# windows
cd e:\workspace-ggml\ggml

build-cuda\bin\Release\whisper.exe -f e:\workspace-ggml\whisper.cpp\samples\jfk.wav -m e:\workspace-ggml\whisper.cpp\models\ggml-base.en.bin

build-cuda\bin\Release\whisper.exe -f e:\workspace-ggml\whisper.cpp\samples\jfk.wav -m e:\workspace-ggml\whisper.cpp\models\ggml-medium.bin


build-cuda\bin\Release\whisper.exe -f e:\workspace-ggml\whisper.cpp\samples\hp0.wav -m e:\workspace-ggml\whisper.cpp\models\ggml-base.en.bin
