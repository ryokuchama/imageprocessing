cmake_minimum_required(VERSION 3.0)
# コンパイルに必要なソースコードを取得(それぞれの環境に合わせる)
file(GLOB src ../imageprocessing/*.cpp)
# インクルードパスの設定(これもそれぞれの環境に合わせる)
include_directories(../head)
# コンパイラへのオプション
set(CMAKE_CXX_FLAGS "-std=c++0x -O3")
# コンパイル対象コードと出力ファイル名
add_executable(main ${src})

# OpenCVに必要(Linuxの場合)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBS})