#ifndef DATABASE_H_INLCUDED
#define DATABASE_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sqlite3.h>

#define DB_OPEN_ERROR 1
#define DB_EXEC_ERROR 2
#define DB_SUCCESS 0

typedef struct {
        int id;
        char* title;
        char* content;
} Note;

/*
 * Creates a sqlite database, if there is no existing one, else opens it
  * @param filename: char *
 */
uint8_t create_database(char *);

/*
 * Closes a sqlite database
 */
uint8_t close_database(void);

/*
 * Inserts a note into the database
 * @param note: Note
 */
uint8_t insert_note(Note);

/*
 * Returns a note based on the ID
 * @param id: int
 */
Note* get_note(int);

/*
 * Returns all notes found in the database
 */
Note* get_all_notes(void);

#endif
