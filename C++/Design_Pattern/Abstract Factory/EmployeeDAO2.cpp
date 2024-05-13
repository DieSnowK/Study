// ���ݿ�����йصĻ���
class IDBConnection
{};
class IDBConnectionFactory
{
public:
    virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommand
{};
class IDBCommandFactory
{
public:
    virtual IDBCommand* CreateDBCommand() = 0;
};

class IDataReader
{};
class IDataReaderFactory
{
public:
    virtual IDataReader* CreateDataReader() = 0;
};

//֧��SQL Server
class SqlConnection: public IDBConnection
{};
class SqlConnectionFactory:public IDBConnectionFactory
{};

class SqlCommand: public IDBCommand
{};
class SqlCommandFactory:public IDBCommandFactory
{};

class SqlDataReader: public IDataReader
{};
class SqlDataReaderFactory:public IDataReaderFactory
{};

//֧��Oracle
class OracleConnection: public IDBConnection
{};
class OracleCommand: public IDBCommand
{};
class OracleDataReader: public IDataReader
{};

class EmployeeDAO
{
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDataReaderFactory* dataReaderFactory;
public:
    vector<EmployeeDO> GetEmployees()
    {
        IDBConnection* connection =
            dbConnectionFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command =
            dbCommandFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); // ������

        IDBDataReader* reader = command->ExecuteReader(); // ������
        while (reader->Read())
        {}
    }
};