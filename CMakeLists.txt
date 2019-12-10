cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(wormsim)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build.emscripten)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall --emrun")

# BUILD THE LIBRARY

set(EMSDK_ROOT $ENV{EMSCRIPTEN})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${EMSDK_ROOT}/cmake/Modules")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EMSDK_ROOT}/cmake/Modules")

add_subdirectory("sundials-2.3.0")

include_directories("sundials-2.3.0/include")
include_directories("sundials-2.3.0/src")

add_executable(${PROJECT_NAME}
    ./sundials-2.3.0/wormsim.cpp
)

target_link_libraries(${PROJECT_NAME}
    
    sundials

    "-o ${CMAKE_CURRENT_SOURCE_DIR}/build.emscripten/wormsim.js"
    "--bind"
    "-s WASM=1"

    "-s EXTRA_EXPORTED_RUNTIME_METHODS='[cwrap]'"
    "-v"
    "-s EXPORT_ES6=0"
    "-s DISABLE_EXCEPTION_CATCHING=0"
    "-s ALLOW_MEMORY_GROWTH=1"
)

# link_libraries("sundials")
# set_target_properties(wormsim PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 --emrun --bind"

# target_compile_definitions(${PROJECT_NAME} PRIVATE GAMEBOYCORE_STATIC=1)



# set(HEADER_FILES
#             wormsim.h
#             sundials-2.3.0/include/ida/ida.h
#             sundials-2.3.0/include/ida/ida_band.h
#             sundials-2.3.0/include/ida/ida_bbdpre.h
#             sundials-2.3.0/include/ida/ida_dense.h
#             sundials-2.3.0/include/ida/ida_spbcgs.h
#             sundials-2.3.0/include/ida/ida_spgmr.h
#             sundials-2.3.0/include/ida/ida_spils.h
#             sundials-2.3.0/include/ida/ida_sptfqmr.h
#             sundials-2.3.0/include/nvector/nvector_parallel.h
#             sundials-2.3.0/include/nvector/nvector_serial.h
#             sundials-2.3.0/include/sundials/sundials_band.h
#             sundials-2.3.0/include/sundials/sundials_dense.h
#             sundials-2.3.0/include/sundials/sundials_fnvector.h
#             sundials-2.3.0/include/sundials/sundials_iterative.h
#             sundials-2.3.0/include/sundials/sundials_math.h
#             sundials-2.3.0/include/sundials/sundials_nvector.h
#             sundials-2.3.0/include/sundials/sundials_smalldense.h
#             sundials-2.3.0/include/sundials/sundials_spbcgs.h
#             sundials-2.3.0/include/sundials/sundials_spgmr.h
#             sundials-2.3.0/include/sundials/sundials_sptfqmr.h
#             sundials-2.3.0/include/sundials/sundials_types.h
#             )

# add_library(wormsim SHARED
#             sundials-2.3.0/src/ida/ida.c
#             sundials-2.3.0/src/ida/ida_band.c
#             sundials-2.3.0/src/ida/ida_band_impl.h
#             sundials-2.3.0/src/ida/ida_bbdpre.c
#             sundials-2.3.0/src/ida/ida_bbdpre_impl.h
#             sundials-2.3.0/src/ida/ida_dense.c
#             sundials-2.3.0/src/ida/ida_dense_impl.h
#             sundials-2.3.0/src/ida/ida_ic.c
#             sundials-2.3.0/src/ida/ida_impl.h
#             sundials-2.3.0/src/ida/ida_io.c
#             sundials-2.3.0/src/ida/ida_spbcgs.c
#             sundials-2.3.0/src/ida/ida_spgmr.c
#             sundials-2.3.0/src/ida/ida_spils.c
#             sundials-2.3.0/src/ida/ida_spils_impl.h
#             sundials-2.3.0/src/ida/ida_sptfqmr.c
#             sundials-2.3.0/src/nvec_ser/fnvector_serial.c
#             sundials-2.3.0/src/nvec_ser/fnvector_serial.h
#             sundials-2.3.0/src/nvec_ser/nvector_serial.c
#             sundials-2.3.0/src/sundials/sundials_band.c
#             sundials-2.3.0/src/sundials/sundials_config.h
#             sundials-2.3.0/src/sundials/sundials_config.in
#             sundials-2.3.0/src/sundials/sundials_dense.c
#             sundials-2.3.0/src/sundials/sundials_iterative.c
#             sundials-2.3.0/src/sundials/sundials_math.c
#             sundials-2.3.0/src/sundials/sundials_nvector.c
#             sundials-2.3.0/src/sundials/sundials_smalldense.c
#             sundials-2.3.0/src/sundials/sundials_spbcgs.c
#             sundials-2.3.0/src/sundials/sundials_spgmr.c
#             sundials-2.3.0/src/sundials/sundials_sptfqmr.c
#             sundials-2.3.0/wormsim.cpp
#             )

# target_include_directories(wormsim PRIVATE .)
# set_target_properties(wormsim PROPERTIES VERSION 1)
# set_target_properties(wormsim PROPERTIES PUBLIC_HEADER wormsim.h)

# install(TARGETS wormsim
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})




# include_directories("lib/assimp/include")
# link_directories("lib/assimp/lib-js")


# file(GLOB_RECURSE CORE_HDR src/*.h)
# file(GLOB_RECURSE CORE_SRC src/*.cpp)

# add_definitions("-std=c++11")

# add_executable(wormsim ${CORE_SRC} ${CORE_HDR})





