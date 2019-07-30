
#include "LayoutContainers/Container.h"

namespace GUF{

    template <typename ... ArgsType>
    Container::Container(const std::string_view& firstPropertyName,ArgsType...ts)
        :Container(GTK_TYPE_CONTAINER,firstPropertyName,ts...){
    }

    template<typename... ArgsType>
    Container::Container(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
            :Widget(type,firstPropertyName,ts...) {
    }

    Container::Container(GtkContainer *container) : Widget((GtkWidget*)container) {

    }

    Container::~Container() {
    }

    void Container::Add(Widget *widget) {
        gtk_container_add (GTK_CONTAINER (getGtkObject<GtkContainer*>()), widget->getGtkObject<GtkWidget*>());
    }

    void Container::Remove(Widget *widget) {
        gtk_container_remove(GTK_CONTAINER (getGtkObject()), widget->getGtkObject<GtkWidget*>());
    }
}
