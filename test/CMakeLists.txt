
set(target ${TESTS})

file(GLOB TEST_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${target} ${TEST_SRCS})

target_include_directories(${target} PRIVATE ${INCLUDE})
target_link_libraries(${target} PRIVATE GTest::gtest ${LIBRARY})