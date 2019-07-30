
#ifndef GUF_OBJECT_H
#define GUF_OBJECT_H

#include "Common.h"
#include <initializer_list>
#include <gtk/gtk.h>
#include <string_view>
namespace GUF{
    class Object {
    public:
        Object() = default;

        virtual ~Object() = default;

        void setProperty(const std::string_view& propertyId, const GValue *value);
        GValue getProperty(const std::string_view& propertyId);

        void dispose();
        void finalize();

        void dispatchPropertiesChanged();
        void notify();
//        void constructed();

    protected:
        template <typename ... ArgsType>
        explicit Object(GType type,const std::string_view& firstPropertyName,ArgsType...ts);

    private:
        GObject *_object;
    };
}


#endif //GUF_OBJECT_H
