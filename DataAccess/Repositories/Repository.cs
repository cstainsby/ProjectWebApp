using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.Extensions.Configuration;
using DataAccess.Models;
using Dapper;
using System.Data;

/*
 * This class implements all of the generic functions outlined in IRepository
 * It will treat the model it is working with as a generic T 
 * It will inherit the abstract repository 
 */

namespace DataAccess.Repositories
{
    internal class Repository<T> : AbstractRepository, IRepository<T> where T : AbstractModel
    {
        public Repository(IDbTransaction _transaction) : base(_transaction)
        {
        }
        
        // retrieve specific item within given Id
        public async Task<T> GetByIdAsync(int Id)
        {
            string sql = $"SELECT * FROM dbo." + _type + " WHERE Id = " + Id;


            return await _connection.QuerySingleOrDefaultAsync
                (sql, 
                param: new { Id = Id }, 
                transaction: _transaction);
        }

        // delete an item of type T within db given Id
        public async Task<int> RemoveAsync(int Id)
        {
            string sql = @"DELETE FROM dbo." + _type + " WHERE Id = @Id";

            return await _connection.ExecuteAsync
                (sql,
                param: new { Id = Id },
                transaction: _transaction);
        }
    }
}
