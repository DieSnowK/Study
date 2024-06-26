class ISubject
{
public:
    virtual void process() = 0;
};

class RealSubject : public ISubject
{
public:
    virtual void process()
    {}
};

class ClientApp
{
    ISubject* subject;
public:
    ClientApp()
    {
        subject = new RealSubject();
    }
    
    void DoTask()
    {
        // ...
        subject->process();
        // ...
    }
};