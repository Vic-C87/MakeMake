#include "app.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    Settings settings;
    int running = 1;
    int input_status;
    char *compile_flag = "-c";
    char *path_flag = "-p";
    if (argc < 2)
    {
        int menu_choice;
        while (running)
        {
            print_menu();
            input_status = scanf("%d", &menu_choice);

            if (!input_status)
            {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
            else
            {
                switch (menu_choice)
                {
                case 1:
                    printf("case 1\n");
                    break;
                case 2:
                    printf("case 2\n");
                    break;
                case 3:
                    printf("case 3\n");
                    break;
                case 4:
                    printf("case 4\n");
                    break;
                case 0:
                    running = 0;
                    break;
                default:
                    break;
                }
            }

        }

    }
    else if (strcmp(argv[1], path_flag) == 0)
    {
        if (argc > 2)
        {
            initialize_basic(&settings);
            set_path(&settings, argv[2]);
            createMake(&settings);
            clearMemory(&settings);
            printf("Makefile created for project at: %s\n", argv[2]);
        }
        else
        {
            printf("Not enough arguments!\n");
        }
    }
    else if (strcmp(argv[1], compile_flag) == 0)
    {
        initialize_basic(&settings);
        createMake(&settings);
        clearMemory(&settings);
        printf("Basic Makefile created!\n");
        
    }
    else
    {
        printf("error, flag not recognized, try -p [filepath]\n");
    }
    

    return 0;
}