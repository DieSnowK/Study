// ������
class ISplitter
{
public:
    virtual void split() = 0;
    virtual ISplitter* clone() = 0; // ͨ����¡�Լ�����������
    
    virtual ~ISplitter(){}
};