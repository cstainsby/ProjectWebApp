using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Dapper;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

namespace DataAccess.Data
{
    public class SQLDataAccess
    {
        private readonly IConfiguration _configuration;

        public SQLDataAccess(IConfiguration configuration)
        {
            _configuration = configuration;
        }

        // find and return the connection string to the db
        // by default connect set to "ProjectSQLDB"
        public string GetConnectionString(string connect = "ProjectDB")
        {
            return _configuration.GetConnectionString(connect);
        }

        public List<T> LoadData<T>(string sql)
        {
            using (IDbConnection cnn = new SqlConnection(GetConnectionString()))
            {
                return cnn.Query<T>(sql).ToList();
            }
        }

        // data that is passed in will be saved to the db
        public int SaveData<T>(string sql, T data)
        {
            using (IDbConnection cnn = new SqlConnection(GetConnectionString()))
            {
                return cnn.Execute(sql, data);
            }
        }
    }
}
