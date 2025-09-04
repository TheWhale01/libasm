#include "libasm.h"

void test_strcmp(void) {
    const char *str1 = "test 1";
    const char *str2 = "test 1";
    const char *str3 = "test 4";
    const char *str4 = "test  ";
    int custom_result = -1;
    int original_result = -1;
    size_t nb_test = 1;

    printf(BLUE "       - [ strcmp / ft_strcmp ] -\n" RESET);
    printf("----------------------------------------------------------------------------------------------------\n");
    // TEST 1
    original_result = strcmp(str1, str2);
    custom_result = ft_strcmp(str1, str2);
    if (custom_result == original_result)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Equal strings\n" RESET);
    nb_test++;

    // TEST 2
    original_result = strcmp(str1, str3);
    custom_result = ft_strcmp(str1, str3);
    if (custom_result < 0 && original_result < 0)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Negative result\n" RESET);
    nb_test++;

    // TEST 3
    original_result = strcmp(str1, str4);
    custom_result = ft_strcmp(str1, str4);
    if (custom_result > 0 && original_result > 0)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Positive result\n" RESET);
    nb_test++;
    printf("\n");
}
