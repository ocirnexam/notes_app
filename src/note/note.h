#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#define NOTE_TITLE_MAX 50
#define NOTE_CONTENT_MAX 1024

typedef struct {
        int id;
        char title[NOTE_TITLE_MAX];
        char content[NOTE_CONTENT_MAX];
} Note;

#endif