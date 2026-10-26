#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

void initialize(Settings *someSettings)
{
    someSettings->m_compiler = strup("gcc ");
    someSettings->m_count_cflags = 6;
    someSettings->m_cflags = malloc(someSettings->m_count_cflags * sizeof(char*));
    if (someSettings->m_cflags == NULL)
    {
        printf("Could not allocate enough memory!\nSettings are not setup!\n");
        return;
    }

    someSettings->m_cflags[0] = strdup("-Wall ");
    someSettings->m_cflags[1] = strdup("-Wextra ");
    someSettings->m_cflags[2] = strdup("-Wpedantic ");
    someSettings->m_cflags[3] = strdup("-std=c17 ");
    someSettings->m_cflags[4] = strdup("-MMD ");
    someSettings->m_cflags[5] = strdup("-MP ");

    someSettings->m_target = strdup("program");
    someSettings->m_build_dir = strdup("build");
}

void createMake(const Settings *someSettings)
{
    
}

void clearMemory(Settings *someSettingsToClear)
{
    free(someSettingsToClear->m_compiler);

    int count = someSettingsToClear->m_count_cflags;
    for (int i = 0; i < count; i++)
    {
        free(someSettingsToClear->m_cflags[i]);
    }
    free(someSettingsToClear->m_cflags);

    free(someSettingsToClear->m_target);
    free(someSettingsToClear->m_build_dir);
}