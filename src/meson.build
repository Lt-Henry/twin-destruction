
gcc = meson.get_compiler('cpp')
libm = gcc.find_library('m')
sdl2 = dependency('sdl2')
sdl2_image = dependency('SDL2_image')

executable('twin', ['main.cpp','game.cpp','atlas.cpp','screen.cpp','actor.cpp','staff.cpp'],
    cpp_args:'-std=c++11',
    dependencies: [libm,sdl2,sdl2_image]
    )
