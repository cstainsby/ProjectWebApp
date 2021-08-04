using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Autofac.Extras.Moq;
using DataAccess.Repositories;
using DataAccess.Models;
using Microsoft.Extensions.Configuration;
using Xunit;

namespace ProjectUnitTests.Repositories
{
    public class UnitOfWorkTest
    {
        [Fact]
        public void getSimulationRepository()
        {
            // build a configuration to access connection strings
            IConfiguration configuration = new ConfigurationBuilder()
                .SetBasePath(Directory.GetCurrentDirectory())
                .AddJsonFile("appsettings.json")
                .Build();

            Console.Out.WriteLine(Directory.GetCurrentDirectory());
            // make sure the connection string is grabbed correctly
            Assert.Equal("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=ProjectDB;Integrated Security=True;Connect Timeout=60;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False"
                , configuration.GetConnectionString("ProjectDB"));

            // using the unit of work object and the connection string store the repo within the Controller
            var unitWork = new UnitOfWork(configuration.GetConnectionString("ProjectDB"));


            // test w
            //Assert.Equal("ISumulationModel", unitWork.SimulationRepo);
        }
    }
}
