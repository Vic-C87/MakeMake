#ifndef APP_H
#define APP_H

typedef struct
{
    char *m_filepath;
    char *m_compiler;
    char **m_cflags;
    char *m_target;
    char *m_src_dir;
    char *m_build_dir;
    int m_count_cflags;
} Settings;

void print_menu();

void initialize_basic(Settings *someSettings);

void set_path(Settings *someSettings, char *aPath);

void createMake(const Settings *someSettings);

void clearMemory(Settings *someSettingsToClear);

char *salloc(const char *someText);

#endif