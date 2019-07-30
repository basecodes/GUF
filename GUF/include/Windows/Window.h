
#ifndef GUF_WINDOW_H
#define GUF_WINDOW_H

#include <gtk/gtk.h>
#include <string_view>

#include "LayoutContainers/Bin.h"

namespace GUF {

    class FormFactory;
    class Application;
    class Window :public Bin{
    public:

        Window();
        explicit Window(GtkWindowType windowType);
        explicit Window(GtkWindow *window);

        ~Window() override = default;

        void setTitle(const std::string_view& title);
        std::string getTitle();

        void setSize(int width,int height);
        void setPosition(GtkWindowPosition windowPosition);

        [[nodiscard]]
        GtkWidget *getGtkWidget() const override {
            return (GtkWidget *)_window;
        }

    private:
        GtkWindow *_window;
    };
}

#endif //GUF_WINDOW_H
