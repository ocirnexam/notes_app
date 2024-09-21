#include "database.h"

static sqlite3_stmt* stmt = NULL;
static sqlite3 *db = NULL;

//----------------------------------------------------
uint8_t create_database(char* filename)
{
        const char sql[] = "CREATE TABLE IF NOT EXISTS NOTES("  
                           "ID INT PRIMARY        KEY      NOT NULL," 
                           "TITLE                 TEXT     NOT NULL," 
                           "CONTENT               TEXT     NOT NULL);";
        if(sqlite3_open(filename, &db)) {
                return DB_OPEN_ERROR;
        }
        if(sqlite3_exec(db, sql, NULL, NULL, NULL)) {
                return DB_EXEC_ERROR;
        }
        return DB_SUCCESS;
}

//----------------------------------------------------
uint8_t close_database(void)
{
        if(db) {
                sqlite3_close(db);
        }
        return 0;
}

//----------------------------------------------------
uint8_t insert_note(Note note)
{
        if(sqlite3_prepare_v2(db, "INSERT INTO NOTES VALUES (?1, ?2, ?3);", -1, &stmt, 0)) {
                return DB_EXEC_ERROR;
        }
        sqlite3_bind_int(stmt, 1, note.id);
        sqlite3_bind_text(stmt, 2, note.title, -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, note.content, -1, SQLITE_TRANSIENT);

        if(sqlite3_step(stmt) == SQLITE_DONE) {
                return DB_SUCCESS;
        }
        sqlite3_finalize(stmt);
        return DB_EXEC_ERROR;
}

//----------------------------------------------------
Note* get_note(int id)
{
        Note* note = malloc(sizeof(Note));
        if(!note) {
                return NULL;
        }
        if(sqlite3_prepare_v2(db, "SELECT ID, TITLE, CONTENT FROM NOTES WHERE ID=?1;", -1, &stmt, 0)) {
                return NULL;
        }
        sqlite3_bind_int(stmt, 1, id);
        if(sqlite3_step(stmt) == SQLITE_ROW) {
                note->id = (int) sqlite3_column_int(stmt, 0);
                strncpy(note->title, (char *) sqlite3_column_text(stmt, 1), NOTE_TITLE_MAX);
                strncpy(note->content, (char *) sqlite3_column_text(stmt, 2), NOTE_CONTENT_MAX);
                return note;
        }
        sqlite3_finalize(stmt);
        return NULL;
}

//----------------------------------------------------
linked_list get_all_notes(void)
{
        
        if(sqlite3_prepare_v2(db, "SELECT ID, TITLE, CONTENT FROM NOTES;", -1, &stmt, 0)) {
                return NULL;
        }
        linked_list list = linked_list_create();
        while(sqlite3_step(stmt) == SQLITE_ROW) {
                Note* note = malloc(sizeof(Note));
                if(note == NULL) {
                        linked_list_free(list);
                        return NULL;
                }
                note->id = (int) sqlite3_column_int(stmt, 0);
                strncpy(note->title, (char *) sqlite3_column_text(stmt, 1), NOTE_TITLE_MAX);
                strncpy(note->content, (char *) sqlite3_column_text(stmt, 2), NOTE_CONTENT_MAX);
                list = linked_list_add(list, note);
        }
        sqlite3_finalize(stmt);
        return list;
}
