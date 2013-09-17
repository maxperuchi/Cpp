#include <windows.h>
#include <iostream>
#include "rotinas.h"
#include "resource.h"

#define ID_VISOR 99

#define ID_BOTAO_0 100
#define ID_BOTAO_1 101
#define ID_BOTAO_2 102
#define ID_BOTAO_3 103
#define ID_BOTAO_4 104
#define ID_BOTAO_5 105
#define ID_BOTAO_6 106
#define ID_BOTAO_7 107
#define ID_BOTAO_8 108
#define ID_BOTAO_9 109

#define ID_BOTAO_RESULTADO 110
#define ID_BOTAO_MAIS 111
#define ID_BOTAO_MENOS 112
#define ID_BOTAO_DIVIDIR 113
#define ID_BOTAO_MULTIPLICAR 114

HWND visor;
char textoAntigo[18];
char tempResultado[18];
char operador;
int resultado;
char numTemp[18];

void LimpaVariaveis(bool limpaVisor)
{
    if (limpaVisor)
    {
        SetWindowText(visor,"");
    }
    resultado = 0;
    tempResultado[18] = {NULL};
    textoAntigo[18] = {NULL};
}

using namespace std;

void Mostra666()
{
    SetWindowText(visor,"666");
};

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

char szClassName[ ] = "CalculadoraCPP";

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND janela;
    MSG messages;
    WNDCLASSEX wincl;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = CreatePatternBrush( LoadBitmap( hThisInstance, MAKEINTRESOURCE(BKGROUND) ) );
    wincl.hIcon = LoadIcon(hThisInstance,MAKEINTRESOURCE(MAINICON));
    wincl.hIconSm = LoadIcon(hThisInstance, MAKEINTRESOURCE(MAINICON));

    if (!RegisterClassEx (&wincl))
        return 0;

    janela = CreateWindowEx (
           0,
           szClassName,
           "CalculadoraCPP",
           WS_SYSMENU,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           230,
           290,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );

    visor = CriarLabel(janela,hThisInstance,20,15,20,200,"",(HMENU)ID_VISOR);

    CriarBotao(janela,hThisInstance,60,15,40,40,"7",(HMENU)ID_BOTAO_7);
    CriarBotao(janela,hThisInstance,60,65,40,40,"8",(HMENU)ID_BOTAO_8);
    CriarBotao(janela,hThisInstance,60,115,40,40,"9",(HMENU)ID_BOTAO_9);
    CriarBotao(janela,hThisInstance,110,15,40,40,"4",(HMENU)ID_BOTAO_4);
    CriarBotao(janela,hThisInstance,110,65,40,40,"5",(HMENU)ID_BOTAO_5);
    CriarBotao(janela,hThisInstance,110,115,40,40,"6",(HMENU)ID_BOTAO_6);
    CriarBotao(janela,hThisInstance,160,15,40,40,"1",(HMENU)ID_BOTAO_1);
    CriarBotao(janela,hThisInstance,160,65,40,40,"2",(HMENU)ID_BOTAO_2);
    CriarBotao(janela,hThisInstance,160,115,40,40,"3",(HMENU)ID_BOTAO_3);
    CriarBotao(janela,hThisInstance,210,15,40,90,"0",(HMENU)ID_BOTAO_0);

    CriarBotao(janela,hThisInstance,210,172,40,40,"+",(HMENU)ID_BOTAO_MAIS);
    CriarBotao(janela,hThisInstance,160,172,40,40,"-",(HMENU)ID_BOTAO_MENOS);
    CriarBotao(janela,hThisInstance,110,172,40,40,"/",(HMENU)ID_BOTAO_DIVIDIR);
    CriarBotao(janela,hThisInstance,60,172,40,40,"*",(HMENU)ID_BOTAO_MULTIPLICAR);
    CriarBotao(janela,hThisInstance,210,115,40,40,"=",(HMENU)ID_BOTAO_RESULTADO);

    resultado = 0;

    ShowWindow (janela, nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        if (messages.message == WM_KEYDOWN)
		{
            switch (messages.wParam)
            {
                case VK_NUMPAD1:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_1,NULL);
                    break;
                case VK_NUMPAD2:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_2,NULL);
                    break;
                case VK_NUMPAD3:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_3,NULL);
                    break;
                case VK_NUMPAD4:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_4,NULL);
                    break;
                case VK_NUMPAD5:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_5,NULL);
                    break;
                case VK_NUMPAD6:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_6,NULL);
                    break;
                case VK_NUMPAD7:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_7,NULL);
                    break;
                case VK_NUMPAD8:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_8,NULL);
                    break;
                case VK_NUMPAD9:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_9,NULL);
                    break;
                case VK_NUMPAD0:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_0,NULL);
                    break;
                case VK_DELETE:
                    LimpaVariaveis(true);
                    break;
                case VK_BACK:
                    LimpaVariaveis(true);
                    break;
                case VK_ADD:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_MAIS,NULL);
                    break;
                case VK_DIVIDE:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_DIVIDIR,NULL);
                    break;
                case VK_SUBTRACT:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_MENOS,NULL);
                    break;
                case VK_MULTIPLY:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_MULTIPLICAR,NULL);
                    break;
                case VK_RETURN:
                    WindowProcedure(janela,WM_COMMAND,ID_BOTAO_RESULTADO,NULL);
                    break;
                case VK_ESCAPE:
                    return 0;
                default:
                    break;
            }
        }

        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}


