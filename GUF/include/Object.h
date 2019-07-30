
#ifndef GUF_OBJECT_H
#define GUF_OBJECT_H

#include "Common.h"
#include <initializer_list>
#include <gtk/gtk.h>
#include <string_view>

namespace GUF{
    class Object {
    public:

        template <typename ... ArgsType>
        explicit Object(GType type,const std::string_view& firstPropertyName,ArgsType...ts);
        explicit Object(GObject *object);
        virtual ~Object() = default;

        virtual void setProperty(const std::string_view& propertyName, const GValue *value);
        virtual GValue getProperty(const std::string_view& propertyName);

        virtual void dispose();
        virtual void finalize();

        virtual void dispatchPropertiesChanged();
        virtual void notify(const std::string_view& propertyName);

        virtual void constructed();

        virtual GObject* getGtkObject (){
            return _object;
        }

        template<typename T>
        T getGtkObject() {
            return (T)(_object);
        }

    private:
        GObject *_object{};
    };
}


#endif //GUF_OBJECT_H
