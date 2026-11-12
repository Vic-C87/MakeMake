#ifndef APP_H
#define APP_H

typedef struct
{
    char *m_filepath;
    char *m_compiler;
    char *m_language;
    char **m_cflags;
    char **m_ldflags;
    char **m_ldlibs;
    char *m_target;
    char *m_src_dir;
    char *m_build_dir;
    int m_count_cflags;
    int m_count_ldflags;
    int m_count_ldlibs;
} Settings;

void print_menu();

void print_edit_menu();

void initialize_basic(Settings *someSettings);

void display_makefile(Settings *someSettings);

void edit_makefile(Settings *someSettings);

void set_compiler(Settings *someSettings, char *aCompiler);

void set_language(Settings *someSettings, char *aLanguage);

void set_path(Settings *someSettings, char *aPath);

void createMake(const Settings *someSettings);

void clearMemory(Settings *someSettingsToClear);

char *salloc(const char *someText);

char *get_flags(char **an_array, int aLength);

#endif