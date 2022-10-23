#include "../include/WidgetStyle.h"

QString WidgetStyle::GetTabStyle()  // hides tab buttons on the QTabBar widget
{
    return "QTabBar::tab "
           "{ width: 0; "
           "height: 0; "
           "margin: 0; "
           "padding: 0; "
           "border: none; }";
}
