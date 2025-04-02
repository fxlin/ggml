#
# whisper

add_library(whisper-cpp STATIC
    whisper.cpp
    )

target_link_libraries(whisper-cpp PRIVATE
    ggml
    )

set(TEST_TARGET whisper)
add_executable(${TEST_TARGET} main.cpp)
if (GGML_USE_VTUNE)
# add_link_options("C:\\Program Files (x86)\\Intel\\oneAPI\\vtune\\latest\\sdk\\lib64\\libittnotify.lib") #xzl
#xzl
link_directories("C:\\Program Files (x86)\\Intel\\oneAPI\\vtune\\latest\\sdk\\lib64\\") # for x64 target
# link_directories("C:\\Program Files (x86)\\Intel\\oneAPI\\vtune\\latest\\sdk\\lib32\\") # for x86 target
target_link_libraries(${TEST_TARGET} PRIVATE whisper-cpp common libittnotify.lib)
else()
target_link_libraries(${TEST_TARGET} PRIVATE whisper-cpp common)
endif()

target_include_directories(${TEST_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(${TEST_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ggml)

#
# whisper-quantize

set(TEST_TARGET whisper-quantize)
add_executable(${TEST_TARGET} quantize.cpp)
target_link_libraries(${TEST_TARGET} PRIVATE ggml common common-ggml)
