cmake_minimum_required (VERSION 2.8)
project (UniCAP)


INCLUDE_DIRECTORIES(/usr/local/include)
#link_directories(/usr/local/lib)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++11")

FIND_LIBRARY(libthrift thrift /usr/local/lib)
IF(NOT libthrift)
MESSAGE(FATAL_ERROR “libthrift not found”)
ENDIF(NOT libthrift)
MESSAGE(--${libthrift})


FIND_LIBRARY(libglog glog /usr/local/lib)
IF(NOT libglog)
MESSAGE(FATAL_ERROR “libglog not found”)
ENDIF(NOT libglog)
MESSAGE(--${libglog})


FIND_LIBRARY(libleveldb leveldb /usr/local/lib)
IF(NOT libleveldb)
MESSAGE(FATAL_ERROR “libleveldb not found”)
ENDIF(NOT libleveldb)
MESSAGE(--${libleveldb})

FIND_PACKAGE( Boost 1.40 COMPONENTS system filesystem thread REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
MESSAGE(--${Boost_LIBRARIES})

add_subdirectory(gen)
add_subdirectory(computing)
add_subdirectory(job_tracker)

add_executable(UniCAPMaster, job_tracker.cpp)
target_link_libraries(UniCAPMaster, Gen, Computing, JobTracker, ${Boost_LIBRARIES}, ${libthrift}, ${libglog}, ${libleveldb})
#target_link_libraries(UniCAPMaster, glog, thrift, leveldb, boost_filesystem, boost_system, boost_thread-mt, Gen, Computing, JobTracker)
