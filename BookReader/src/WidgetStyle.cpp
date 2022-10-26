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
<<<<<<< HEAD
           "}";
}

QString WidgetStyle::GetStartLabelStyle()
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
                "font-size: 14px;"
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
=======
            "}";
>>>>>>> 71f1b8d385306c6712a94b2d1a57c76083c33321
}
