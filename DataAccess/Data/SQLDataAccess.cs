using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Dapper;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;


namespace DataAccess.DataAccess
{
    public static class SQLDataAccess
    {
        // find and return the connection string to the db
        // by default connect set to "ProjectSQLDB"
        public static string GetConnectionString(string connect = "ProjectSQLDB")
        {
            return ConfigurationManager.ConnectionStrings[connect].ConnectionString;
        }

        public static List<T> LoadData<T>(string sql)
        {
            using (IDbConnection cnn = new SqlConnection(GetConnectionString()))
            {
                return cnn.Query<T>(sql).ToList();
            }
        }

        // data that is passed in will be saved to the db
        public static int SaveData<T>(string sql, T data)
        {
            using (IDbConnection cnn = new SqlConnection(GetConnectionString()))
            {
                return cnn.Execute(sql, data);
            }
        }
    }
}
