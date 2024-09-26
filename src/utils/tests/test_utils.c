#include <string.h>

#include "unity.h"
#include "utils.h"

void setUp()
{

}

void tearDown()
{

}

void test_is_number()
{
    char* string = "12345";
    uint8_t result = is_number(string);
    TEST_ASSERT_EQUAL_UINT8(TRUE, result);
}

int main(void)
{
    UNITY_BEGIN();

    // TESTS
    RUN_TEST(test_is_number);

    UNITY_END();
    return 0;
}