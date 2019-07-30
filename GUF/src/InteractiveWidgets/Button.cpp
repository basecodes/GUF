
#include <gtk/gtk.h>
#include "InteractiveWidgets/Button.h"

namespace GUF{

    Button::Button(const std::string_view &label)
        :Bin((GtkBin*)gtk_button_new_with_label(label.data())) {
    }

    template<typename... ArgsType>
    Button::Button(const std::string_view &firstPropertyName, ArgsType... ts)
            :Button(GTK_TYPE_BUTTON,firstPropertyName, ts...) {

    }

    template<typename... ArgsType>
    Button::Button(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
            :Bin(type,firstPropertyName,ts...) {

    }

    void Button::click (GtkWidget *widget,gpointer userData) {
        if(widget == nullptr) {
            throw std::invalid_argument("widget");
        }

        if(userData == nullptr) {
            throw std::invalid_argument("userData");
        }

        auto button = (Button *) userData;
        button->_clickCallback();
    }

    void Button::addClickEventListener(const ClickCallback& clickCallback) {
        g_signal_connect (getGtkObject<GtkButton *>(), "clicked", G_CALLBACK (Button::click), this);
        _clickCallback = clickCallback;
    }
}
