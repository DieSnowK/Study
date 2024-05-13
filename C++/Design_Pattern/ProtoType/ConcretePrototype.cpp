// 具体类
class BinarySplitter : public ISplitter
{
public:
    virtual ISplitter* clone()
    {
        return new BinarySplitter(*this); // 调用拷贝构造
    }
};

class TxtSplitter: public ISplitter
{
public:
    virtual ISplitter* clone()
    {
        return new TxtSplitter(*this); // 调用拷贝构造
    }
};

class PictureSplitter: public ISplitter
{
public:
    virtual ISplitter* clone()
    {
        return new PictureSplitter(*this); // 调用拷贝构造
    }
};

class VideoSplitter: public ISplitter
{
public:
    virtual ISplitter* clone()
    {
        return new VideoSplitter(*this); // 调用拷贝构造
    }
};