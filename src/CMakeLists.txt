include_directories(${GlobalSign_SOURCE_DIR}/lib/include)
add_executable(top_20 main.cpp)
target_link_libraries(top_20 treap ${CONAN_LIBS})