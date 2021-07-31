using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Dapper;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

/*
 * This class handles all interactions with the database
 * It takes any model as a generic and executes the passed in "sql" command given a connection string
 */

namespace DataAccess.Data
{
    public static class SQLDataAccess
    {
        // pull all database entries of type T and return them as a list
        public static async Task<IEnumerable<T>> LoadData<T>(string cnnString, string sql)
        {
            using (IDbConnection cnn = new SqlConnection(cnnString))
            {
                return await cnn.QueryAsync<T>(sql);
            }
        }

        // overloaded LoadData to find a specific entry rather than pulling all db entries
        public static async Task<T> LoadData<T>(string cnnString, string sql, T obj)
        {
            using (IDbConnection cnn = new SqlConnection(cnnString))
            {
                return await cnn.QuerySingleOrDefaultAsync<T>(sql, obj);
            }
        }

        // data that is passed in will be saved to the db
        public static async Task<int> EditData<T>(string cnnString, string sql, T data)
        {
            using (IDbConnection cnn = new SqlConnection(cnnString))
            {
                return await cnn.ExecuteAsync(sql, data);
            }
        }
    }
}
