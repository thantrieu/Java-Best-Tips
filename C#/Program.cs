using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Text;
using System.Threading.Tasks;

namespace TestSQLiteDB
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var sql = "Data Source=test.db";
            //SQLiteConnection.CreateFile(createDBSQL);
            SQLiteConnection conn = new SQLiteConnection(sql);
            try
            {
                conn.Open();
                // CreateTable(conn);
                //InsertData(conn, "S100", "Ngo Gia Khai", 22);
                //InsertData(conn, "S101", "Le Tuan Anh", 32);
                //InsertData(conn, "S102", "Tran Quoc Tuan", 29);
                //InsertData(conn, "S103", "Pham Thi Hong Anh", 25);
                InsertData(conn, "S105", "Nguyen Mai Loan", 22);
                SelectData(conn);
            } catch(Exception e)
            {
                Console.WriteLine(e);
            } finally
            {
                conn.Close();
            }
        }

        private static void SelectData(SQLiteConnection conn)
        {
            var id = "StaffId";
            var fullName = "FullName";
            var age = "Age";
            Console.WriteLine($"{id,-20:s}{fullName,-35:s}{age,-10:d}");
            var sql = "SELECT * FROM Staffs";
            var cmd = new SQLiteCommand(sql, conn);
            var reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                Console.WriteLine($"{reader.GetString(0),-20:d}" +
                    $"{reader.GetString(1),-35:s}" +
                    $"{reader.GetInt32(2),-10:d}");
            }
        }

        private static void InsertData(SQLiteConnection conn, string staffId, string fullName, int age)
        {
            var sql = "INSERT INTO Staffs(StaffId, FullName, Age) " +
                "VALUES(@staffId, @fullName, @age)";
            var cmd = new SQLiteCommand(sql, conn);
            cmd.Parameters.AddWithValue("@staffId", staffId);
            cmd.Parameters.AddWithValue("@fullName", fullName);
            cmd.Parameters.AddWithValue("@age", age);
            cmd.ExecuteNonQuery();
        }

        private static void CreateTable(SQLiteConnection conn)
        {
            string sql = "CREATE TABLE IF NOT EXISTS Staffs(" +
                    "StaffId VARCHAR(20) PRIMARY KEY," +
                    "FullName VARCHAR(50)," +
                    "Age INT DEFAULT 0" +
                    ")";
            var cmd = new SQLiteCommand(sql, conn);
            cmd.ExecuteNonQuery();
        }
    }
}
