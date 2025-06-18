cmake_minimum_required(VERSION 3.5)

project(06.homework)

add_executable(containers main.cpp)

# clang-format
find_program(CLANG-FORMAT_PATH NAMES clang-format REQUIRED)
message(STATUS "Найден clang-format: ${CLANG-FORMAT_PATH}")
file(GLOB_RECURSE CLANG-FORMAT_SRC CONFIGURE_DEPENDS *.*pp)
add_custom_target(clangformat
    COMMAND ${CLANG-FORMAT_PATH} -i ${CLANG-FORMAT_SRC}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Форматирование ${PROJECT_NAME} с ${CLANG-FORMAT_PATH}"
)
add_dependencies(containers clangformat)

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_compile_options(containers PRIVATE
    -Wall
    -Wextra
    -pedantic
    -Werror
    -fsanitize=address # only for debug and test builds!
)
target_link_options(containers PRIVATE
    -fsanitize=address
)

