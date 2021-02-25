add_executable(
        cpp-test
        main.cpp
        solution.test.cpp
        world.test.cpp
        hugo/solver.test.cpp
)

target_include_directories(
        cpp-test PUBLIC
        ../googletest/googletest/include
        ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(cpp-test PUBLIC gtest)