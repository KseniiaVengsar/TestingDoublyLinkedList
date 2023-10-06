cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
project(MyProject)

add_executable(cmake_exe ./TestingDoublyLinkedList/TestingDoublyLinkedList.cpp)

add_subdirectory(./Catch2 Catch2-build)
#собираем второй exe файл здесь
add_executable(Test ./TestingDoublyLinkedList/Testfile.cpp ./TestingDoublyLinkedList/TestingDoublyLinkedList.cpp)
target_link_libraries(Test PRIVATE Catch2::Catch2)
