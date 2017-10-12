#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

HWND CreateButton(HWND parJanela, HINSTANCE instance, INT posX, INT posY, INT tamX, INT tamY, char text[ ], HMENU parHmenu)
{
    return CreateWindow("BUTTON",text,WS_VISIBLE | WS_CHILD,posY,posX,tamY,tamX,parJanela,parHmenu,instance,NULL);
}

HWND CreateTxtBox(HWND parJanela, HINSTANCE instance, INT posX, INT posY, INT tamX, INT tamY, char text[ ], HMENU parHmenu)
{
    return CreateWindow("EDIT",text,WS_VISIBLE | WS_CHILD | WS_BORDER,posY,posX,tamY,tamX,parJanela,parHmenu,instance,NULL);
}

HWND CreateLabel(HWND parJanela, HINSTANCE instance, INT posX, INT posY, INT tamX, INT tamY, char text [ ], HMENU parHmenu)
{
    return CreateWindow("STATIC",text,WS_VISIBLE | WS_CHILD | SS_RIGHT, posY, posX, tamY, tamX, parJanela, parHmenu, instance,NULL);
}

#endif // HELPERS_H_INCLUDED
