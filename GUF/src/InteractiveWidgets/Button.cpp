
#include <gtk/gtk.h>
#include "InteractiveWidgets/Button.h"

namespace GUF{

    Button::Button(const std::string_view &label) {
        _button = (GtkButton*)gtk_button_new_with_label(label.data());
    }

    Button::~Button() {

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

    GtkWidget *Button::getGtkWidget()const {
        return (GtkWidget*)_button;
    }

    void Button::addClickEventListener(const ClickCallback& clickCallback) {
        g_signal_connect (_button, "clicked", G_CALLBACK (Button::click), this);
        _clickCallback = clickCallback;
    }
}
