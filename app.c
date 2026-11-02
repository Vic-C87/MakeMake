#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"

void print_menu()
{
    printf("\n-Menu--:\n");
    printf("1. Makemake!\n");
    printf("2. Display Makefile\n");
    printf("3. Set main path\n");
    printf("4. Edit Makefile\n");
    printf("0. Exit application\n");
    printf("Enter a menu choice:> ");
}

void initialize_basic(Settings *someSettings)
{
    someSettings->m_filepath = salloc("Makefile");
    someSettings->m_compiler = salloc("gcc ");
    someSettings->m_count_cflags = 6;
    someSettings->m_cflags = malloc(someSettings->m_count_cflags * sizeof(char*));
    if (someSettings->m_cflags == NULL)
    {
        printf("Could not allocate enough memory!\nSettings are not setup!\n");
        return;
    }

    someSettings->m_cflags[0] = salloc("-Wall ");
    someSettings->m_cflags[1] = salloc("-Wextra ");
    someSettings->m_cflags[2] = salloc("-Wpedantic ");
    someSettings->m_cflags[3] = salloc("-std=c17 ");
    someSettings->m_cflags[4] = salloc("-MMD ");
    someSettings->m_cflags[5] = salloc("-MP ");

    someSettings->m_target = salloc("program");
    someSettings->m_src_dir = salloc("");
    someSettings->m_build_dir = salloc("build");
}

void set_path(Settings *someSettings, char *aPath)
{
    free(someSettings->m_filepath);
    someSettings->m_filepath = malloc(strlen(aPath) + 8 + 1);
    if (someSettings->m_filepath == NULL)
    {
        printf("Failed to allocate memory!\n");
        return;
    }
    
    strcpy(someSettings->m_filepath, aPath);

    strcat(someSettings->m_filepath, "/Makefile");
}

void createMake(const Settings *someSettings)
{

    FILE *file = fopen(someSettings->m_filepath, "w");
    if (file == NULL)
    {
        printf("Could not create file!\n");
        return;
    }

    int flagTotalCharLength = 0;
    int flagCount = someSettings->m_count_cflags;

    for (int i = 0; i < flagCount; i++)
    {
        flagTotalCharLength += strlen(someSettings->m_cflags[i]);
    }
    char *flags = malloc(flagTotalCharLength * sizeof(*flags));

    for (int i = 0; i < flagCount; i++)
    {
        strcat(flags, someSettings->m_cflags[i]);
    }
    
    //Variables from Settings
    fprintf(file, "CC := %s\nCFLAGS := %s\nTARGET := %s\nSRC_DIR := %s\nBUILD_DIR := %s\n", someSettings->m_compiler, flags, someSettings->m_target, someSettings->m_src_dir, someSettings->m_build_dir);
    //Variables created, not set by user
    fprintf(file, "\nSRCS := $(wildcard $(SRC_DIR)*.c)\nOBJS := $(SRCS:$(SRC_DIR)%%.c=$(BUILD_DIR)/%%.o)\nDEPS := $(OBJS:.o=.d)\n\n");
    //Recipies
    fprintf(file, "\nall: $(TARGET)\n\n$(TARGET): $(OBJS)\n\t$(CC) $(OBJS) -o $@\n\n$(BUILD_DIR)/%%.o: $(SRC_DIR)%%.c | $(BUILD_DIR)\n\t$(CC) $(CFLAGS) -c $< -o $@\n\n$(BUILD_DIR):\n\tmkdir -p $@\n\n-include $(DEPS)\n\nclean:\n\trm -rf $(BUILD_DIR) $(TARGET)\n\nPHONY: all clean\n");

    free(flags);
    fclose(file);
}

void clearMemory(Settings *someSettingsToClear)
{
    free(someSettingsToClear->m_filepath);
    free(someSettingsToClear->m_compiler);

    int count = someSettingsToClear->m_count_cflags;
    for (int i = 0; i < count; i++)
    {
        free(someSettingsToClear->m_cflags[i]);
    }
    free(someSettingsToClear->m_cflags);

    free(someSettingsToClear->m_target);
    free(someSettingsToClear->m_src_dir);
    free(someSettingsToClear->m_build_dir);
}

char *salloc(const char *someText)
{
    char *text = malloc(strlen(someText) + 1);
    if (text == NULL)
    {
        printf("Failed to allocate memory for string!\n");
        return NULL;
    }
    
    strcpy(text, someText);

    return text;
}