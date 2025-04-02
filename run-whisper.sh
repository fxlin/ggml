
# run it like 
# ./run-whisper.sh 2>&1 | grep "total time"


# WHISPER=`readlink -f build-wsl/bin/whisper`
WHISPER=`readlink -f build/bin/whisper`

# AUDIO=samples/jfk.wav
AUDIO=samples/bernie4min.wav
# AUDIO=samples/bernie8min.wav

# MODEL=models/ggml-medium.bin
MODEL=models/ggml-base.en.bin

cd ~/workspace-ggml/whisper.cpp/

cpu() {
    echo "---- total time cpu ---- "
    for THR in 1 4 8 12 16  
    do 
        ${WHISPER} -t $THR --no-gpu -f $AUDIO --model $MODEL
    done
}

gpu() {
    echo "---- total time gpu ---- "
    # for THR in 1 4 8 12 16  
    for THR in 1 
    do 
        ${WHISPER} -t $THR -f $AUDIO --model $MODEL -p 1
    done
}

profile() {
    xctrace record --template FL-gpu-counters --launch -- \
    ${WHISPER} -t $THR -f $AUDIO --model $MODEL
}

# cpu
 gpu
# profile
