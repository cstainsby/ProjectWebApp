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
    internal class Repository<T> : AbstractRepository, IRepository<T> where T : Model
    {
        public Repository(IDbTransaction _transaction) : base(_transaction)
        {
        }
        
        // retrieve specific item within given Id
        public async Task<T> GetByIdAsync(int Id)
        {
            string sql = "SELECT * FROM dbo." + _type + " WHERE Id = @Id";

            return await _connection.QuerySingleOrDefaultAsync
                (
                sql, 
                param: new { Id = Id }, 
                transaction: _transaction
                );
        }

        // retrieve all items of type T within the db 
        public async Task<IEnumerable<T>> GetAllAsync()
        {
            string sql = "SELECT * FROM dbo." + _type;

            return await _connection.QueryAsync<T>(sql);
        }

        // create a new item of type T within db given Id
        public async Task<int> AddAsync(T entity)
        {
            if(entity == null)
            {
                throw new ArgumentNullException("entity");
            }

            string sql = @"INSERT INTO dbo." + _type + " (Id, simName, simDesc, gitURL) VALUES (@Id, @simName, @simDesc, @gitURL);";

            return await _connection.ExecuteAsync
                (
                sql,
                param: new { Id = entity.Id },
                transaction: _transaction
                );
        }

        // delete an item of type T within db given Id
        public async Task<int> RemoveAsync(int Id)
        {
            string sql = "DELETE FROM dbo." + _type + " WHERE Id = @Id";

            return await _connection.ExecuteAsync
                (
                sql,
                param: new { Id = Id },
                transaction: _transaction
                );
        }

        /*public async Task<T> FindAsync(Expression<Func<T, bool>> expression)
        {
            string sql = ""
        }*/
    }
}
