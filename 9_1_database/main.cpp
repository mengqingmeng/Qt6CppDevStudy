#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << drivers.join(",");

    QSqlDatabase m_db = QSqlDatabase::addDatabase("QPSQL");

    m_db.setHostName("127.0.0.1");
    m_db.setDatabaseName("commutator");

    m_db.setPort(5432);
    m_db.setUserName("postgres");
    m_db.setPassword("postgres");
    bool openResult = m_db.open();
    qDebug() << "db is open" << openResult << " : " << m_db.lastError().text();

    QCoreApplication a(argc, argv);

    return a.exec();
}
