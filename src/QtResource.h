
#ifndef QT_ZI_YUAN_H

#define QT_ZI_YUAN_H


class QtResource {
    public:
        static QtResource& instance(){
            static QtResource shiLi_;
            return shiLi_;
        }

    private:

        QtResource();
        ~QtResource();
};

#endif /* end of include guard: QT_ZI_YUAN_H */
