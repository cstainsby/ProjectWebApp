using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Data;

/*
 * This abstract repository will define how the other repos 
 * will hold the db connection and transaction
 * it will only be avalible to the repos within this folder
 */

namespace DataAccess.Repositories
{
    internal abstract class AbstractRepository
    {
        protected IDbTransaction _transaction { get; private set; }
        protected IDbConnection _connection 
        { 
            get { return _transaction.Connection; } 
        }

        public AbstractRepository(IDbTransaction dbTransaction)
        {
            _transaction = dbTransaction;
        }
    }
}
