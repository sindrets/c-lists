#include "arraylist_test.h"
#include "clonelist_test.h"
#include "test.h"

int main(int argc, char const *argv[])
{
    arraylist_test();
    clonelist_test();

    return test_summary() ? 0 : 1;
}
