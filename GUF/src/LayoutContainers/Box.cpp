#include "LayoutContainers/Box.h"

namespace GUF{

    template<typename... ArgsType>
    Box::Box(const std::string_view &firstPropertyName, ArgsType... ts)
        :Box(GTK_TYPE_BOX,firstPropertyName, ts...) {

    }

    template<typename... ArgsType>
    Box::Box(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
        :Box(type, firstPropertyName,ts...) {

    }
}