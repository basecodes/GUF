
#ifndef GUF_BUTTON_H
#define GUF_BUTTON_H

#include <gtk/gtk.h>
#include <Widget.h>
#include "Common.h"

namespace GUF {
    class Button : public Widget {
    public:
        Button():Button(""){}
        explicit Button(const std::string_view &label);
        ~Button() override;

        [[nodiscard]]
        GtkWidget *getGtkWidget() const override;
        void addClickEventListener(const ClickCallback& clickCallback);

    private:
        static void click(GtkWidget *widget,gpointer data);

        GtkButton *_button;
        ClickCallback _clickCallback;
    };
}

#endif //GUF_BUTTON_H
