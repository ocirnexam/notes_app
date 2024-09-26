#include "utils.h"

uint8_t is_number(char* string)
{
    for(int i = 0; i < strlen(string); i++) {
        if(!isdigit(string[i])) {
            return FALSE;
        }
    }
    return TRUE;
}