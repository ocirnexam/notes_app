#include "database.h"

static sqlite3 *db;

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
        char* sql = sqlite3_mprintf("INSERT INTO NOTES (ID, TITLE, CONTENT) VALUES (%q, %q, %q);", note.id, note.title, note.content);
        if(sqlite3_exec(db, sql, NULL, NULL, NULL)) {
                sqlite3_free(sql);
                return DB_EXEC_ERROR;
        }
        sqlite3_free(sql);
        return DB_SUCCESS;
}

//----------------------------------------------------
Note get_note(int id)
{
        sqlite3_stmt* stmt = NULL;
        Note note;
        char* sql = sqlite3_mprintf("SELECT ID, TITLE, CONTENT FROM NOTES WHERE ID = %q;", id);
        if(sqlite3_prepare_v2(db, sql, -1, &stmt, 0)) {
                sqlite3_free(sql);
                return note;
        }
        if(sqlite3_step(stmt) == SQLITE_ROW) {
                note.id = (int) sqlite3_column_int(stmt, 0);
                note.title = (char *) sqlite3_column_text(stmt, 1);
                note.content = (char *) sqlite3_column_text(stmt, 2);
        }
        sqlite3_finalize(stmt);
        sqlite3_free(sql);
        return note;
}

//----------------------------------------------------
Note* get_all_notes(void)
{

}
