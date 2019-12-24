//
// Created by zhihui on 12/23/19.
//

#ifndef BASICPTR_BASICPTR_H
#define BASICPTR_BASICPTR_H
#include <utility>

namespace gary{

    class Counter{

    public:
        explicit Counter():count(0){}
        ~Counter(){}
        int get(){
            return count;
        }
        void plus (){
            ++count;
        }
        void minus (){
            --count;
        }
    private:
        int count;
    };


    template <typename T>
    class basicPtr{

    public:
        explicit basicPtr(T *_data):data(_data){
            counter = new Counter();
            if(_data)
            {
                counter->plus();
            }
        }

        basicPtr(const basicPtr<T> &old):data(old.data),counter(old.counter){
            counter->plus();
        }

        basicPtr& operator=(const basicPtr<T> &old) {
            if(this != &old){
                counter->minus();
                if(0 == counter->get()){
                    delete data;
                    delete counter;
                }
                data = old.data;
                counter = old.counter;
                counter->plus();
            }
            return *this;
        }

        ~basicPtr(){
            counter->minus();
            if(0 == counter->get()){
                delete data;
                delete counter;
            }
        }

        T& operator *() {
            return *data;
        }

        T& operator ->() {
            return data;
        }

    private:
        T *data;
        Counter *counter;
    };
}


#endif //BASICPTR_BASICPTR_H
