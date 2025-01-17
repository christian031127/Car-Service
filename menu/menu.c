#include "menu.h"

//Logó illetve adott menüpontokban a szövegek kiírása
void logo()
{
    printf("          AUTOSZERVIZ PROGRAM         \n");
    printf("              __-------__             \n");
    printf("            / _---------_ \\          \n");
    printf("           / /           \\ \\        \n");
    printf("           | |           | |          \n");
    printf("           |_|___________|_|          \n");
    printf("       /-\\|                 |/-\\    \n");
    printf("      | _ |\\       0       /| _ |    \n");
    printf("      |(_)| \\      !      / |(_)|    \n");
    printf("      |___|__\\_____!_____/__|___|    \n");
    printf("      [_________|IYX0EQ|________]     \n");
    printf("       ||||     ~~~~~~~~    ||||      \n");
    printf("        --                   --       \n");
}

void fomenu()
{
    printf("[1] Uj auto hozzaadasa\n");
    printf("[2] Auto torlese\n");
    printf("[3] Kereses ugyfel es rendszam alapjan\n");
    printf("[4] Javitas feljegyzese\n");
    printf("[5] Szerviztortenet megjelenitese\n");
    printf("[6] Hamarosan lejaro vizsga\n");
    printf("[0] Kilepes\n");
    printf("Valasztas: ");
}

void almenu1()
{
    printf("[1] Uj ugyfel hozzadasa\n");
    printf("[2] Uj auto hozzaadasa meglevo ugyfelhez\n");
    printf("[0] Visszalepes\n");
    printf("Valasztas: ");
}

void almenu2()
{
    printf("AUTO ES HOZZATARTOZO JAVITASOK TORLESE:\n\n");
    printf("Auto azonositoja: ");
}

void almenu3()
{
    printf("[1] Ugyfel nev alapjan\n");
    printf("[2] Rendszam alapjan\n");
    printf("[0] Visszalepes\n");
    printf("Valasztas: ");
}

void almenu4()
{
    printf("[1] Uj javitas hozzaadasa meglevo autohoz\n");
    printf("[0] Visszalepes\n");
    printf("Valasztas: ");
}

void visszalep()
{
    printf("Visszalepeshez [ENTER]\n");
    getch();
    system("cls");
}
