#include "libasm.h"

void test_strcpy(void) {
    const int buffer_size = 100;
    const char *str1 = "Ceci est un test !\n";
    const char *str2 = "";
    const char *str3 = "\n";
    char custom_buff[buffer_size];
    char original_buff[buffer_size];
    char *custom_result = NULL;
    char *original_result = NULL;
    size_t nb_test = 1;

    memset(original_buff, 1, buffer_size);
    memset(custom_buff, 1, buffer_size);
    printf(BLUE "       - [ strcpy / ft_strcpy ] -\n" RESET);
    printf("----------------------------------------------------------------------------------------------------\n");
    // TEST 1
    original_result = strcpy(original_buff, str1);
    custom_result = ft_strcpy(custom_buff, str1);
    if (!strcmp(original_buff, custom_buff) && !strcmp(original_result, custom_result))
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Plain string\n" RESET);
    nb_test++;

    // TEST 2
    memset(original_buff, 1, buffer_size);
    memset(custom_buff, 1, buffer_size);
    original_result = strcpy(original_buff, str2);
    custom_result = ft_strcpy(custom_buff, str2);
    if (!strcmp(original_buff, custom_buff) && !strcmp(original_result, custom_result))
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Empty string\n" RESET);
    nb_test++;

    // TEST 3
    memset(original_buff, 1, buffer_size);
    memset(custom_buff, 1, buffer_size);
    original_result = strcpy(original_buff, str3);
    custom_result = ft_strcpy(custom_buff, str3);
    if (!strcmp(original_buff, custom_buff) && !strcmp(original_result, custom_result))
        printf(GREEN "TEST %ld: PASSED" RESET, nb_test);
    else
        printf(RED "TEST %ld: FAILED" RESET, nb_test);
    printf(YELLOW " - Only line feed\n" RESET);
    nb_test++;
    printf("\n");
}
