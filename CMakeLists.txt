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

file(GLOB LIB_SRCS "${SOURCE}/*.cpp")
file(GLOB LIB_INCLUDE "${INCLUDE}/*.h")
add_library(${LIBRARY} STATIC ${LIB_SRCS} ${LIB_INCLUDE})
target_include_directories(${LIBRARY} PUBLIC ${INCLUDE})


add_subdirectory(parser)
add_subdirectory(samples)
add_subdirectory(test)


target_link_libraries(${LIBRARY} PUBLIC parser_generated)

set_property(GLOBAL PROPERTY EXPR_INCLUDEDIR ${INCLUDE})
set_property(GLOBAL PROPERTY EXPR_ANTLR_INCLUDE ${ANTLR_INCLUDE_DIR})
set_property(GLOBAL PROPERTY EXPR_ANTLR_LIB ${ANTLR_LIB})