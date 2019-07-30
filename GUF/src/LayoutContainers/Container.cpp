
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

    void Container::AddWidget(Widget *widget) {
        gtk_container_add (GTK_CONTAINER (getGtkWidget()), widget->getGtkWidget());
    }

    void Container::RemoveWidget(Widget *widget) {
        gtk_container_remove(GTK_CONTAINER (getGtkWidget()), widget->getGtkWidget());
    }
}
