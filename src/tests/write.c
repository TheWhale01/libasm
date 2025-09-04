#include "libasm.h"

void test_write(void) {
    const int wrong_fd = 15;
    const char *str = "Ceci est un test !\n";
    int read_size = 10;
    int original_result = -1;
    int custom_result = -1;
    int errno_cpy = -1;
    size_t nb_test = 1;

    errno = -1;
    printf(BLUE "       - [ write / ft_write ] -\n" RESET);
    printf("----------------------------------------------------------------------------------------------------\n");
    // TEST 1
    original_result = write(STDOUT_FILENO, str, strlen(str));
    errno_cpy = errno;
    custom_result = ft_write(STDOUT_FILENO, str, ft_strlen(str));
    if (original_result == custom_result && custom_result != -1
            && original_result != -1 && errno == -1 && errno_cpy == -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Writting to stdout\n" RESET);
    nb_test++;

    // TEST 2
    original_result = write(wrong_fd, str, read_size);
    errno_cpy = errno;
    custom_result = ft_write(wrong_fd, str, read_size);
    if (errno == errno_cpy && original_result == custom_result && custom_result == -1
            && original_result == -1 && errno != -1 && errno_cpy != -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Wrong FD\n" RESET);
    nb_test++;

    // TEST 3
    original_result = write(STDOUT_FILENO, NULL, read_size);
    errno_cpy = errno;
    custom_result = ft_write(STDOUT_FILENO, NULL, read_size);
    if (errno == errno_cpy && original_result == custom_result && custom_result == -1
            && original_result == -1 && errno != -1 && errno_cpy != -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Wrong buffer\n" RESET);
    nb_test++;
    printf("\n");
}
