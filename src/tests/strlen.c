#include "libasm.h"

void test_strlen(void) {
    const char *str1 = "test 1";
    const char *str2 = "";
    const char *str3 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \
        sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim \
        ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip \
        ex ea commodo consequat. Duis aute irure dolor in reprehenderit in \
        voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur \
        sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt \
        mollit anim id est laborum.";
    size_t custom_result = 0;
    size_t original_result = 0;
    int errno_cpy = -1;
    size_t nb_test = 1;

    printf(BLUE "       - [ strlen / ft_strlen ] -\n" RESET);
    printf("----------------------------------------------------------------------------------------------------\n");
    // TEST 1
    errno = -1;
    original_result = strlen(str1);
    errno = errno_cpy;
    custom_result = ft_strlen(str1);
    if (custom_result == original_result)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Small string\n" RESET);
    nb_test++;

    // TEST 2
    errno = -1;
    errno_cpy = -1;
    original_result = strlen(str2);
    errno_cpy = errno;
    custom_result = ft_strlen(str2);
    if (custom_result == original_result)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Empty string\n" RESET);
    nb_test++;

    // TEST 3
    errno = -1;
    errno_cpy = -1;
    original_result = strlen(str3);
    errno_cpy = errno;
    custom_result = ft_strlen(str3);
    if (custom_result == original_result)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Big text\n" RESET);
    nb_test++;
    printf("\n");
}
