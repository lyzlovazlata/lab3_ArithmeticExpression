
set(PARSER_GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
file(GLOB PARSER_SRCS "${PARSER_GEN_DIR}/*.cpp")

add_library(parser_generated STATIC ${PARSER_SRCS})
target_include_directories(parser_generated
    PUBLIC
        ${PARSER_GEN_DIR}
        ${ANTLR_INSTALL_DIR}/include/antlr4-runtime
)

target_link_libraries(parser_generated
    PUBLIC
        ${ANTLR_INSTALL_DIR}/lib/antlr4-runtime.lib
)
