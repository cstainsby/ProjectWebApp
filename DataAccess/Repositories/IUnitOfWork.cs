using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

/*
 * use the UnitOfWork interface and object to access the database, by using "using" statements
 */

namespace DataAccess.Repositories
{
    public interface IUnitOfWork
    {
        // add new repositories here
        ISimulationRepository Simulations { get; }

    }
}
