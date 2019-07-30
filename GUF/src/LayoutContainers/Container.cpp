
#include "LayoutContainers/Container.h"

namespace GUF{

    Container::~Container() {
    }

    void Container::AddWidget(Widget *widget) {
        gtk_container_add (GTK_CONTAINER (getGtkWidget()), widget->getGtkWidget());
    }

    void Container::RemoveWidget(Widget *widget) {
        gtk_container_remove(GTK_CONTAINER (getGtkWidget()), widget->getGtkWidget());
    }
}
