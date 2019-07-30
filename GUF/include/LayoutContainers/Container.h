
#ifndef GUF_CONTAINER_H
#define GUF_CONTAINER_H

#include <map>
#include <string>
#include <gtk/gtk.h>
#include "Widget.h"

namespace GUF{

    class Container: public Widget {
    public:

        ~Container() override;

        virtual void AddWidget(Widget *widget) ;
        virtual void RemoveWidget(Widget *widget) ;

        [[nodiscard]]
        virtual GtkWidget *getGtkWidget() const = 0;
    };
}

#endif //GUF_CONTAINER_H
