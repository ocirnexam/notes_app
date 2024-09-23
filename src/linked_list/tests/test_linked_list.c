#include <string.h>

#include "unity.h"
#include "linked_list/linked_list.h"


Note* note1 = NULL;
Note* note2 = NULL;

void setUp()
{
    note1 = (Note*) malloc(sizeof(Note));
    note2 = (Note*) malloc(sizeof(Note));
    note1->id = 1;
    strncpy(note1->title,"Title1", NOTE_TITLE_MAX);
    strncpy(note1->content, "Content1", NOTE_CONTENT_MAX);
    note2->id = 2;
    strncpy(note2->title,"Title2", NOTE_TITLE_MAX);
    strncpy(note2->content, "Content2", NOTE_CONTENT_MAX);
}

void tearDown()
{

}

void test_create_linked_list()
{
    linked_list list = linked_list_create();
    TEST_ASSERT_NOT_EQUAL(NULL, list);
    if(list) {
        free(list);
    }
}

void test_add_list_entry()
{
    linked_list list = linked_list_create();
    linked_list next = NULL;

    list = linked_list_add(list, note1);
    TEST_ASSERT_EQUAL(note1, list->note);

    list = linked_list_add(list, note2);
    TEST_ASSERT_EQUAL(note2, list->note);

    next = list->next;
    free(list);
    free(next);
}

void test_linked_list_free()
{
    linked_list list = linked_list_create();
    list = linked_list_add(list, note1);
    list = linked_list_add(list, note2);

    TEST_ASSERT_NOT_EQUAL(NULL, list);
    TEST_ASSERT_NOT_EQUAL(NULL, list->next);

    uint32_t freed_item_count = linked_list_free(&list);
    TEST_ASSERT_EQUAL_UINT32(2, freed_item_count);


}

int main(void)
{
    UNITY_BEGIN();

    // TESTS
    RUN_TEST(test_create_linked_list);
    RUN_TEST(test_add_list_entry);
    RUN_TEST(test_linked_list_free);

    UNITY_END();
    return 0;
}