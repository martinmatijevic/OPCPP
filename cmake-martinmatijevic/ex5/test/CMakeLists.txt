add_executable("testData" test.cpp ../src/data.cpp)
target_link_libraries("testData"  googletest pthread)

add_test(NAME testData COMMAND testData)
