#include <windows.h>

int main(int argc, char **argv) { 
    if (argc !=2) {
        MessageBox(NULL, "Usage: exec_html <html_file>", "Usage Error", MB_OK);
        return 1;
    }
    if ((int)ShellExecute(NULL, "open", argv[1], NULL, NULL, SW_SHOWNORMAL) < 32) {
        MessageBox(NULL, argv[1], "Could not open file", MB_OK);
        return 1;
    }
    return 0;
}
