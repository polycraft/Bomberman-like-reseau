#ifndef PROPERTY_H
#define PROPERTY_H

class Property
{
    public:
        template <typename T> Property(T val)
        {
            value=(void*)new T(val);
        }
        virtual ~Property()
        {
            delete value;
        }

        template <typename T> const T& getValue()
        {
            T* tmp=(T*)value;
            return *tmp;
        }

        template <class T> void setValue(T v)
        {
            T* tmp=(T*)value;
            *tmp=v;
        }
    private:

        void* value;
};

#endif // PROPERTY_H
