#include "fcntl.h"
#include "libasm.h"

void test_read(void) {
    const char *filename = "test.txt";
    const int buff_size = 100;
    const int wrong_fd = 15;
    int fd = open(filename, O_RDONLY);
    int read_size = 10;
    int original_result = -1;
    int custom_result = -1;
    int errno_cpy = -1;
    char original_buff[buff_size];
    char custom_buff[buff_size];
    size_t nb_test = 1;

    errno = -1;
    bzero(custom_buff, buff_size);
    bzero(original_buff, buff_size);
    printf(BLUE "       - [ read / ft_read ] -\n" RESET);
    printf("----------------------------------------------------------------------------------------------------\n");
    // TEST 1
    original_result = read(fd, original_buff, read_size);
    errno_cpy = errno;
    close(fd);
    fd = open(filename, O_RDONLY);
    custom_result = ft_read(fd, custom_buff, read_size);
    close(fd);
    if (!strcmp(custom_buff, original_buff) && original_result == custom_result
            && custom_result != -1 && original_result != -1 && errno == -1
            && errno_cpy == -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Reading a file\n" RESET);
    nb_test++;

    // TEST 2
    original_result = read(wrong_fd, original_buff, read_size);
    errno_cpy = errno;
    custom_result = ft_read(wrong_fd, custom_buff, read_size);
    if (errno == errno_cpy && original_result == custom_result && custom_result == -1
            && original_result == -1 && errno != -1 && errno_cpy != -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Wrong FD\n" RESET);
    nb_test++;

    // TEST 3
    fd = open(filename, O_RDONLY);
    original_result = read(fd, NULL, read_size);
    close(fd);
    errno_cpy = errno;
    fd = open(filename, O_RDONLY);
    custom_result = ft_read(fd, NULL, read_size);
    close(fd);
    if (errno == errno_cpy && original_result == custom_result && custom_result == -1
            && original_result == -1 && errno != -1 && errno_cpy != -1)
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Wrong buffer\n" RESET);
    nb_test++;
    printf("\n");
}
