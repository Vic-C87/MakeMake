#include "app.h"

int main(void)
{
    Settings settings;

    initialize(&settings);
    createMake(&settings);
    clearMemory(&settings);

    return 0;
}