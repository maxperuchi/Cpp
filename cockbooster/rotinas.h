#ifndef ROTINAS_H_INCLUDED
#define ROTINAS_H_INCLUDED

HWND CriarBotao(HWND parJanela, HINSTANCE parInstancia, INT posX, INT posY, INT tamX, INT tamY, char textoBotao[ ], HMENU parHmenu)
{
    return CreateWindow("BUTTON",textoBotao,WS_VISIBLE | WS_CHILD,posY,posX,tamY,tamX,parJanela,parHmenu,parInstancia,NULL);
}

HWND CriarTxtBox(HWND parJanela, HINSTANCE parInstancia, INT posX, INT posY, INT tamX, INT tamY, char texto[ ], HMENU parHmenu)
{
    return CreateWindow("EDIT",texto,WS_VISIBLE | WS_CHILD | WS_BORDER,posY,posX,tamY,tamX,parJanela,parHmenu,parInstancia,NULL);
}

HWND CriarLabel(HWND parJanela, HINSTANCE parInstancia, INT posX, INT posY, INT tamX, INT tamY, char texto [ ], HMENU parHmenu)
{
    return CreateWindow("STATIC",texto,WS_VISIBLE | WS_CHILD | SS_RIGHT, posY, posX, tamY, tamX, parJanela, parHmenu, parInstancia,NULL);
}

#endif // ROTINAS_H_INCLUDED
