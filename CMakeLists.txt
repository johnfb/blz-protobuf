cmake_minimum_required(VERSION 2.8.11)
project(blz_protobuf CXX VERSION 0.0.1)

include(CheckCXXSourceCompiles)
include(CheckXXCompilerFlag)
include(GNUInstallDirs)

find_package(Protobuf "3.4.0" REQUIRED)

# does the compiler default to something C++11 compatible?
check_cxx_source_compiles("
#if __cplusplus < 201103L
#error
#endif
int main() {}
" ${PROJECT_NAME}_HAVE_CXX11)

if (NOT {$PROJECT_NAME}_HAVE_CXX11)
    # does the compiler support the standard flag to turn on C++11?
    check_cxx_compiler_flag("-std=c++11" BLZ_PROTOBUF_CXX_FLAG)
    if (NOT BLZ_PROTOBUF_CXX_FLAG)
        message(FATAL_ERROR " C++11 support is required for this library")
    endif()
    set(CMAKE_CXX_FLAGS "${BLZ_PROTOBUF_CXX_FLAG} ${CMAKE_CXX_FLAGS}")
endif()

