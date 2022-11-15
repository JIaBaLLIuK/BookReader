#ifndef WIDGET_STYLE_H
#define WIDGET_STYLE_H

#include <QString>
// класс, содержащий в себе стили для всех виджетов
class WidgetStyle
{
public:
    static QString GetTabStyle();
    static QString GetAboutPogramLabelStyle();
    static QString GetMainWindowLabelStyle();
    static QString GetPageNumberLabelsStyle();
    static QString GetBookLabelStyle();
    static QString GetFindPageButtonStyle();
    static QString GetFindPageLineEditStyle();

    static QString GetRecentOpenedFilesButtonsStyle();
    static QString GetDeleteRecentOpenedFilesButtonsStyle();
};

#endif
