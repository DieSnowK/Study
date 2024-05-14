//Ŀ��ӿڣ��½ӿڣ�
class ITarget
{
public:
    virtual void process() = 0;
};

//�����ӿڣ��Ͻӿڣ�
class IAdaptee
{
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

//��������
class OldClass: public IAdaptee
{};

//���������� �̳�
class Adapter: public ITarget
{
protected:
    IAdaptee* pAdaptee;//���
public:
    Adapter(IAdaptee* pAdaptee)
    {
        this->pAdaptee = pAdaptee;
    }
    
    virtual void process()
    {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};

//�������� ��̳�
class Adapter: public ITarget,
               protected OldClass
{}

int main()
{
    IAdaptee* pAdaptee = new OldClass();
    ITarget* pTarget = new Adapter(pAdaptee);
    pTarget->process();
}