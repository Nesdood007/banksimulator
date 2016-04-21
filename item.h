//item.h
//Amy Vinson and Brady O'Leary
//

class item {
    public:
        int key;
        virtual void Run();
        item():key(0);//default item constructor that sets key to zero
};

