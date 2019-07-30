
#include <LayoutContainers/Bin.h>

namespace GUF{
    Bin::~Bin() = default;
    Bin::Bin(GtkBin *bin):Container((GtkContainer*)bin) {

    }

    template<typename... ArgsType>
    Bin::Bin(const std::string_view &firstPropertyName, ArgsType... ts)
        :Bin(GTK_TYPE_BIN,firstPropertyName, ts...) {

    }

    template<typename... ArgsType>
    Bin::Bin(GType type, const std::string_view &firstPropertyName, ArgsType... ts)
        :Container(type, firstPropertyName,ts...) {

    }
}

