cmake_minimum_required(VERSION 3.16)

project(lab_01)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror --coverage -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror --coverage -g")


set(LIB_SOURCE_FILES project/src/mail.c)
add_library(mail STATIC ${LIB_SOURCE_FILES})

add_executable(main project/src/main.c)
target_link_libraries(main mail)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(mail_test tests/mail_test.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
target_link_libraries(mail_test ${GTEST_LIBRARIES} mail gcov)
