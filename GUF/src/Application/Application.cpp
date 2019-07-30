
#include "Application/Application.h"
#include "Windows/Window.h"
#include <stdexcept>

namespace GUF {

    void Application::g_activate(GtkApplication *application, gpointer userData) {
        if(application == nullptr) {
            throw std::invalid_argument("application");
        }

        if(userData == nullptr) {
            throw std::invalid_argument("userData");
        }
        auto uifApplication = (Application *) userData;
        uifApplication->activate();
    }

    Application::Application(const std::string_view& applicationId,GApplicationFlags applicationFlags)
        :Object((GObject*)gtk_application_new(applicationId.data(), applicationFlags)){
    }

    Application::~Application() {
        g_object_unref(getGtkObject());
    }

    void Application::AddWindow(Window *window) {
        gtk_application_add_window(getGtkObject<GtkApplication*>(), window->getGtkObject<GtkWindow*>());
    }

    int Application::run(int argc, char **argv) {
        g_signal_connect (getGtkObject(), "activate", G_CALLBACK(Application::g_activate), this);
        auto status = g_application_run(G_APPLICATION (getGtkObject<GtkApplication*>()), argc, argv);
        return status;
    }

    void Application::activate() {
    }
}