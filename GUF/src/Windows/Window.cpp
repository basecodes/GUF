#include "Windows/Window.h"
#include "Application/Application.h"
#include <gtk/gtk.h>

namespace GUF {

    Window::Window():Window(GtkWindowType::GTK_WINDOW_TOPLEVEL) {

    }

    Window::Window(GtkWindowType windowType) {
        _window = (GtkWindow *) gtk_window_new(windowType);
    }

    Window::Window(GtkWindow *window) {
        _window = window;
    }

    void Window::setSize(int width, int height) {
        if (width < 0) {
            throw std::invalid_argument("width");
        }

        if (height < 0) {
            throw std::invalid_argument("height");
        }
        gtk_window_set_default_size(GTK_WINDOW (_window), width, height);
    }

    void Window::setPosition(GtkWindowPosition windowPosition) {
        gtk_window_set_position(_window, windowPosition);
    }

    void Window::setTitle(const std::string_view &title) {
        if (title == "") {
            throw std::invalid_argument("title");
        }
        gtk_window_set_title(GTK_WINDOW (_window), title.data());
    }

    std::string Window::getTitle() {
        return gtk_window_get_title(GTK_WINDOW (_window));
    }
}