#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/greet.h"
#include <stdio.h>
#include <string.h>

// Test function for greet
void test_greet(void) {
    FILE *fp;
    char output[100];

    // Redirect stdout to a file
    fp = freopen("output.txt", "w", stdout);
    if (fp == NULL) {
        CU_FAIL("Failed to redirect stdout.");
        return;
    }

    // Call the greet function
    greet("Test");

    // Restore stdout and close file
    freopen("/dev/tty", "w", stdout);
    fclose(fp);

    // Read the output from the file
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        CU_FAIL("Failed to open output file.");
        return;
    }
    fgets(output, sizeof(output), fp);
    fclose(fp);

    // Check if the output is correct
    CU_ASSERT_STRING_EQUAL(output, "Hello, Test!\n");
}

// Register and run the test suite
int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("GreetTestSuite", 0, 0);

    CU_add_test(suite, "test of greet()", test_greet);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
