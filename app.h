#ifndef APP_H
#define APP_H

typedef struct
{
    int m_count_cflags;
    char *m_compiler;
    char **m_cflags;
    char *m_target;
    char *m_build_dir;
} Settings;

typedef struct
{
    char **m_lines;
} MakeData;

void initialize(Settings *someSettings);

void createMake(const Settings *someSettings);

void clearMemory(Settings *someSettingsToClear);

char *salloc(const char *someText);

#endif