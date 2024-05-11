class ConsoleNotifier : public IProgress 
{
public:
	virtual void DoProgress(float value)
	{
		cout << ".";
	}
};

// 此处IProgess是接口继承
class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;
public:
	void Button1_Click()
	{
		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number);

		ConsoleNotifier cn;
		splitter.addIProgress(this); //订阅通知
		splitter.addIProgress(&cn); //订阅通知

		splitter.split();
	}

	virtual void DoProgress(float value)
	{
		progressBar->setValue(value);
	}
};