cmake_minimum_required(VERSION 3.28)
project("Notes app with web server")


add_executable(notes src/main.c 
                     src/database/database.c 
                     src/linked_list/linked_list.c)
target_link_libraries(notes sqlite3)
target_include_directories(notes PUBLIC src)
target_include_directories(notes PUBLIC src/database)
target_include_directories(notes PUBLIC src/linked_list)
target_include_directories(notes PUBLIC src/note)
