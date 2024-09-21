#include <stdio.h>
#include "database/database.h"

int main(int argc, char* argv[])
{
        Note note1 = {.id = 1, .title = "Note 1", .content = "A fresh note stored in db"};
        Note note2 = {.id = 2, .title = "Note 2", .content = "Hallo"};
        Note note3 = {.id = 3, .title = "Note 3", .content = "Servus, Max"};
        Note* note;
        linked_list notes;

        if(!create_database("/usr/share/notes/notes.db")) {
                insert_note(note1);
                insert_note(note2);
                insert_note(note3);
                note = get_note(2);
                if (note) {
                        printf("ID: %d\nTITLE: %s\nCONTENT: %s\n", note->id, note->title, note->content);
                        free(note);
                }
                notes = get_all_notes();
                linked_list_print(notes);
                linked_list_free(notes);
                close_database();
                return 0;
        }
        return 1;
}
