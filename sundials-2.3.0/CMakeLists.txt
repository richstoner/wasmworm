cmake_minimum_required(VERSION 3.4.1)

include_directories(sundials-2.3.0/include sundials-2.3.0/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories("include")
include_directories("src")

set(HEADER_FILES
            wormsim.h
            include/ida/ida.h
            include/ida/ida_band.h
            include/ida/ida_bbdpre.h
            include/ida/ida_dense.h
            include/ida/ida_spbcgs.h
            include/ida/ida_spgmr.h
            include/ida/ida_spils.h
            include/ida/ida_sptfqmr.h
            include/nvector/nvector_parallel.h
            include/nvector/nvector_serial.h
            include/sundials/sundials_band.h
            include/sundials/sundials_dense.h
            include/sundials/sundials_fnvector.h
            include/sundials/sundials_iterative.h
            include/sundials/sundials_math.h
            include/sundials/sundials_nvector.h
            include/sundials/sundials_smalldense.h
            include/sundials/sundials_spbcgs.h
            include/sundials/sundials_spgmr.h
            include/sundials/sundials_sptfqmr.h
            include/sundials/sundials_types.h
            )

add_library(sundials
            wormsim.cpp
            src/ida/ida.c
            src/ida/ida_band.c
            src/ida/ida_band_impl.h
            src/ida/ida_bbdpre.c
            src/ida/ida_bbdpre_impl.h
            src/ida/ida_dense.c
            src/ida/ida_dense_impl.h
            src/ida/ida_ic.c
            src/ida/ida_impl.h
            src/ida/ida_io.c
            src/ida/ida_spbcgs.c
            src/ida/ida_spgmr.c
            src/ida/ida_spils.c
            src/ida/ida_spils_impl.h
            src/ida/ida_sptfqmr.c
            src/nvec_ser/fnvector_serial.c
            src/nvec_ser/fnvector_serial.h
            src/nvec_ser/nvector_serial.c
            src/sundials/sundials_band.c
            src/sundials/sundials_config.h
            src/sundials/sundials_config.in
            src/sundials/sundials_dense.c
            src/sundials/sundials_iterative.c
            src/sundials/sundials_math.c
            src/sundials/sundials_nvector.c
            src/sundials/sundials_smalldense.c
            src/sundials/sundials_spbcgs.c
            src/sundials/sundials_spgmr.c
            src/sundials/sundials_sptfqmr.c
            )

# # add lib dependencies
# target_link_libraries(wormworx_jni
#                       android
#                       log 
#                       EGL
#                       GLESv2)

