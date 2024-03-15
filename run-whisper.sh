WHISPER=`readlink -f build-wsl/bin/whisper`
cd /mnt/d/workspace-ggml/whisper.cpp/
${WHISPER} -t 6 -f samples/jfk.wav
