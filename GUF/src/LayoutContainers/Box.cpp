#include "LayoutContainers/Box.h"

namespace GUF{

    Box::Box(GtkOrientation orientation /*= GtkOrientation::GTK_ORIENTATION_VERTICAL*/,int spacing /*= 1*/) {
        _box = (GtkBox*)gtk_box_new(orientation,spacing);
    }

    Box::Box() {

    }

    Box::Box(GtkBox *gtkBox) {
        _box = gtkBox;
    }
}