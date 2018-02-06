
gcc = meson.get_compiler('cpp')
libm = gcc.find_library('m')

executable('twin', ['main.cpp'],
    cpp_args:'-std=c++11',
    dependencies: libm
    )
