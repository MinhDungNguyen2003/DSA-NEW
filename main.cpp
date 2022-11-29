#include "header.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    string command_line_argument[argc];
    for (int i = 0; i < argc; i++)
        command_line_argument[i] = argv[i];
    if (command_line_argument[1] == "-a")
    {
        cout << "ALGORITHM MODE\n";
        if (argc == 6)
            command_line2(argc, argv);
        else if (argc == 5)
        {
            if (checkStringIsNumber(command_line_argument[3]))
                command_line3(argc, argv);
            else
                command_line1(argc, argv);
        }
    }

    else
    {
        cout << "COMPARE MODE\n";
        if (argc == 5)
            command_line4(argc, argv);

        else if (argc == 6)
            command_line5(argc, argv);
    }

    return 0;
}