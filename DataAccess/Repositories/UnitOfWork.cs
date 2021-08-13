using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;

namespace DataAccess.Repositories
{
    public class UnitOfWork : IUnitOfWork
    {
        private IDbConnection _dbConnection;
        private IDbTransaction _dbTransaction;
        private ISimulationRepository _simRepo;
        private bool _disposed;


        public UnitOfWork(string cnnString)
        {
            _dbConnection = new SqlConnection( cnnString );
            _dbConnection.Open();
            _dbTransaction = _dbConnection.BeginTransaction();
            _disposed = false;
        }

        public ISimulationRepository SimulationRepo 
        {
            get{ return _simRepo ?? (_simRepo = new SimulationRepository(_dbTransaction)); }
        }

        public void Save()
        {
            try
            {
                // when changes are made try to commit the changes to the repository
                _dbTransaction.Commit();
            }
            catch
            {
                // if there are any errors in changes, delete them and revert to previous version of db
                _dbTransaction.Rollback();
                throw;
            }
            finally
            {
                // once the above two steps are finished dispose of the current repos and prepare for any next requests
                _dbTransaction.Dispose();
                _dbTransaction = _dbConnection.BeginTransaction();
                _simRepo = null;
            }
        }

        public void Dispose()
        {
            // when called to dispose call the dsiposeHelper to delete the repository
            // then request that during object cleanup later that the destructor not be called(it has already been deleted)
            DisposeHelper(true);
            GC.SuppressFinalize(this); 
        }

        ~UnitOfWork()
        {
            // destructor helper function
            DisposeHelper(false);
        }

        private void DisposeHelper(bool toBeDisposed)
        {
            // this function helps in the destruction of the current repo 
            if (!_disposed)
            {
                if (toBeDisposed)
                {
                    if(_dbTransaction != null)
                    {
                        _dbTransaction.Dispose();
                        _dbTransaction = null;
                    }
                    if(_dbConnection != null)
                    {
                        _dbConnection.Dispose();
                        _dbConnection = null;
                    }
                }
                _disposed = true;
            }
        }
    }
}
