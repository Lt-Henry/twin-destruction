
gcc = meson.get_compiler('cpp')
libm = gcc.find_library('m')
sdl2 = dependency('sdl2')
sdl2_image = dependency('SDL2_image')

lib_files=['utils.cpp','name.cpp','node.cpp','atlas.cpp','game.cpp','sprite.cpp']
source_files=['main.cpp']

executable('twin', (source_files+lib_files),
    cpp_args:'-std=c++11',
    dependencies: [libm,sdl2,sdl2_image]
    )
