#include "Windows/Dialog.h"
#include "LayoutContainers/Box.h"

namespace GUF{

    template<typename... ArgsType>
    Dialog::Dialog(const std::string_view &firstPropertyName, ArgsType... ts)
        :Dialog(GTK_TYPE_DIALOG,firstPropertyName, ts...) {
    }

    template<typename... ArgsType>
    Dialog::Dialog(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
            :Window(type,firstPropertyName,ts...) {

    }

    Dialog::Dialog():Window((GtkWindow*)(GtkDialog*)gtk_dialog_new ()) {
        _box = new Box((GtkBox*)gtk_dialog_get_content_area(getGtkObject<GtkDialog *>()));
    }

    Dialog::~Dialog() {
        delete(_box);
    }

    Box *Dialog::getBox() {
        return _box;
    }
}
