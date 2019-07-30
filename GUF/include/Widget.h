
#ifndef GUF_WIDGET_H
#define GUF_WIDGET_H

#include <string>
#include "Common.h"
#include <gtk/gtk.h>

namespace GUF {

    class Window;
    abstract class Widget {
    public:
        Widget();
        virtual ~Widget() = default;

        virtual void show();
        virtual void destroy();
        virtual bool inDestruction();
        virtual void showNow();
        virtual void hide();
        virtual void destroyed(GtkWidget **widget_pointer);
        virtual void setParentWindow(Window *window);
        virtual void setParent(Widget *widget);

        [[nodiscard]]
        virtual std::string getUUID() const;

        [[nodiscard]]
        virtual GtkWidget *getGtkWidget() const = 0;

    private:
        std::string _uuid;
    };
}

#endif //GUF_WIDGET_H
