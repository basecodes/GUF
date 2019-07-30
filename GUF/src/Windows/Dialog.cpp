#include "Windows/Dialog.h"
#include "LayoutContainers/Box.h"

namespace GUF{

    Dialog::Dialog():Window((GtkWindow*)(GtkDialog*)gtk_dialog_new ()) {
        _dialog = (GtkDialog*)Window::getGtkWidget();
        _box = new Box((GtkBox*)gtk_dialog_get_content_area(_dialog));
    }

    Dialog::~Dialog() {
        delete(_box);
    }

    Box *Dialog::getBox() {
        return _box;
    }
}
