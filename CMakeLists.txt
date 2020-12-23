# 最低保証バージョン
cmake_minimum_required(VERSION 3.0)
# プロジェクト名
project(imageprocessing)
# コンパイルに必要なソースコードを取得(それぞれの環境に合わせる)
file(GLOB src ../imageprocessing/src/*.cpp)
# インクルードパスの設定(これもそれぞれの環境に合わせる)
include_directories(../head)
# コンパイラへのオプション
set(CMAKE_CXX_FLAGS "-std=c++0x -O3")
# コンパイル対象コードと出力ファイル名
add_executable(main ${src})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(main ${OpenCV_LIBS})