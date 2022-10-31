#include "../include/WidgetStyle.h"

QString WidgetStyle::GetTabStyle()
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

QString WidgetStyle::GetMainWindowLabelStyle()
{
    return "QLabel {"
                "qproperty-wordWrap: false;"
                "font-size: 70px;"
                "font-family: \"Monotype Corsiva\";"
                "font-weight: 500;"
            "}";
}

QString WidgetStyle::GetPageNumberLabelsStyle()
{
    return "QLabel {"
                "qproperty-wordWrap: false;"
                "font-size: 16px;"
                "font-family: \"Times New Roman\";"
            "}";
}

QString WidgetStyle::GetBookLabelStyle()
{
    return "QLabel {"
                "qproperty-wordWrap: true;"
                "font-size: 20px;"
                "font-family: \"Times New Roman\";"
            "}";
}

QString WidgetStyle::GetFindPageButtonStyle()
{
    return "QPushButton {"
                "background: #FAEBD7;"
                "border: 0px solid white;"
           "}";
}

QString WidgetStyle::GetFindPageLineEditStyle()
{
    return "QLineEdit {"
                "background: #FAEBD7;"
                "border: 1px solid gray;"
                "font-size: 16px;"
                "font-family: \"Times New Roman\";"
            "}";
}
