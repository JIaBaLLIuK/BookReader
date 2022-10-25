#include "../include/WidgetStyle.h"

QString WidgetStyle::GetTabStyle()  // return styles wich hide tab buttons on the QTabBar widget
{
    return "QTabBar::tab {"
                "width: 0;"
                "height: 0;"
            "}"

            "QTabWidget::pane {"
               "background: #FAEBD7;"
               "border: 1px solid gray;"
            "}";
}

QString WidgetStyle::GetAboutPogramLabelStyle()
{
    return "QLabel {"
                "qproperty-wordWrap: true;"
                "font-size: 20px;"
                "font-family: \"Times New Roman\";"
            "}";
}
