cmake_minimum_required(VERSION 3.29)
project(Toblerone)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".a")
add_executable(Toblerone main.cpp ../Toblerone/resources.rc)
add_compile_options(-static -static-libgcc -static-libstdc++)
include_directories("C:/lib/C++/Toblerone")



if (WIN64)
    set_target_properties(Toblerone PROPERTIES LINK_FLAGS "-mwindows -static")
    include_directories("C:/lib/C++/Windows")
elseif (WIN32)
    set_target_properties(Toblerone PROPERTIES LINK_FLAGS "-mwindows -static")
    include_directories("C:/lib/C++/Windows")
    include_directories("C:/lib/C++/Windows/32/fltk-1.3.9")
    set(FLTK_INCLUDE_DIR "C:/lib/C++/Windows/32/fltk-1.3.9/include")
    set(FLTK_FLUID_EXECUTABLE "C:/lib/C++/Windows/32/fltk-1.3.9/bin/fluid.exe")
endif()



target_link_libraries(Toblerone
        C:/lib/C++/Windows/32/fltk-1.3.9/lib/libfltk.a
        C:/lib/C++/Windows/32/fltk-1.3.9/lib/libfltk_images.a
        C:/lib/C++/Windows/32/fltk-1.3.9/lib/libfltk_jpeg.a
        C:/lib/C++/Windows/32/fltk-1.3.9/lib/libfltk_png.a
        comctl32
)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")


