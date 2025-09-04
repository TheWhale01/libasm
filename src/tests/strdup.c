#include "libasm.h"

void test_strdup(void) {
    const char *str1 = "test 1";
    const char *str2 = "";
    const char *str3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
        sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim \
        ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip \
        ex ea commodo consequat. Duis aute irure dolor in reprehenderit in \
        voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur \
        sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt \
        mollit anim id est laborum.";
    char *original_result = NULL;
    char *custom_result = NULL;
    int errno_cpy = -1;
    size_t nb_test = 1;

    printf(BLUE "       - [ strdup / ft_strdup ] -\n" RESET);
    printf("----------------------------------------------------------------------------------------------------\n");
    // TEST 1
    errno = -1;
    original_result = strdup(str1);
    errno = errno_cpy;
    custom_result = ft_strdup(str1);
    if (!strcmp(original_result, custom_result) && errno == -1 && errno_cpy == -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Equal strings\n" RESET);
    free(custom_result);
    free(original_result);
    custom_result = NULL;
    original_result = NULL;
    nb_test++;

    // TEST 2
    errno = -1;
    errno_cpy = -1;
    original_result = strdup(str2);
    errno_cpy = errno;
    custom_result = ft_strdup(str2);
    if (!strcmp(original_result, custom_result) && errno == -1 && errno_cpy == -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Empty string\n" RESET);
    free(custom_result);
    free(original_result);
    custom_result = NULL;
    original_result = NULL;
    nb_test++;

    // TEST 3
    errno = -1;
    errno_cpy = -1;
    original_result = strdup(str3);
    errno_cpy = errno;
    custom_result = ft_strdup(str3);
    if (!strcmp(original_result, custom_result) && errno == -1 && errno_cpy == -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Big text\n" RESET);
    free(custom_result);
    free(original_result);
    custom_result = NULL;
    original_result = NULL;
    nb_test++;
}
