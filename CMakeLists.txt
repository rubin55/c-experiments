cmake_minimum_required(VERSION 2.8)
project(c_experiments)

set(CMAKE_CXX_STANDARD 14)

include_directories(app)
include_directories(cpl)
include_directories(mc)
include_directories(oap)
include_directories(tcc)

# app
add_executable(byterep app/chapter_02/byterep.c)

# cpl
add_executable(hello cpl/hello.c)
add_executable(cel2fahrs cpl/cel2fahrs.c)
add_executable(countchars cpl/countchars.c)
add_executable(countlines cpl/countlines.c)
add_executable(fahr2 cpl/fahr2.c)
add_executable(fahrs2cels cpl/fahr2cels.c)
add_executable(get2put cpl/get2put.c)

# mc
add_executable(getting-started mc/getting-started.c)

# oap
add_executable(simple1 oap/chapter_02/simple1.c)
target_link_libraries(simple1 GL GLU glut)
add_executable(simple2 oap/chapter_02/simple2.c)
target_link_libraries(simple2 GL GLU glut)
add_executable(simple3 oap/chapter_02/simple3.c)
target_link_libraries(simple3 GL GLU glut)

# tcc
add_executable(first tcc/first.c)

# var
add_executable(joystick var/joystick.c)
