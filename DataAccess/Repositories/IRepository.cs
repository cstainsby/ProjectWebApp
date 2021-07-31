using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Threading.Tasks;

namespace DataAccess.Repositories
{
    interface IRepository<T> where T : class
    {
        Task<T> GetByIdAsync(int Id);
        Task<IEnumerable<T>> GetAllAsync();
        //Task<IEnumerable<T>> FindAsync(Expression<Func<T, bool>> expression);

        Task<int> AddAsync(T entity);
        //void AddRange();
        Task<int> RemoveAsync(T entity);
    }
}
