
set(target sample)

file(GLOB SAMPLE_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${target} ${SAMPLE_SRCS})

target_include_directories(${target} PRIVATE ${INCLUDE})

target_link_libraries(${target} PRIVATE ${LIBRARY})