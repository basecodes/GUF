#include "Windows/Window.h"
#include "Application/Application.h"
#include <gtk/gtk.h>

namespace GUF {

    void Window::setSize(int width, int height) {
        if (width < 0) {
            throw std::invalid_argument("width");
        }

        if (height < 0) {
            throw std::invalid_argument("height");
        }
        gtk_window_set_default_size(GTK_WINDOW (getGtkWidget()), width, height);
    }

    void Window::setPosition(GtkWindowPosition windowPosition) {
        gtk_window_set_position(getGtkWidget<GtkWindow*>(), windowPosition);
    }

    void Window::setTitle(const std::string_view &title) {
        if (title == "") {
            throw std::invalid_argument("title");
        }
        gtk_window_set_title(GTK_WINDOW (getGtkWidget()), title.data());
    }

    std::string Window::getTitle() {
        return gtk_window_get_title(GTK_WINDOW (getGtkWidget()));
    }

    template<typename... ArgsType>
    Window::Window(const std::string_view &firstPropertyName, ArgsType... ts)
        :Window(GTK_TYPE_WINDOW,firstPropertyName, ts...) {

    }

    template<typename... ArgsType>
    Window::Window(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
        :Bin(type,firstPropertyName,ts...){
    }
}