using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

/*
 * define this interface with generic T holding exclusivley objects
 * This will be implemented by all other processors
 */

namespace DataAccess.Logic
{
    public interface IProcessor<T> where T : class
    {
        // each processor will have a config 
        //IConfiguration config { get; set; }

        // get item of type T by Id
        Task<T> GetById(int Id);

        // retrieve all items of type T within the db 
        Task<IReadOnlyList<T>> GetAllAsync();

        // create a new item of type T within db given Id
        Task<int> CreateAsync(T obj);

        // delete an item of type T within db given Id
        Task<int> DeleteAsync(int Id);

        // update an items contents within db given Id
        Task<int> UpdateAsync(T obj);
    }
}
