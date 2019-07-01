#include "../src/welcome.h"
#include <gtest/gtest.h>
#include <QApplication>

/** @brief  Global int for argc argument from the main() function.
 *          This is later used in the tests cases.
 */
static int t_argc;
/** @brief  Global char** for argv argument from the main() function.
 *          This is later used in the tests cases.
 */
static char **t_argv;

/**
 * @brief   Test the behavior of a welcome window. The tests runs so that
 *          it opens up a welcome window and then waits for the user to close it.
 *          If the user close it with exit code zero
 *          (uses not forceful closing) then the test case hase passed.
 */
TEST(WelcomeScreenTestCases, WelcomeScreenTest) {

    int rc;

    fprintf(stderr, "\nRUNNING WELCOME SCREEN TEST\n");
    QApplication a(t_argc, t_argv);
    Welcome w;
    w.setNextWindow();
    w.show();

    rc = a.exec();
    fprintf(stderr, "\nDONE\n");
    EXPECT_EQ(rc, 0);
}

int main(int argc, char* argv[]){

    t_argc = argc;
    t_argv = argv;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
