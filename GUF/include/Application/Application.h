
#ifndef GUF_APPLICATION_H
#define GUF_APPLICATION_H

#include <string_view>
#include <gtk/gtk.h>
#include <Object.h>

namespace GUF{

    class Window;
    class Application: public Object {
    public:
        Application(const std::string_view& applicationId,GApplicationFlags applicationFlags);
        ~Application() override;

        virtual int run(int argc,char *argv[]);
        virtual void activate();
        virtual void AddWindow(Window *window);

    private:
        static void g_activate(GtkApplication *application, gpointer userData);

        GtkApplication *_application;
    };
}


#endif //GUF_APPLICATION_H
