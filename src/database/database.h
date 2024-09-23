#ifndef DATABASE_H_INLCUDED
#define DATABASE_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sqlite3.h>

#include "note/note.h"
#include "linked_list/linked_list.h"

#define DB_OPEN_ERROR 1
#define DB_EXEC_ERROR 2
#define DB_SUCCESS 0

/*
 * Creates a sqlite database, if there is no existing one, else opens it
  * @param filename: char *
 */
uint8_t db_create(char *);

/*
 * Closes a sqlite database
 */
uint8_t db_close(void);

/*
 * Inserts a note into the database
 * @param note: Note
 */
uint8_t db_insert(Note);

/*
 * Deletes a Note in the database
 * @param id: int
*/
uint8_t db_delete(int);

/*
 * Returns a note based on the ID
 * @param id: int
 */
Note* db_get(int);

/*
 * Returns all notes found in the database
 */
linked_list db_get_all(void);

#endif
