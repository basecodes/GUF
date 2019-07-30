
#ifndef GUF_BIN_H
#define GUF_BIN_H

#include "Container.h"

namespace GUF{
    class Bin :public Container {
    public:

        explicit Bin(GtkBin* bin);
        ~Bin() override;

        template <typename ... ArgsType>
        explicit Bin(const std::string_view& firstPropertyName,ArgsType...ts);
    protected:
        template <typename ... ArgsType>
        explicit Bin(GType type,const std::string_view& firstPropertyName,ArgsType...ts);
    };
}
#endif //GUF_BIN_H
