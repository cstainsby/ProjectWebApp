using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

/*
 * use the UnitOfWork interface and object to access the database, by using "using" statements
 * This will help work with multiple repositories while only using a single database context 
 * https://dapper-tutorial.net/knowledge-base/42477624/create-a-dbcontext-that-handle-a-databasefactory-to-use-dapperextensions-more-easily <- more info about it here
 * https://github.com/timschreiber/DapperUnitOfWork/tree/master/DapperUnitOfWork <- git link to similar implementation
 */

namespace DataAccess.Repositories
{
    public interface IUnitOfWork : IDisposable
    {
        // add new repositories here
        ISimulationRepository SimulationRepo { get; }

        // Save will save the database after modifications have been made
        void Save();
    }
}
