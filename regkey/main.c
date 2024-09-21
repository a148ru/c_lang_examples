#include <stdio.h>
#include "regkey.h"

int main(int argc, char* argv[])
{
    RegKey my_key = createKey("myKey");
    storeValue(my_key, "A");
    publishKey(my_key);
    return 0;
}