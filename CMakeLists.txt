cmake_minimum_required(VERSION 3.15)
project(Arith LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


#путь к ANTLR runtime
# через ключ -d
set(ANTLR_INSTALL_DIR
    "C:/Users/Zlata/source/ANTLR/antlr_install"
    CACHE PATH "Path to ANTLR C++ runtime installation (contains include/, lib/, bin/)"
)

set(LIBRARY "${PROJECT_NAME}")
set(INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE  "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TESTS   "test_${PROJECT_NAME}")

# гугл тесты фетчу
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(parser)
file(GLOB LIB_SRCS "${SOURCE}/*.cpp")
file(GLOB LIB_INCLUDE "${INCLUDE}/*.h")
add_library(${LIBRARY} STATIC ${LIB_SRCS} ${LIB_INCLUDE})
target_include_directories(${LIBRARY} PUBLIC ${INCLUDE})
target_link_libraries(${LIBRARY} PUBLIC parser_generated)

add_subdirectory(samples)
add_subdirectory(test)


get_target_property(LIB_LOCATION ${LIBRARY} ARCHIVE_OUTPUT_DIRECTORY)
message(STATUS "Library output dir: ${LIBRARY} -> ${LIB_LOCATION}")