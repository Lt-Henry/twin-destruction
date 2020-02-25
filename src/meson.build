
gcc = meson.get_compiler('cpp')
libm = gcc.find_library('m')
sdl2 = dependency('sdl2')
sdl2_image = dependency('SDL2_image')

executable('twin', ['main.cpp','utils.cpp','name.cpp','node.cpp','atlas.cpp'],
    cpp_args:'-std=c++11',
    dependencies: [libm,sdl2,sdl2_image]
    )