LRESULT CALLBACK WindowProcedure (HWND janela, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_COMMAND:
            switch (wParam)
            {
               case ID_BOTAO_0:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"0");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_1:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"1");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_2:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"2");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_3:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"3");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_4:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"4");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_5:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"5");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_6:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"6");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_7:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"7");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_8:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"8");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_9:
                    GetWindowText(visor,textoAntigo,18);
                    strcat(textoAntigo,"9");
                    SetWindowText(visor,textoAntigo);
                    break;
               case ID_BOTAO_RESULTADO:
                    if (operador == '+')
                    {
                        GetWindowText(visor,tempResultado,18);
                        resultado = atoi(tempResultado) + resultado;
                        itoa(resultado,textoAntigo,10);
                    }
                    else if (operador == '-')
                    {
                        GetWindowText(visor,tempResultado,18);
                        resultado = resultado - atoi(tempResultado);
                        itoa(resultado,textoAntigo,10);
                    }
                    else if (operador == '*')
                    {
                        GetWindowText(visor,tempResultado,18);
                        resultado = resultado * atoi(tempResultado);
                        itoa(resultado,textoAntigo,10);
                    }
                    else if (operador == '/')
                    {
                        GetWindowText(visor,tempResultado,18);
                        resultado = resultado / atoi(tempResultado);
                        itoa(resultado,textoAntigo,10);
                    }
                    SetWindowText(visor,textoAntigo);
                    LimpaVariaveis(false);
                    break;
               case ID_BOTAO_MAIS:
                    GetWindowText(visor,tempResultado,18);
                    resultado = atoi(tempResultado);
                    operador = '+';
                    SetWindowText(visor,"");
                    break;
               case ID_BOTAO_MENOS:
                    GetWindowText(visor,tempResultado,18);
                    resultado = atoi(tempResultado);
                    operador = '-';
                    SetWindowText(visor,"");
                    break;
               case ID_BOTAO_MULTIPLICAR:
                    GetWindowText(visor,tempResultado,18);
                    resultado = atoi(tempResultado);
                    operador = '*';
                    SetWindowText(visor,"");
                    break;
               case ID_BOTAO_DIVIDIR:
                    GetWindowText(visor,tempResultado,18);
                    resultado = atoi(tempResultado);
                    operador = '/';
                    SetWindowText(visor,"");
                    break;
               default:
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (janela, message, wParam, lParam);
    }

    return 0;
}
