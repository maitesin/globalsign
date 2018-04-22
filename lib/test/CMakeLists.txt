include_directories(${GlobalSign_SOURCE_DIR}/lib/include)
add_executable(treap_test treap.cpp)
target_link_libraries(treap_test treap ${CONAN_LIBS})
add_test(NAME treap
         COMMAND ./bin/treap_test)