using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Threading.Tasks;

/*
 * This interface will define funciton prototypes for all standard functions that should be in a repository
 */

namespace DataAccess.Repositories
{
    public interface IRepository<T> where T : class
    {
        Task<T> GetByIdAsync(int Id);
        
        //Task<IEnumerable<T>> FindAsync(Expression<Func<T, bool>> expression);

        //void AddRange();
        Task<int> RemoveAsync(int Id);
    }
}
