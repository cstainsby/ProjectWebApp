using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.Extensions.Configuration;
using DataAccess.Models;
using DataAccess.Data;
using Dapper;

/*
 * This class implements all of the generic functions outlined in IRepository
 * It will treat the model it is working with as a generic T 
 */

namespace DataAccess.Repositories
{
    public class Repository<T> : IRepository<T> where T : class, new()
    {
        protected readonly IConfiguration configuration;   // configuration object to access db's with
        protected string dboContext;                       // designates which dbo to interface with

        public Repository(IConfiguration configuration, string dboContext)
        {
            this.configuration = configuration;
            this.dboContext = dboContext;
        }

        public async Task<T> GetByIdAsync(int Id)
        {
            string sql = "SELECT * FROM dbo," + dboContext + "WHERE Id = @Id";

            T entry = new T();

            return await SQLDataAccess.LoadData<T>(configuration.GetConnectionString("ProjectDB"), sql, entry);
        }

        // retrieve all items of type T within the db 
        public async Task<IEnumerable<T>> GetAllAsync()
        {
            string sql = "SELECT * FROM dbo." + dboContext;

            return await SQLDataAccess.LoadData<T>(configuration.GetConnectionString("ProjectDB"), sql);
        }

        // create a new item of type T within db given Id
        public async Task<int> AddAsync(T entity)
        {
            string sql = @"INSERT INTO dbo." + dboContext + "(Id, simName, simDesc, gitURL) VALUES (@Id, @simName, @simDesc, @gitURL);";

            return await SQLDataAccess.EditData<T>(configuration.GetConnectionString("ProjectDB"), sql, entity);
        }

        // delete an item of type T within db given Id
        public async Task<int> RemoveAsync(T entity)
        {
            string sql = "DELETE FROM dbo." + dboContext + "WHERE Id = @Id";

            return await SQLDataAccess.EditData<T>(configuration.GetConnectionString("ProjectDB"), sql, entity);
        }

        /*public async Task<T> FindAsync(Expression<Func<T, bool>> expression)
        {
            string sql = ""
        }*/
    }
}
