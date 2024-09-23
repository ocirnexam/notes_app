#include <stdio.h>
#include "database/database.h"

int main(int argc, char* argv[])
{
        Note note1 = {.id = 1, .title = "Note 1", .content = "A fresh note stored in db"};
        Note note2 = {.id = 2, .title = "Note 2", .content = "Hallo"};
        Note note3 = {.id = 3, .title = "Note 3", .content = "Servus, Max"};
        Note* note;
        linked_list notes;

        if(!db_create("/usr/share/notes/notes.db")) {
                db_insert(note1);
                db_insert(note2);
                db_insert(note3);
                note = db_get(2);
                if (note) {
                        printf("ID: %d\nTITLE: %s\nCONTENT: %s\n", note->id, note->title, note->content);
                        free(note);
                }
                printf("\n\nPrint all notes:\n\n");
                db_delete(2);
                notes = db_get_all();
                linked_list_print(notes);
                linked_list_free(&notes);
                db_close();
                return 0;
        }
        return 1;
}
