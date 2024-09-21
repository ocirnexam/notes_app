#include <stdio.h>
#include "database/database.h"

int main(int argc, char* argv[])
{
        Note note = {.id = 1, .title = "Note 1", .content = "A fresh note stored in db"};
        Note* note2;
        if(!create_database("/usr/share/notes/notes.db")) {
                insert_note(note);
                note2 = get_note(1);
                if (note2) {
                        printf("ID: %d\nTITLE: %s\nCONTENT: %s\n", note2->id, note2->title, note2->content);
                        free(note2);
                }
                close_database();
                return 0;
        }
        return 1;
}
