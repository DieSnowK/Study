//���ݿ�����йصĻ���
class IDBConnection
{};
class IDBCommand
{};
class IDataReader
{};

class IDBFactory
{
public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDataReader* CreateDataReader() = 0;
};

//֧��SQL Server
class SqlConnection: public IDBConnection
{};
class SqlCommand: public IDBCommand
{};
class SqlDataReader: public IDataReader
{};

class SqlDBFactory:public IDBFactory
{
public:
    virtual IDBConnection* CreateDBConnection()
    {}
    virtual IDBCommand* CreateDBCommand()
    {}
    virtual IDataReader* CreateDataReader()
    {}
};

//֧��Oracle
class OracleConnection: public IDBConnection
{};
class OracleCommand: public IDBCommand
{};
class OracleDataReader: public IDataReader
{};

class EmployeeDAO
{
    IDBFactory* dbFactory;
public:
    vector<EmployeeDO> GetEmployees()
    {
        IDBConnection* connection =
            dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command =
            dbFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection);

        IDBDataReader* reader = command->ExecuteReader();
        while (reader->Read())
        {}
    }
};