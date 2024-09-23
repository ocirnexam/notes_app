cmake_minimum_required(VERSION 3.28)
project("Notes app with web server")

include(CTest)


add_executable(notes src/main.c 
                     src/database/database.c 
                     src/linked_list/linked_list.c)
target_link_libraries(notes sqlite3)
target_include_directories(notes PUBLIC src)
target_include_directories(notes PUBLIC src/database)
target_include_directories(notes PUBLIC src/linked_list)
target_include_directories(notes PUBLIC src/note)

add_subdirectory(src/Unity)

add_executable(test_linked_list src/linked_list/tests/test_linked_list.c
                                src/linked_list/linked_list.c)
target_link_libraries(test_linked_list unity)
target_include_directories(test_linked_list PUBLIC src/linked_list)
target_include_directories(test_linked_list PUBLIC src/Unity)
target_include_directories(test_linked_list PUBLIC src)

add_test(NAME test_linked_list COMMAND test_linked_list)
