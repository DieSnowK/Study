class Memento
{
    string state;
    //..
public:
    Memento(const string& s) 
        : state(s) 
    {}

    string getState() const 
    { 
        return state; 
    }

    void setState(const string& s) 
    { 
        state = s; 
    }
};

class Originator
{
    string state;
    //....
public:
    Originator() {}

    Memento createMomento() 
    {
        Memento m(state);
        return m;
    }
    
    void setMomento(const Memento & m) 
    {
        state = m.getState();
    }
};

int main()
{
    Originator orginator;
    
    // �������״̬���洢������¼
    Memento mem = orginator.createMomento();
    
    // .. �ı�orginator״̬
    
    // �ӱ���¼�лָ�
    orginator.setMomento(memento);
}