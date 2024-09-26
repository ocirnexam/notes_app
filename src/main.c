#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "database/database.h"

int main(int argc, char* argv[])
{
        Note* note;
        Note insert_note;
        linked_list notes;

        if(!db_create("/usr/share/notes/notes.db")) {
                if (argc == 2 && !strncmp(argv[1], "--list-all", strlen(argv[1]))) {
                        notes = db_get_all();
                        linked_list_print(notes);
                        linked_list_free(&notes);
                } else if (argc == 3 && !strncmp(argv[1], "--get", strlen(argv[1]))) {
                        if(is_number(argv[2]) == TRUE) {
                                note = db_get(atoi(argv[2]));
                                if (note) {
                                        printf("NOTE\n-----------------------------\n%s\n-----------------------------\n\n%s\n", note->title, note->content);
                                        free(note);
                                }
                        } 
                } else if (argc == 3 && !strncmp(argv[1], "--delete", strlen(argv[1]))) {
                        if(is_number(argv[2]) == TRUE) {
                                int id = atoi(argv[2]);
                                uint8_t result = db_delete(id);
                                if (result == DB_SUCCESS) {
                                        printf("Note with ID: %d successfully deleted!\n", id);
                                } else {
                                        printf("ERROR %d: Deleting Note with ID %d failed!\n", result, id);
                                }
                        } 
                } else if (argc == 5 && !strncmp(argv[1], "--add", strlen(argv[1])) && is_number(argv[2]) == TRUE) {
                        int id = atoi(argv[2]);
                        insert_note.id = id;
                        strncpy(insert_note.title, argv[3], NOTE_TITLE_MAX);
                        strncpy(insert_note.content, argv[4], NOTE_CONTENT_MAX);
                        uint8_t result = db_insert(insert_note);
                        if(result == DB_SUCCESS) {
                                printf("Note with ID: %d successfully created!\n", id);
                        } else {
                                printf("ERROR %d: Creating Note with ID %d failed!\n", result, id);
                        }
                }
                db_close();
                return 0;
        }
        return 1;
}
