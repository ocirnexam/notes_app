cmake_minimum_required(VERSION 3.28)
project("Notes app with web server")


add_executable(notes src/main.c src/database/database.c)
target_link_libraries(notes sqlite3)
target_include_directories(notes PUBLIC src)
target_include_directories(notes PUBLIC src/database)
